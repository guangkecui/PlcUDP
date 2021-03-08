#include "sensordata.h"
#include <fstream>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <math.h>
#include <iostream>
using namespace std;
typedef unsigned char BYTE;

Sensordata::Sensordata()
{
    Camera_Master = new Cameradata();
    Camera_Attached = new Cameradata();
    lightplane1 = nullptr;
    lightplane2 = nullptr;

}

Sensordata::~Sensordata()
{
    if(Camera_Master!=nullptr){
        delete Camera_Master;
        Camera_Master = nullptr;
    }
    if(Camera_Attached!=nullptr){
        delete Camera_Attached;
        Camera_Attached = nullptr;
    }
    if(lightplane1!= nullptr){
        delete lightplane1;
        lightplane1 = nullptr;
    }
    if(lightplane2!= nullptr){
        delete lightplane2;
        lightplane2 = nullptr;
    }
}

/**********************************************
  函数名称：ReadData
  输入参数：FileName:输出文件名，FileFormat文件格式：true：dat，false：txt
  输出参数：
  函数功能：读取dat文件或txt文件，一个文件对应一个传感器数据
**********************************************/
bool Sensordata::ReadData(QString FileName, bool FileFormat)
{
    if(FileFormat==true)//格式为dat
    {
        BYTE dd_info[10];//定义大小为10的uchar数组
        std::ifstream inF_info;//文件读入流
        inF_info.open(FileName.toStdString(),std::ios::binary|std::ios::in|std::ios::out);//打开文件
        if(inF_info)
        {
            inF_info.seekg(0,std::ios::beg);
            inF_info.read(reinterpret_cast<char*>(dd_info), sizeof(BYTE)*10);
        }
        inF_info.close();
        if(dd_info[0]=='b')//双目，没有激光条
        {
            setLight(0);
        }
        else if(dd_info[0]=='m')//单目
        {
            uint lightno=*(dd_info+2)-'0';//激光条的数目
            setLight(lightno);
        }
        else
            return false;
        return LoadSensorData(FileName);

    }
    if(FileFormat==false)
    {
        char info[10];
        int Rx1; int Ry1; double para1[14];double rToSensor1[9];double tToSensor1[3];
        int Rx2; int Ry2; double para2[14];double rToMasterCamera[9];double tToMasterCamera[3];
        double rToTrack[9];double tToTrack[3];
        double linearMatrix[3];//直线方程的四个参数：距离x轴夹角，距离y轴夹角，距离z轴夹角
        double rt[12];
        std::string sensorinfo;
        std::ifstream readin;//文件读入流
        readin.open(FileName.toStdString().c_str());//打开文件
        readin>>sensorinfo;
        if(sensorinfo[0]=='b')//双目
        {
            std::string camera1,camera2;
            readin>>camera1>>Rx1>>Ry1>>para1[0]>>para1[1]
                    >>para1[2]>>para1[3]>>para1[4]>>para1[5]
                    >>para1[6]>>para1[7]>>para1[8]>>para1[9]
                    >>para1[10]>>para1[11]>>para1[12]>>para1[13]
                    >>camera2>>Rx2>>Ry2>>para2[0]>>para2[1]
                    >>para2[2]>>para2[3]>>para2[4]>>para2[5]
                    >>para2[6]>>para2[7]>>para2[8]>>para2[9]
                    >>para2[10]>>para2[11]>>para2[12]>>para2[13]
                    >>rt[0]>>rt[1]>>rt[2]>>rt[3]>>rt[4]>>rt[5]
                    >>rt[6]>>rt[7]>>rt[8]>>rt[9]>>rt[10]>>rt[11];
            readin.close();
            /***************主相机内参-数组转Mat*********************************/
            Camera_Master->setSerialNum(QString::fromStdString(camera1));
            Mat Mtemp1(3,3,CV_64FC1);
            for(int i = 0; i < 3; ++i){
                for(int j = 0; j < 3; ++j){
                    Mtemp1.at<double>(i,j) = para1[i*3+j];
                }
            }
            Mat Disttemp1(1,5,CV_64FC1);
            for(int i=0;i<5;++i)
                Disttemp1.at<double>(0,i) = para1[i+9];
            Camera_Master->setM(Mtemp1);
            Camera_Master->setDist(Disttemp1);
            /****************************************************************/
            /***************从相机内参-数组转Mat*******************************/
            Camera_Attached->setSerialNum(QString::fromStdString(camera2));
            Mat Mtemp2(3,3,CV_64FC1);
            for(int i = 0; i < 3; ++i){
                for(int j = 0; j < 3; ++j){
                    Mtemp2.at<double>(i,j) = para2[i*3+j];
                }
            }
            Mat Disttemp2(1,5,CV_64FC1);
            for(int i=0;i<5;++i)
                Disttemp2.at<double>(0,i) = para2[i+9];
            Camera_Attached->setM(Mtemp2);
            Camera_Attached->setDist(Disttemp2);
            /************************************************************/
            /****************RT-数组转Mat*********************************/
            Mat mat_rt(3,4,CV_64FC1);
            for(int i = 0;i < 3; ++i){
                for(int j =0;j<4;++j){
                    mat_rt.at<double>(i,j) = para2[i*4+j];
                }
            }
            /************************************************************/
            return true;
        }
        else if(sensorinfo[0]=='m')//单目
        {
            strcpy(info,sensorinfo.c_str());
            uint lightno=*(info+2)-'0';//激光条数目
            setLight(lightno);
            info[0]='m';
            info[1]='_';
            std::string camera1;//主相机序列号
            std::string camera2;//从相机序列号
            readin>>camera1>>Rx1>>Ry1
                    >>para1[0]>>para1[1]>>para1[2]
                    >>para1[3]>>para1[4]>>para1[5]
                    >>para1[6]>>para1[7]>>para1[8]//主相机内参
                    >>para1[9]>>para1[10]>>para1[11]>>para1[12]>>para1[13];//主相机畸变参数
                    for(int i=0;i<lightno*4;i++)//主相机光平面参数读入
                    {
                        readin>>lightplane1[i];//激光条数据一次读入，分别为A\B\C\D\A\B\C\D\A......
                    }
                    readin>>rToSensor1[0]>>rToSensor1[1]>>rToSensor1[2]>>tToSensor1[0]
                    >>rToSensor1[3]>>rToSensor1[4]>>rToSensor1[5]>>tToSensor1[1]
                    >>rToSensor1[6]>>rToSensor1[7]>>rToSensor1[8]>>tToSensor1[2];//主相机转到传感器坐标系下的rt

            readin>>camera2>>Rx2>>Ry2
                    >>para2[0]>>para2[1]>>para2[2]
                    >>para2[3]>>para2[4]>>para2[5]
                    >>para2[6]>>para2[7]>>para2[8]//从相机内参
                    >>para2[9]>>para2[10]>>para2[11]>>para2[12]>>para2[13];//从相机畸变参数
                    for(int i=0;i<lightno*4;i++)//从相机光平面参数读入
                    {
                        readin>>lightplane2[i];//激光条数据一次读入，分别为A\B\C\D\A\B\C\D\A......
                    }
                    readin>>rToMasterCamera[0]>>rToMasterCamera[1]>>rToMasterCamera[2]>>tToMasterCamera[0]
                    >>rToMasterCamera[3]>>rToMasterCamera[4]>>rToMasterCamera[5]>>tToMasterCamera[1]
                    >>rToMasterCamera[6]>>rToMasterCamera[7]>>rToMasterCamera[8]>>tToMasterCamera[2];//从相机转到主相机坐标系下的rt

            readin>>rToTrack[0]>>rToTrack[1]>>rToTrack[2]>>tToTrack[0]
                    >>rToTrack[3]>>rToTrack[4]>>rToTrack[5]>>tToTrack[1]
                    >>rToTrack[6]>>rToTrack[7]>>rToTrack[8]>>tToTrack[2];//传感器坐标系到轨道坐标系的RT
            readin>>linearMatrix[0]>>linearMatrix[1]>>linearMatrix[2];
            readin.close();

            /***************主相机参数-数组转Mat*********************************/
            Camera_Master->setSerialNum(QString::fromStdString(camera1));
            Mat Mtemp1(3,3,CV_64FC1);
            for(int i = 0; i < 3; ++i){
                for(int j = 0; j < 3; ++j){
                    Mtemp1.at<double>(i,j) = para1[i*3+j];
                }
            }
            Mat Disttemp1(1,5,CV_64FC1);
            for(int i=0;i<5;++i){
                Disttemp1.at<double>(0,i) = para1[i+9];
            }
            Mat RtoSensorTemp1(3,3,CV_64FC1);
            for(int i = 0; i < 3; ++i){
                for(int j = 0; j < 3; ++j){
                    RtoSensorTemp1.at<double>(i,j) = rToSensor1[i*3+j];
                }
            }
            Mat TtoSensorTemp1(3,1,CV_64FC1);
            for(int i=0;i<3;++i){
                TtoSensorTemp1.at<double>(i,0) = tToSensor1[i];
            }
            Camera_Master->setM(Mtemp1);
            Camera_Master->setDist(Disttemp1);
            Camera_Master->setRToSensor(RtoSensorTemp1);
            Camera_Master->setTToSensor(TtoSensorTemp1);
            /****************************************************************/
            /***************从相机参数-数组转Mat*********************************/
            Camera_Attached->setSerialNum(QString::fromStdString(camera2));
            Mat Mtemp2(3,3,CV_64FC1);
            for(int i = 0; i < 3; ++i){
                for(int j = 0; j < 3; ++j){
                    Mtemp2.at<double>(i,j) = para2[i*3+j];

                }
            }
            Mat Disttemp2(1,5,CV_64FC1);
            for(int i=0;i<5;++i)
                Disttemp2.at<double>(0,i) = para2[i+9];
            R = Mat::zeros(3,3,CV_64FC1);
            for(int i = 0; i < 3; ++i){
                for(int j = 0; j < 3; ++j){
                    R.at<double>(i,j) = rToMasterCamera[i*3+j];
                }
            }

            T = Mat::zeros(3,1,CV_64FC1);
            for(int i=0;i<3;++i){
                T.at<double>(i,0) = tToMasterCamera[i];
            }

            Camera_Attached->setM(Mtemp2);
            Camera_Attached->setDist(Disttemp2);
//            setR(RToMasterCamera);
//            setT(TToMasterCamera);
            //Camera_Attached->setRToSensor(RtoSensorTemp2);
            //Camera_Attached->setTToSensor(TtoSensorTemp2);
            /****************************************************************/

            /*****************传感器到轨道RT******************************/
            RTtoTrackFromSensor = Mat::zeros(4,4,CV_64FC1);
            for(int i=0;i<3;++i){
                for(int j=0;j<3;++j){
                    RTtoTrackFromSensor.at<double>(i,j) = rToTrack[i*3+j];
                }
                RTtoTrackFromSensor.at<double>(i,3) = tToTrack[i];
            }
            RTtoTrackFromSensor.at<double>(3,3) = 1.0;
            /****************************************************************/
            /*****************直线方程矩阵******************************/
            LinearEquationMatrix = Mat::zeros(4,4,CV_64FC1);
            LinearEquationMatrix.at<double>(0,0) = 1.0;
            LinearEquationMatrix.at<double>(1,1) = 1.0;
            LinearEquationMatrix.at<double>(2,2) = 1.0;
            LinearEquationMatrix.at<double>(3,3) = 1.0;
            LinearEquationMatrix.at<double>(0,3) = cos(linearMatrix[0]);
            LinearEquationMatrix.at<double>(1,3) = cos(linearMatrix[1]);
            LinearEquationMatrix.at<double>(2,3) = cos(linearMatrix[2]);
            /****************************************************************/
            return true;
        }
        return false;
    }
}

/**********************************************
  函数名称：LoadSensorData
  输入参数：读入的文件路径
  输出参数：
  函数功能：将dat或txt里面的数据导入Sensordata中
**********************************************/
bool Sensordata::LoadSensorData(QString FileName)
{
    char info[10];
    char sn1[20]; int Rx1; int Ry1; double para1[14];
    char sn2[20]; int Rx2; int Ry2; double para2[14];
    double rt[12];
    BYTE dd_info[10];
    std::ifstream inF_info;
    inF_info.open(FileName.toStdString(),std::ios::binary|std::ios::in|std::ios::out);
    if(inF_info)
    {
        inF_info.seekg(0,std::ios::beg);
        inF_info.read(reinterpret_cast<char*>(dd_info), sizeof(BYTE)*10);
    }
    else
        return false;
    inF_info.close();
    if(dd_info[0]=='b')//双目
    {
        BYTE dd[800];//定义800个字节
        std::ifstream inF;
        inF.open(FileName.toStdString(),std::ios::binary|std::ios::in|std::ios::out);
        if(inF)
        {
            inF.seekg(0,std::ios::beg);
            inF.read(reinterpret_cast<char*>(dd), sizeof(BYTE)*800);
        }
        inF.close();
        if(info!=0)
        {
            for(int i=0;i<10;i++)
            {
                if(dd[i]==0)
                {
                    break;
                }
                else
                {
                    *(info+i)=dd[i];
                }

            }
        }
        //主相机序列号
        if(sn1!=0)
        {
            for(int i=0;i<20;i++)
            {
                if(dd[i+10]==0)
                {
                    break;
                }
                else
                {
                    *(sn1+i)=dd[i+10];
                }

            }
            Camera_Master->setSerialNum(QString(sn1));
        }
        //从相机序列号
        if(sn2!=0)
        {
            for(int i=0;i<20;i++)
            {
                if(dd[i+30]==0)
                {
                    break;
                }
                else
                {
                    *(sn2+i)=dd[i+30];
                }

            }
            Camera_Attached->setSerialNum(QString(sn2));
        }
        if(Rx1!=0)
        {
            for (int i=0;i<1;i++)
            {
                Rx1=*((int*)(dd+50+8*i));
            }
            Camera_Master->setHorizontal(Rx1);
        }
        if(Ry1!=0)
        {
            for (int i=0;i<1;i++)
            {
                Ry1=*((int*)(dd+60+8*i));
            }
            Camera_Master->setVertial(Ry1);
        }
        if(Rx2!=0)
        {
            for (int i=0;i<1;i++)
            {
                Rx2=*((int*)(dd+70+8*i));
            }
            Camera_Attached->setHorizontal(Rx2);
        }
        if(Ry2!=0)
        {
            for (int i=0;i<1;i++)
            {
                Ry2=*((int*)(dd+80+8*i));
            }
            Camera_Attached->setVertial(Ry2);
        }
        //主相机内参
        if(para1!=0)
        {
            for (int i=0;i<14;i++)
            {
                *(para1+i)=*((double*)(dd+128+8*i));
            }
            Mat M(3,3,CV_64FC1);
            for(int i = 0; i < 3; ++i){
                for(int j = 0; j < 3; ++j){
                    M.at<double>(i,j) = para1[i*3+j];
                }
            }
            Mat Dist(1,5,CV_64FC1);
            for(int i=0;i<5;++i)
                Dist.at<double>(0,i) = para1[i+9];

            Camera_Master->setM(M);
            Camera_Master->setDist(Dist);
        }
        //从相机内参
        if(para2!=0)
        {
            for (int i=0;i<14;i++)
            {
                *(para2+i)=*((double*)(dd+256+8*i));
            }
            Mat M(3,3,CV_64FC1);
            for(int i = 0; i < 3; ++i){
                for(int j = 0; j < 3; ++j){
                    M.at<double>(i,j) = para2[i*3+j];
                }
            }
            Mat Dist(1,5,CV_64FC1);
            for(int i=0;i<5;++i)
                Dist.at<double>(0,i) = para2[i+9];

            Camera_Attached->setDist(Dist);
            Camera_Attached->setM(M);
        }
        //主从相机间的RT关系
        if(rt!=0)
        {
            for (int i=0;i<12;i++)
            {
                *(rt+i)=*((double*)(dd+384+8*i));
            }
            Mat mat_rt(3,4,CV_64FC1);
            for(int i = 0;i < 3; ++i){
                for(int j =0;j<4;++j){
                    mat_rt.at<double>(i,j) = para2[i*4+j];
                }
            }
            //setRT(mat_rt);
        }
        return true;
    }
    //判断是否单目
    else if(dd_info[0]=='m')
    {
        uint lightno=*(dd_info+2)-'0';
        BYTE dd[800];
        std::ifstream inF;
        inF.open(FileName.toStdString(),std::ios::binary|std::ios::in|std::ios::out);
        if(inF)
        {
            inF.seekg(0,std::ios::beg);
            inF.read(reinterpret_cast<char*>(dd), sizeof(BYTE)*800);
        }
        inF.close();
        //主相机序列号
        if(sn1!=0)
        {
            for(int i=0;i<20;i++)
            {
                if(dd[i+10]==0)
                {
                    break;
                }
                else
                {
                    *(sn1+i)=dd[i+10];
                }
            }
            Camera_Master->setSerialNum(QString(sn1));
        }
        if(Rx1!=0)
        {
            for (int i=0;i<1;i++)
            {
                Rx1=*((int*)(dd+50+8*i));
            }
            Camera_Master->setHorizontal(Rx1);
        }
        if(Ry1!=0)
        {
            for (int i=0;i<1;i++)
            {
                Ry1=*((int*)(dd+60+8*i));
            }
            Camera_Master->setVertial(Ry1);
        }
        //主相机内参
        if(para1!=0)
        {
            for (int i=0;i<14;i++)
            {
                *(para1+i)=*((double*)(dd+128+8*i));
            }
            Mat M(3,3,CV_64FC1);
            for(int i = 0; i < 3; ++i){
                for(int j = 0; j < 3; ++j){
                    M.at<double>(i,j) = para1[i*3+j];
                }
            }
            Mat Dist(1,5,CV_64FC1);
            for(int i=0;i<5;++i)
                Dist.at<double>(0,i) = para1[i+9];

            Camera_Master->setM(M);
            Camera_Master->setDist(Dist);
        }
        //光条方程
        if(lightplane1!=0)
        {
            setLight(lightno);
            for (int i=0;i<4*lightno;i++)
            {
                *(lightplane1+i)=*((double*)(dd+256+8*i));
            }
        }
        return true;
    }
    return false;
}

void Sensordata::setR(const cv::Mat InputR)
{
    R = InputR.clone();
}

void Sensordata::setT(const cv::Mat InputT)
{
    T = InputT.clone();
}

void Sensordata::setLight(const int LightNums)
{
    if(lightplane1!=nullptr){
        delete lightplane1;
    }
    if(lightplane2!=nullptr){
        delete lightplane2;
    }
    lightplane1 = new double[4*LightNums];
    lightplane2 = new double[4*LightNums];
}

void Sensordata::setRToTrack(const cv::Mat InputR)
{
    RToTrackFromSensor = InputR.clone();
}

void Sensordata::setTToTrack(const cv::Mat InputT)
{
    TToTrackFromSensor = InputT.clone();
}

void Sensordata::setRTToTrack(const cv::Mat InputRT)
{
    RTtoTrackFromSensor = InputRT.clone();
}

void Sensordata::setLinearMatrix(const cv::Mat InputM)
{
    LinearEquationMatrix = InputM.clone();
}

cv::Mat Sensordata::getR() const
{
    return R;
}

cv::Mat Sensordata::getT() const
{
    return T;
}

cv::Mat Sensordata::getROfTrack() const
{
    return RToTrackFromSensor;
}

cv::Mat Sensordata::getTOfTrack() const
{
    return TToTrackFromSensor;
}

cv::Mat Sensordata::getRTOfTrack() const
{
    return RTtoTrackFromSensor;
}

cv::Mat Sensordata::getLinearMatrix() const
{
    return LinearEquationMatrix;
}

double *Sensordata::getLight1() const
{
    return lightplane1;
}

double *Sensordata::getLight2() const
{
    return lightplane2;
}

Cameradata *Sensordata::getCamera_Master() const
{
    return Camera_Master;
}

Cameradata *Sensordata::getCamera_Attached() const
{
    return Camera_Attached;
}

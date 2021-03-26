#include "imageproce.h"
#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include<QDir>
#include<QMetaType>
#include<QVector3D>
#include<iostream>

Q_DECLARE_METATYPE (QVector<double>)
using namespace std;
using namespace cv;

ImageProce::ImageProce(QString InputFilePath, sensorunit *sensors, QObject *parent):
    workingFilePath(InputFilePath),
    isSinglePointShow(false),
    m_threshold(200),
    QObject(parent)
{
    qRegisterMetaType<QVector<double>>("QVector<double>");
    if(sensors==nullptr){
        emit sendMessageToMainwindow(QString("ImageProce Init:Sensors's Ptr is nullptr."));
        return;
    }
    else{
        m_SensorUnit = sensors;
    }
}

/**********************************************
  函数名称：UndistortPoint2d
  输入参数：src:原图像点；dst：校正后的图像点；
  输出参数：
  函数功能：通过畸变参数对原图像点进行畸变矫正
**********************************************/

void ImageProce::UndistortPoint2d(vector<cv::Mat> & src, vector<cv::Mat> & dst,Mat & M,Mat &D)
{

    dst.clear();
                double fx = M.at<double>(0, 0);
                double fy = M.at<double>(1, 1);
                double ux = M.at<double>(0, 2);
                double uy = M.at<double>(1, 2);

                double k1 = D.at<double>(0, 0);
                double k2 = D.at<double>(0, 1);
                double p1 = D.at<double>(0, 2);
                double p2 = D.at<double>(0, 3);
                double k3 = D.at<double>(0, 4);
                double k4 = 0;
                double k5 = 0;
                double k6 = 0;

                for (unsigned int i = 0; i < src.size(); i++)
                {
                    const cv::Mat & p = src[i];
                    //首先进行坐标转换；
                    double xDistortion = (p.at<double>(0,0) - ux) / fx;
                    double yDistortion = (p.at<double>(1,0) - uy) / fy;

                    double xCorrected, yCorrected;

                    double x0 = xDistortion;
                    double y0 = yDistortion;

                    //这里使用迭代的方式进行求解，因为根据2中的公式直接求解是困难的，所以通过设定初值进行迭代，这也是OpenCV的求解策略；
                    for (int j = 0; j < 200; j++)
                    {
                        double r2 = xDistortion * xDistortion + yDistortion * yDistortion;

                        double distRadialA = 1 / (1. + k1 * r2 + k2 * r2 * r2 + k3 * r2 * r2 * r2);
                        double distRadialB = 1. + k4 * r2 + k5 * r2 * r2 + k6 * r2 * r2 * r2;

                        double deltaX = 2. * p1 * xDistortion * yDistortion + p2 * (r2 + 2. * xDistortion * xDistortion);
                        double deltaY = p1 * (r2 + 2. * yDistortion * yDistortion) + 2. * p2 * xDistortion * yDistortion;

                        xCorrected = (x0 - deltaX)* distRadialA * distRadialB;
                        yCorrected = (y0 - deltaY)* distRadialA * distRadialB;

                        xDistortion = xCorrected;
                        yDistortion = yCorrected;
                    }

                    //进行坐标变换；
                    xCorrected = xCorrected * fx + ux;
                    yCorrected = yCorrected * fy + uy;
                    Mat res = Mat(3,1,CV_64F,Scalar::all(0));
                    res.at<double>(0,0) = xCorrected;
                    res.at<double>(1,0) = yCorrected;
                    res.at<double>(2,0) = 1;
                    dst.push_back(res);
                }
}

void ImageProce::setSensorUnit(sensorunit *_sensors)
{
    m_SensorUnit = _sensors;
}

/**
 * Perform one thinning iteration.
 * Normally you wouldn't call this function directly from your code.
 *
 * Parameters:
 * 		im    Binary image with range = [0,1]
 * 		iter  0=even, 1=odd
 */
void ImageProce::thinningIteration(Mat &img, int iter)
{

    CV_Assert(img.channels() == 1);
    CV_Assert(img.depth() != sizeof(uchar));
    CV_Assert(img.rows > 3 && img.cols > 3);

    cv::Mat marker = cv::Mat::zeros(img.size(), CV_8UC1);

    int nRows = img.rows;
    int nCols = img.cols;

    if (img.isContinuous()) {
        nCols *= nRows;
        nRows = 1;
    }

    int x, y;
    uchar *pAbove;
    uchar *pCurr;
    uchar *pBelow;
    uchar *nw, *no, *ne;    // north (pAbove)
    uchar *we, *me, *ea;
    uchar *sw, *so, *se;    // south (pBelow)

    uchar *pDst;

    // initialize row pointers
    pAbove = NULL;
    pCurr  = img.ptr<uchar>(0);
    pBelow = img.ptr<uchar>(1);

    for (y = 1; y < img.rows-1; ++y) {
        // shift the rows up by one
        pAbove = pCurr;
        pCurr  = pBelow;
        pBelow = img.ptr<uchar>(y+1);

        pDst = marker.ptr<uchar>(y);

        // initialize col pointers
        no = &(pAbove[0]);
        ne = &(pAbove[1]);
        me = &(pCurr[0]);
        ea = &(pCurr[1]);
        so = &(pBelow[0]);
        se = &(pBelow[1]);

        for (x = 1; x < img.cols-1; ++x) {
            // shift col pointers left by one (scan left to right)
            nw = no;
            no = ne;
            ne = &(pAbove[x+1]);
            we = me;
            me = ea;
            ea = &(pCurr[x+1]);
            sw = so;
            so = se;
            se = &(pBelow[x+1]);

            int A  = (*no == 0 && *ne == 1) + (*ne == 0 && *ea == 1) +
                     (*ea == 0 && *se == 1) + (*se == 0 && *so == 1) +
                     (*so == 0 && *sw == 1) + (*sw == 0 && *we == 1) +
                     (*we == 0 && *nw == 1) + (*nw == 0 && *no == 1);
            int B  = *no + *ne + *ea + *se + *so + *sw + *we + *nw;
            int m1 = iter == 0 ? (*no * *ea * *so) : (*no * *ea * *we);
            int m2 = iter == 0 ? (*ea * *so * *we) : (*no * *so * *we);

            if (A == 1 && (B >= 2 && B <= 6) && m1 == 0 && m2 == 0)
                pDst[x] = 1;
        }
    }

    img &= ~marker;
}

/**
 * Function for thinning the given binary image
 *
 * Parameters:
 * 		src  The source image, binary with range = [0,255]
 * 		dst  The destination image
 */
void ImageProce::thinning(const Mat &src, Mat &dst)
{

    dst = src.clone();
    dst /= 255;         // convert to binary image

    cv::Mat prev = cv::Mat::zeros(dst.size(), CV_8UC1);
    cv::Mat diff;

    do {
        thinningIteration(dst, 0);
        thinningIteration(dst, 1);
        cv::absdiff(dst, prev, diff);
        dst.copyTo(prev);
    }
    while (cv::countNonZero(diff) > 0);

    dst *= 255;
}

/**********************************************
  函数名称：isHasThreelight
  输入参数：原图像
  输出参数：单激光条图像
  函数功能：判断激光条中是否有三根激光条，若有，返回三个单激光条图像
**********************************************/
std::vector<Mat> ImageProce::isHasThreelight(Mat &InputImg)
{
    return vector<Mat>();
}

/**********************************************
  函数名称：findLightbarCenter
  输入参数：src:光条原图像；ImaeCenter：光条中心的点集合[x,y,1];
    TYPE:1,thinning-zhangsuen算法(光条顺滑，但是光条提取不完全，较短，并且处理时间较长)
        2，steger算法(光条噪点较多，但是光条提取完全，较长，处理时间短)
        3，steger+thinning算法(光条噪点处于中等，光条提取完全，较长，处理时间最长)
  输出参数：
  函数功能：寻找光条中心点
**********************************************/
void ImageProce::findLightbarCenter(Mat &InputImg, vector<Mat> &ImaeCenter,int TYPE)
{
    Mat img0 = InputImg;//此为原图，有背景
    Mat img;//此为处理图
    img0.copyTo(img);//拷贝矩阵
//    namedWindow("img",0);
//    imshow("img",img);
    //threshold(img, img, 200, 255, THRESH_TOZERO);
//    blur(img,img,Size(3,3));//均值滤波
//                         //高斯滤波
//    img.convertTo(img, CV_32FC1);
//    GaussianBlur(img, img, Size(0, 0), 7, 7);

    //*thinning-zhangsuen算法*/
    if(TYPE == 1 ){
        Mat GrayCenter;
        img.convertTo(img,CV_8UC1);
        threshold(img,GrayCenter,50,255,THRESH_BINARY);
        thinning(GrayCenter,GrayCenter);
        //imshow("GrayCenter",GrayCenter);
        for (int row = 0; row < GrayCenter.rows; ++row) {
            uchar* rowptr = GrayCenter.ptr<uchar>(row);
            int col = 0;
            while (col<GrayCenter.cols) {
                if(rowptr[col]!=0){
                    Mat points(3, 1, CV_64FC1, Scalar::all(1.0));
                    points.at<double>(0,0) = col;
                    points.at<double>(1,0) = row;
                    ImaeCenter.push_back(points);
                }
                col++;
            }
        }
        return;
    }

    else {
        //一阶偏导数
        Mat m1, m2;
        m1 = (Mat_<float>(1, 2) << 1, -1);  //x偏导
        m2 = (Mat_<float>(2, 1) << 1, -1);  //y偏导

        Mat dx, dy;
        filter2D(img, dx, CV_32FC1, m1);
        filter2D(img, dy, CV_32FC1, m2);

        //二阶偏导数
        Mat m3, m4, m5;
        m3 = (Mat_<float>(1, 3) << 1, -2, 1);   //二阶x偏导
        m4 = (Mat_<float>(3, 1) << 1, -2, 1);   //二阶y偏导
        m5 = (Mat_<float>(2, 2) << 1, -1, -1, 1);   //二阶xy偏导

        Mat dxx, dyy, dxy;
        filter2D(img, dxx, CV_32FC1, m3);
        filter2D(img, dyy, CV_32FC1, m4);
        filter2D(img, dxy, CV_32FC1, m5);

        //hessian矩阵
        double maxD = -1;
        int imgcol = img.cols;
        int imgrow = img.rows;
        vector<double> Pt;
        for (int i = 0; i<imgcol; i++)
        {
            for (int j = 0; j<imgrow; j++)
            {
                if (img0.at<uchar>(j, i)>50)
                {
                    Mat hessian(2, 2, CV_32FC1);
                    hessian.at<float>(0, 0) = dxx.at<float>(j, i);
                    hessian.at<float>(0, 1) = dxy.at<float>(j, i);
                    hessian.at<float>(1, 0) = dxy.at<float>(j, i);
                    hessian.at<float>(1, 1) = dyy.at<float>(j, i);
                    Mat eValue;
                    Mat eVectors;
                    eigen(hessian, eValue, eVectors);
                    double nx, ny;
                    double fmaxD = 0;
                    if (fabs(eValue.at<float>(0, 0)) >= fabs(eValue.at<float>(1, 0)))  //求特征值最大时对应的特征向量
                    {
                        nx = eVectors.at<float>(0, 0);
                        ny = eVectors.at<float>(0, 1);
                        fmaxD = eValue.at<float>(0, 0);
                    }
                    else
                    {
                        nx = eVectors.at<float>(1, 0);
                        ny = eVectors.at<float>(1, 1);
                        fmaxD = eValue.at<float>(1, 0);
                    }
                    double t = -(nx*dx.at<float>(j, i) + ny*dy.at<float>(j, i)) / (nx*nx*dxx.at<float>(j, i) + 2 * nx*ny*dxy.at<float>(j, i) + ny*ny*dyy.at<float>(j, i));

                    if (fabs(t*nx) <= 0.5 && fabs(t*ny) <= 0.5)
                    {
                        Pt.push_back(i);
                        Pt.push_back(j);
                    }
                }
            }
        }
        Mat GrayCenter = Mat::zeros(InputImg.rows,InputImg.cols,CV_8UC1);
        for (int k = 0; k<Pt.size() / 2; k++)
        {
            GrayCenter.at<uchar>((int)Pt[2 * k + 1],(int)Pt[2 * k + 0]) = 255;
        }
        Mat element = getStructuringElement(MORPH_RECT, Size(3, 3));//自定义开闭运算的核
        morphologyEx(GrayCenter, GrayCenter, MORPH_CLOSE, element);
        if(TYPE == 3){
            thinning(GrayCenter,GrayCenter);
        }
        //************求灰度重心*****************************/
        for (int row = 0; row < GrayCenter.rows; ++row) {
            uchar* rowptr = GrayCenter.ptr<uchar>(row);
            int col = 0;
            while (col < GrayCenter.cols) {
                int u = 0;//u = 像素点坐标i*像素点i的灰度值
                int v = 0;//v = 像素点i的灰度值
                while (rowptr[col] != 0) {
                    u += col*rowptr[col];
                    v += rowptr[col];
                    col++;
                }
                if (v != 0) {
                    Mat points(3, 1, CV_64FC1, Scalar::all(1.0));
                    points.at<double>(0,0) = u / v;
                    points.at<double>(1,0) = row;
                    ImaeCenter.push_back(points);
                    u = 0;
                    v = 0;
                }
                col++;
            }
        }
    }
}

/**********************************************
  函数名称：findLightbarCenter
  输入参数：src:光条原图像；ImaeCenter1：1,2号光条中心的点集合[x,y,1];
    TYPE:1,thinning-zhangsuen算法(光条顺滑，但是光条提取不完全，较短，并且处理时间较长)
        2，steger算法(光条噪点较多，但是光条提取完全，较长，处理时间短)
        3，steger+thinning算法(光条噪点处于中等，光条提取完全，较长，处理时间最长)
  输出参数：
  函数功能：寻找光条中心点
**********************************************/
void ImageProce::findLightbarCenterManylight(Mat &InputImg,
                                              std::vector<vector<Mat>> &ImaeCenter, int TYPE)
{

}

/**********************************************
  函数名称：setPictureFilePath
  输入参数：
  输出参数：
  函数功能：选择图片的保存路径
**********************************************/
void ImageProce::setPictureFilePath(QString InputFilePath)
{
    workingFilePath = InputFilePath;
    findPictures(workingFilePath);
}

/**********************************************
  函数名称：findPictures
  输入参数：_filePath:文件夹路径
  输出参数：
  函数功能：寻找文件夹下所有的图片列表
**********************************************/
void ImageProce::findPictures(const QString &_filePath)
{
    QDir dir(_filePath);
    if(!dir.exists())
        return;
    //获取多有的文件，去掉.和..文件夹
    dir.setFilter(QDir::Files|QDir::NoDotAndDotDot);
    //按名字和时间排名
    dir.setSorting(QDir::Name|QDir::Time);
    //转化为list
    fileList = dir.entryInfoList();
    emit sendMessageToMainwindow(QString("File list's size:%1").arg(fileList.size()));
}

/**********************************************
  函数名称：processSingleMonocular
  输入参数：InputSrc:输入图片;distance:距离信息
            isSinglePoint:是否单点显示，即将激光条中y值最大的点提取出来，其他点舍弃
            sonsorNum:传感器标号，用于单点显示点的筛选，1，3号传感器根据z绝对值最大值的点来筛选，
                                                      2，4号传感器根据y绝对值最大值的点来筛选.
  输出参数：
  函数功能：单目莫模式下处理单张图片
**********************************************/
void ImageProce::processSingleMonocular(Mat &InputSrc,double _distance,bool isSinglePoint,int sonsorNum)
{
    Mat ImageUndist;//存储矫正后的图像
    undistort(InputSrc,ImageUndist,workingCameraMatrix,workingDistCoeffs);
    vector<Mat> ImageCenters;//图像的中心点坐标
    vector<Mat> ImageCenters_undist;//矫正畸变后的图像的中心点坐标
    findLightbarCenter(ImageUndist,ImageCenters_undist);//寻找中心点坐标

    //UndistortPoint2d(ImageCenters,ImageCenters_undist,
                     //workingCameraMatrix,workingDistCoeffs);//畸变矫正
    Mat _MatrixInv(3,3,CV_64FC1);
    //workingCameraMatrix.convertTo(workingCameraMatrix,CV_32FC1);
    invert( workingCameraMatrix,_MatrixInv);//内参求逆矩阵
    //workingCameraMatrix.convertTo(workingCameraMatrix,CV_64FC1);
    //_MatrixInv.convertTo(_MatrixInv,CV_64FC1);
    Mat PointInCamera(3,1,CV_64FC1);//初始化相机坐标系下点的坐标
    Mat PointInSensor(4,1,CV_64FC1);//初始化传感器坐标系下点的坐标
    Mat PointInTrack(4,1,CV_64FC1);//初始化轨道坐标系下点的坐标

    QVector<double> xVec;QVector<double> yVec;QVector<double> zVec;
    QVector3D maxYpoint;//y值绝对值最大的点
    maxYpoint.setY(0);
    QVector3D maxZpoint;//z值绝对值最大的点
    maxZpoint.setZ(0);
    for(int i=0;i<ImageCenters_undist.size();++i){
        Mat A_inv = _MatrixInv*ImageCenters_undist[i];
        double a = A_inv.at<double>(0,0);
        double b = A_inv.at<double>(1,0);

        PointInCamera.at<double>(2,0) = (-LightPlane[3])/(LightPlane[0]*a+LightPlane[1]*b+LightPlane[2]);
        PointInCamera.at<double>(0,0) = a*PointInCamera.at<double>(2,0);
        PointInCamera.at<double>(1,0) = b*PointInCamera.at<double>(2,0);
        Mat PointInSensorBuffer = workingRtoSensor * PointInCamera +workingTtoSensor;
//        PointInSensorBuffer.at<double>(0,0)+=workingTtoSensor.at<double>(0,0);
//        PointInSensorBuffer.at<double>(1,0)+=workingTtoSensor.at<double>(1,0);
//        PointInSensorBuffer.at<double>(2,0)+=workingTtoSensor.at<double>(2,0);
        PointInSensor.at<double>(0,0) = PointInSensorBuffer.at<double>(0,0);
        PointInSensor.at<double>(1,0) = PointInSensorBuffer.at<double>(1,0);
        PointInSensor.at<double>(2,0) = PointInSensorBuffer.at<double>(2,0);
        PointInSensor.at<double>(3,0) = 1;
        //_distance = 0;
        Mat workingLinearMatrixBuff = workingLinearMatrix.clone();
        workingLinearMatrixBuff.at<double>(0,3) = _distance*workingLinearMatrix.at<double>(0,3);
        workingLinearMatrixBuff.at<double>(1,3) = _distance*workingLinearMatrix.at<double>(1,3);
        workingLinearMatrixBuff.at<double>(2,3) = _distance*workingLinearMatrix.at<double>(2,3);
        Mat PointInTrackbuff  = workingRTtoTrack * PointInSensor ;
        PointInTrack = workingLinearMatrixBuff*PointInTrackbuff;
        xVec.push_back(PointInTrack.at<double>(0,0));
        yVec.push_back(PointInTrack.at<double>(1,0));
        zVec.push_back(PointInTrack.at<double>(2,0));

    }

    if(isSinglePoint){
        switch (sonsorNum) {
        case 11:
        case 12:
        case 31:
        case 32:{
            for(int i=0;i<zVec.size();++i){
                double srcPointz = zVec[i];
                if(srcPointz<0){
                    srcPointz = -srcPointz;
                }
                if(srcPointz>maxZpoint.z()){
                    maxZpoint.setX(xVec[i]);
                    maxZpoint.setY(yVec[i]);
                    maxZpoint.setZ(zVec[i]);
                }
            }
            xVec.clear();yVec.clear();zVec.clear();
            xVec.push_back(0);
            yVec.push_back(maxZpoint.y());
            zVec.push_back(maxZpoint.z());
            break;}
        case 21:
        case 22:
        case 41:
        case 42:{
            for(int i=0;i<yVec.size();++i){
                double srcPointy = yVec[i];
                if(srcPointy<0){
                    srcPointy = -srcPointy;
                }
                if(srcPointy>maxYpoint.y()){
                    maxYpoint.setX(xVec[i]);
                    maxYpoint.setY(yVec[i]);
                    maxYpoint.setZ(zVec[i]);
                }
            }
            xVec.clear();yVec.clear();zVec.clear();
            xVec.push_back(0);
            yVec.push_back(maxYpoint.y());
            zVec.push_back(maxYpoint.z());
            break;}
           }
        //相机分割显示
        switch (sonsorNum) {
        case 11:
            break;
        case 12:
            break;
        case 21:
            if(!yVec.empty()){
                if(yVec[0]<=1700){
                    xVec.clear();yVec.clear();zVec.clear();
                }
            }
            break;
        case 22:
            if(!yVec.empty()){
                if(yVec[0]>1700){
                    xVec.clear();yVec.clear();zVec.clear();
                }
            }
            break;
        case 31:
            break;
        case 32:
            xVec.clear();yVec.clear();zVec.clear();
            break;
        case 41:
            if(!yVec.empty()){
                if(yVec[0]>=-1700){
                    xVec.clear();yVec.clear();zVec.clear();
                }
            }
            break;
        case 42:
            if(!yVec.empty()){
                if(yVec[0]<-1700){
                    xVec.clear();yVec.clear();zVec.clear();
                }
            }
            break;
        default:
            break;
        }
      }

    emit sendPointToMainwindow(xVec,yVec,zVec);
}

/**********************************************
  函数名称：processMultipleMonocular
  输入参数：
  输出参数：
  函数功能：非实时状态下处理多张图片
**********************************************/
void ImageProce::processMultipleMonocular()
{
    if(fileList.empty())
        return;
    for(int i=0;i<fileList.size();++i){
        QString imageName = fileList[i].fileName();
        int sensorNum;
        double distance = setMatrixFromImagename(imageName,sensorNum);
        Mat image = imread(fileList[i].filePath().toStdString(),IMREAD_GRAYSCALE);
        processSingleMonocular(image,distance,isSinglePointShow,sensorNum);
    }
}

/**********************************************
  函数名称：setMatrixFromImagename
  输入参数：imageName：图片名称,sensorNum传感器标号
  输出参数：传感器距离原点的距离
  函数功能：根据图片名称设置相机内参/畸变参数/相机到传感器RT/传感器到轨道RT
**********************************************/
double_t ImageProce::setMatrixFromImagename(QString &imageFile,int& sensorNum)
{
    QString imageName = imageFile.mid(imageFile.lastIndexOf("/")+1,imageFile.lastIndexOf("."));
        switch (imageName[0].toLatin1()-'0') {
        case 1:

            workingRTtoTrack = m_SensorUnit->Sensor_1->getRTOfTrack().clone();
            workingLinearMatrix = m_SensorUnit->Sensor_1->getLinearMatrix().clone();
            if((imageName[2].toLatin1()-'0')==1){
                sensorNum = 11;
                workingCameraMatrix = m_SensorUnit->Sensor_1->getCamera_Master()->getM().clone();
                workingDistCoeffs = m_SensorUnit->Sensor_1->getCamera_Master()->getDist().clone();
                LightPlane = m_SensorUnit->Sensor_1->getLight1();
                workingRtoSensor = m_SensorUnit->Sensor_1->getCamera_Master()->getROfSensor().clone();
                workingTtoSensor = m_SensorUnit->Sensor_1->getCamera_Master()->getTOfSensor().clone();
            }
            else{
                sensorNum = 12;
                workingCameraMatrix = m_SensorUnit->Sensor_1->getCamera_Attached()->getM().clone();
                workingDistCoeffs = m_SensorUnit->Sensor_1->getCamera_Attached()->getDist().clone();
                LightPlane = m_SensorUnit->Sensor_1->getLight2();
                //r2(r1*x+t1)+t2  = r2r1x+r2t1+t2
                Mat R2 = m_SensorUnit->Sensor_1->getCamera_Master()->getROfSensor().clone();
                Mat T2 = m_SensorUnit->Sensor_1->getCamera_Master()->getTOfSensor().clone();
                Mat R1 = m_SensorUnit->Sensor_1->getR().clone();
                Mat T1 = m_SensorUnit->Sensor_1->getT().clone();
                workingRtoSensor = R2*R1;
                workingTtoSensor = R2*T1 + T2;
            }
            break;
        case 2:
            workingRTtoTrack = m_SensorUnit->Sensor_2->getRTOfTrack().clone();
            workingLinearMatrix = m_SensorUnit->Sensor_2->getLinearMatrix().clone();
            if((imageName[2].toLatin1()-'0')==1){
                sensorNum = 21;
                workingCameraMatrix = m_SensorUnit->Sensor_2->getCamera_Master()->getM().clone();
                workingDistCoeffs = m_SensorUnit->Sensor_2->getCamera_Master()->getDist().clone();
                LightPlane = m_SensorUnit->Sensor_2->getLight1();
                workingRtoSensor = m_SensorUnit->Sensor_2->getCamera_Master()->getROfSensor().clone();
                workingTtoSensor = m_SensorUnit->Sensor_2->getCamera_Master()->getTOfSensor().clone();
            }
            else{
                sensorNum = 22;
                workingCameraMatrix = m_SensorUnit->Sensor_2->getCamera_Attached()->getM().clone();
                workingDistCoeffs = m_SensorUnit->Sensor_2->getCamera_Attached()->getDist().clone();
                LightPlane = m_SensorUnit->Sensor_2->getLight2();
                Mat R2 = m_SensorUnit->Sensor_2->getCamera_Master()->getROfSensor().clone();
                Mat T2 = m_SensorUnit->Sensor_2->getCamera_Master()->getTOfSensor().clone();
                Mat R1 = m_SensorUnit->Sensor_2->getR().clone();
                Mat T1 = m_SensorUnit->Sensor_2->getT().clone();
                workingRtoSensor = R2*R1;
                workingTtoSensor = R2*T1 + T2;
            }
            break;
        case 3:

            workingRTtoTrack = m_SensorUnit->Sensor_3->getRTOfTrack().clone();
            workingLinearMatrix = m_SensorUnit->Sensor_3->getLinearMatrix().clone();
            if((imageName[2].toLatin1()-'0')==1){
                sensorNum = 31;
                workingCameraMatrix = m_SensorUnit->Sensor_3->getCamera_Master()->getM().clone();
                workingDistCoeffs = m_SensorUnit->Sensor_3->getCamera_Master()->getDist().clone();
                LightPlane = m_SensorUnit->Sensor_3->getLight1();
                workingRtoSensor = m_SensorUnit->Sensor_3->getCamera_Master()->getROfSensor().clone();
                workingTtoSensor = m_SensorUnit->Sensor_3->getCamera_Master()->getTOfSensor().clone();
            }
            else{
                sensorNum = 32;
                workingCameraMatrix = m_SensorUnit->Sensor_3->getCamera_Attached()->getM().clone();
                workingDistCoeffs = m_SensorUnit->Sensor_3->getCamera_Attached()->getDist().clone();
                LightPlane = m_SensorUnit->Sensor_3->getLight2();
                Mat R2 = m_SensorUnit->Sensor_3->getCamera_Master()->getROfSensor().clone();
                Mat T2 = m_SensorUnit->Sensor_3->getCamera_Master()->getTOfSensor().clone();
                Mat R1 = m_SensorUnit->Sensor_3->getR().clone();
                Mat T1 = m_SensorUnit->Sensor_3->getT().clone();
                workingRtoSensor = R2*R1;
                workingTtoSensor = R2*T1 + T2;
            }
            break;
        case 4:

            workingRTtoTrack = m_SensorUnit->Sensor_4->getRTOfTrack().clone();
            workingLinearMatrix = m_SensorUnit->Sensor_4->getLinearMatrix().clone();
            if((imageName[2].toLatin1()-'0')==1){
                sensorNum = 41;
                workingCameraMatrix = m_SensorUnit->Sensor_4->getCamera_Master()->getM().clone();
                workingDistCoeffs = m_SensorUnit->Sensor_4->getCamera_Master()->getDist().clone();
                LightPlane = m_SensorUnit->Sensor_4->getLight1();
                workingRtoSensor = m_SensorUnit->Sensor_4->getCamera_Master()->getROfSensor().clone();
                workingTtoSensor = m_SensorUnit->Sensor_4->getCamera_Master()->getTOfSensor().clone();
            }
            else{
                sensorNum = 42;
                workingCameraMatrix = m_SensorUnit->Sensor_4->getCamera_Attached()->getM().clone();
                workingDistCoeffs = m_SensorUnit->Sensor_4->getCamera_Attached()->getDist().clone();
                LightPlane = m_SensorUnit->Sensor_4->getLight2();
                Mat R2 = m_SensorUnit->Sensor_4->getCamera_Master()->getROfSensor().clone();
                Mat T2 = m_SensorUnit->Sensor_4->getCamera_Master()->getTOfSensor().clone();
                Mat R1 = m_SensorUnit->Sensor_4->getR().clone();
                Mat T1 = m_SensorUnit->Sensor_4->getT().clone();
                workingRtoSensor = R2*R1;
                workingTtoSensor = R2*T1 + T2;
            }
            break;
        default:
            break;
        }
        int32_t start = imageName.lastIndexOf("_")+1;
        int32_t end = imageName.lastIndexOf(".");
        QString distance_str = imageName.mid(start,end-start);
        return distance_str.toDouble();
}

void ImageProce::receiveIsSinglePointShowFromMaindow(bool isSingleShow)
{
     isSinglePointShow=isSingleShow;
}


void ImageProce::TestSlot()
{
//    xVec2.push_back(PointInZhu.at<double>(0,0));
//    yVec2.push_back(PointInZhu.at<double>(1,0));
//    zVec2.push_back(PointInZhu.at<double>(2,0));
//    emit sendPointToMainwindow(xVec2,yVec2,zVec2);
}

/**********************************************
  函数名称：receiveFilepathFromManagerToImageProcess
  输入参数：图片名称
  输出参数：
  函数功能：拍摄线程发给图像处理线程已经拍摄好的图片路径，根据图片路径
            进行读取，处理，画点
**********************************************/
void ImageProce::receiveFilepathFromManagerToImageProcess(QString ImagePath_LightOFF, QString ImagePath_LightON)
{
    //两张图片-处理过程
    int sensorNum;//几号传感器
    double distance = setMatrixFromImagename(ImagePath_LightON,sensorNum);//根据图片名读取相机内外参
    Mat image_light_on  = imread(ImagePath_LightON.toStdString(),0);  //读有激光条图片
    Mat image_light_off = imread(ImagePath_LightOFF.toStdString(),0); //读无激光条图片

    Mat  image_absdiff; //相减图像
    absdiff( image_light_on, image_light_off, image_absdiff);//两个图像相减

    //Mat image_gray ;//转换为灰度图
    //cvtColor(image_absdiff, image_gray, CV_BGR2GRAY);

    Mat  image_Threshold; //二值化图像
    threshold(image_absdiff, image_Threshold, m_threshold, 255, THRESH_TOZERO);//200是根据采取到的图片，进行了二值化，得到相对比较好的阈值

    Mat  image_Filter; //滤波图像
    GaussianBlur(image_Threshold,image_Filter,Size(5,5),0,0);//高斯滤波

  imwrite("C:/Users/Administrator/Desktop/0/dahua_camera1_filterimage.bmp", image_Filter);

    processSingleMonocular(image_Filter,distance,isSinglePointShow,sensorNum);

}

void ImageProce::receiveThresholdFromMaindow(int val)
{
    m_threshold = val;
}

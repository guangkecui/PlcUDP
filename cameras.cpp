#include "cameras.h"
#include <QDebug>
#include <string>
#include <iostream>
#include <QDateTime>
#include <QDir>

omron::Cameras::Cameras()
{
    Dahua::GenICam::CSystem &systemObj = Dahua::GenICam::CSystem::getInstance();
    if (false == systemObj.discovery(m_vCameraPtrList))
        return;
    Camera1_1 = nullptr;
    Camera1_2 = nullptr;
    Camera2_1 = nullptr;
    Camera2_2 = nullptr;
    Camera3_1 = nullptr;
    Camera3_2 = nullptr;
    Camera4_1 = nullptr;
    Camera4_2 = nullptr;
    PictureNums.resize(4);
    clearCount();
}

omron::Cameras::~Cameras()
{
    CamerasClose();
    if(Camera1_1!=nullptr){
        delete Camera1_1;
        Camera1_1 = nullptr;
    }
    if(Camera1_2!=nullptr){
        delete Camera1_2;
        Camera1_2 = nullptr;
    }
    if(Camera2_1!=nullptr){
        delete Camera2_1;
        Camera2_1 = nullptr;
    }
    if(Camera2_2!=nullptr){
        delete Camera2_2;
        Camera2_2 = nullptr;
    }
    if(Camera3_1!=nullptr){
        delete Camera3_1;
        Camera3_1 = nullptr;
    }
    if(Camera3_2!=nullptr){
        delete Camera3_2;
        Camera3_2 = nullptr;
    }
    if(Camera4_1!=nullptr){
        delete Camera4_1;
        Camera4_1 = nullptr;
    }
    if(Camera4_2!=nullptr){
        delete Camera4_2;
        Camera4_2 = nullptr;
    }

}

Dahua::Infra::TVector<ICameraPtr> omron::Cameras::getCameraPtrList()
{
    return m_vCameraPtrList;
}

void omron::Cameras::findCameras()
{
    workingCameras = m_vCameraPtrList.size();
    if (workingCameras < 1)
    {
        emit message("ERROR :\nThe number of cameras is less than one!");
        return;
    }
    else{
        for(int i=0;i<workingCameras;++i){
            const char* charSerialNumber = m_vCameraPtrList[i]->getSerialNumber();
            QString SerialNumber(charSerialNumber);
            switch (SerialNumber.toInt())
            {
            case CAMERA1_1NAME:{
                Camera1_1 = new oneCamera(m_vCameraPtrList[i]);
                emit message("Camera1-1 has been searched");
                QVector<QString> CfgInf = Camera1_1->loadCameraCfg(CameraConfiguration1_1);
                for(QString inf:CfgInf){
                    emit message(inf);
                }
                break;}
            case CAMERA1_2NAME:{
                Camera1_2 = new oneCamera(m_vCameraPtrList[i]);
                emit message("Camera1-2 has been searched");
                QVector<QString> CfgInf = Camera1_2->loadCameraCfg(CameraConfiguration1_2);
                for(QString inf:CfgInf){
                    emit message(inf);
                }
                break;}
            case CAMERA2_1NAME:{
                Camera2_1 = new oneCamera(m_vCameraPtrList[i]);
                emit message("Camera2-1 has been searched");
                QVector<QString> CfgInf = Camera2_1->loadCameraCfg(CameraConfiguration2_1);
                for(QString inf:CfgInf){
                    emit message(inf);
                }
                break;}
            case CAMERA2_2NAME:{
                Camera2_2 = new oneCamera(m_vCameraPtrList[i]);
                emit message("Camera2-2 has been searched");
                QVector<QString> CfgInf = Camera2_2->loadCameraCfg(CameraConfiguration2_2);
                for(QString inf:CfgInf){
                    emit message(inf);
                }
                break;}
            case CAMERA3_1NAME:{
                Camera3_1 = new oneCamera(m_vCameraPtrList[i]);
                emit message("Camera3-1 has been searched");
                QVector<QString> CfgInf = Camera3_1->loadCameraCfg(CameraConfiguration3_1);
                for(QString inf:CfgInf){
                    emit message(inf);
                }
                break;}
            case CAMERA3_2NAME:{
                Camera3_2 = new oneCamera(m_vCameraPtrList[i]);
                emit message("Camera3-2 has been searched");
                QVector<QString> CfgInf = Camera3_2->loadCameraCfg(CameraConfiguration3_2);
                for(QString inf:CfgInf){
                    emit message(inf);
                }
                break;}
            case CAMERA4_1NAME:{
                Camera4_1 = new oneCamera(m_vCameraPtrList[i]);
                emit message("Camera4-1 has been searched");
                QVector<QString> CfgInf = Camera4_1->loadCameraCfg(CameraConfiguration4_1);
                for(QString inf:CfgInf){
                    emit message(inf);
                }
                break;}
            case CAMERA4_2NAME:{
                Camera4_2 = new oneCamera(m_vCameraPtrList[i]);
                emit message("Camera4-2 has been searched");
                QVector<QString> CfgInf = Camera4_2->loadCameraCfg(CameraConfiguration4_2);
                for(QString inf:CfgInf){
                    emit message(inf);
                }
                break;}
            default:
                break;
            }
        }
    }
    CamerasOpen();//????????????

    SavePath = DEFAULTIMAGEPATH;
}

void omron::Cameras::CamerasOpen()
{
    if(Camera1_1!=nullptr){
        if(!Camera1_1->CameraOpen()){
            emit message("Cameras????????????Camera1_1????????????");
        }
        else{
            Camera1_1->creatStreamSource();
            emit message("Cameras????????????Camera1_1????????????");
         }
    }
    if(Camera1_2!=nullptr){
        if(!Camera1_2->CameraOpen()){
            emit message("Cameras????????????Camera1_2????????????");
        }
        else{
            Camera1_2->creatStreamSource();
            emit message("Cameras????????????Camera1_2????????????");
         }
    }
    if(Camera2_1!=nullptr){
        if(!Camera2_1->CameraOpen()){
            emit message("Cameras????????????Camera2_1????????????");
        }
        else{
            Camera2_1->creatStreamSource();
            emit message("Cameras????????????Camera2_1????????????");
        }
    }
    if(Camera2_2!=nullptr){
        if(!Camera2_2->CameraOpen()){
            emit message("Cameras????????????Camera2_2????????????");
        }
        else{
            Camera2_2->creatStreamSource();
            emit message("Cameras????????????Camera2_2????????????");
        }
    }
    if(Camera3_1!=nullptr){
        if(!Camera3_1->CameraOpen()){
            emit message("Cameras????????????Camera3_1????????????");
        }
        else{
            Camera3_1->creatStreamSource();
            emit message("Cameras????????????Camera3_1????????????");
        }
    }
    if(Camera3_2!=nullptr){
        if(!Camera3_2->CameraOpen()){
            emit message("Cameras????????????Camera3_2????????????");
        }
        else{
            Camera3_2->creatStreamSource();
            emit message("Cameras????????????Camera3_2????????????");
        }
    }
    if(Camera4_1!=nullptr){
        if(!Camera4_1->CameraOpen()){
            emit message("Cameras????????????Camera4_1????????????");
        }
        else{
            Camera4_1->creatStreamSource();
            emit message("Cameras????????????Camera4_1????????????");
        }
    }
    if(Camera4_2!=nullptr){
        if(!Camera4_2->CameraOpen()){
            emit message("Cameras????????????Camera4_2????????????");
        }
        else{
            Camera4_2->creatStreamSource();
           emit message("Cameras????????????Camera4_2????????????");
        }
    }
}

void omron::Cameras::CamerasClose()
{
    if(Camera1_1!=nullptr){
        if(!Camera1_1->CameraClose()){
            emit message("CamerasClose???Camera1_1????????????");
        }
        else
            emit message("CamerasClose???Camera1_1????????????");
    }
    if(Camera1_2!=nullptr){
        if(!Camera1_2->CameraClose()){
            emit message("CamerasClose???Camera1_2????????????");
        }
        else
            emit message("CamerasClose???Camera1_2????????????");
    }
    if(Camera2_1!=nullptr){
        if(!Camera2_1->CameraClose()){
            emit message("CamerasClose???Camera2_1????????????");
        }
        else
            emit message("CamerasClose???Camera2_1????????????");
    }
    if(Camera2_2!=nullptr){
        if(!Camera2_2->CameraClose()){
            emit message("CamerasClose???Camera2_2????????????");
        }
        else
            emit message("CamerasClose???Camera2_2????????????");
    }
    if(Camera3_1!=nullptr){
        if(!Camera3_1->CameraClose()){
            emit message("CamerasClose???Camera3_1????????????");
        }
        else
            emit message("CamerasClose???Camera3_1????????????");
    }
    if(Camera3_2!=nullptr){
        if(!Camera3_2->CameraClose()){
            emit message("CamerasClose???Camera3_2????????????");
        }
        else
            emit message("CamerasClose???Camera3_2????????????");
    }
    if(Camera4_1!=nullptr){
        if(!Camera4_1->CameraClose()){
            emit message("CamerasClose???Camera4_1????????????");
        }
        else
            emit message("CamerasClose???Camera4_1????????????");
    }
    if(Camera4_2!=nullptr){
        if(!Camera4_2->CameraClose()){
            emit message("Cameras????????????Camera4_2????????????");
        }
        else
            emit message("Cameras????????????Camera4_2????????????");
    }
}

/**********************************************
  ???????????????CalculatePictureName
  ???????????????????????????
  ??????????????????????????????????????????
  ??????????????????????????????_????????????_???n?????????_?????????????????????.bmp
**********************************************/
QString omron::Cameras::CalculatePictureName(omron::CAMERALABEL cameralabel)
{
    QString num = "";
    QString name = "";
    switch (cameralabel) {
    case CAMERALABEL::Camera1_1:
        num = QString("%1").arg(PictureNums[0]);
        name = SavePath_Copy+"/1_1_"+num+"_"+camerasDis.Dis1+".bmp";
        PictureNums[0]++;
        break;
    case CAMERALABEL::Camera1_2:
        num = QString("%1").arg(PictureNums[0]);
        name = SavePath_Copy+"/1_2_"+num+"_"+camerasDis.Dis1+".bmp";
        PictureNums[0]++;
        break;
    case CAMERALABEL::Camera2_1:
         num = QString("%1").arg(PictureNums[1]);
         name = SavePath_Copy+"/2_1_"+num+"_"+camerasDis.Dis2+".bmp";
         PictureNums[1]++;
        break;
    case CAMERALABEL::Camera2_2:
         num = QString("%1").arg(PictureNums[1]);
         name = SavePath_Copy+"/2_2_"+num+"_"+camerasDis.Dis2+".bmp";
         PictureNums[1]++;
        break;
    case CAMERALABEL::Camera3_1:
         num = QString("%1").arg(PictureNums[2]);
         name = SavePath_Copy+"/3_1_"+num+"_"+camerasDis.Dis3+".bmp";
         PictureNums[2]++;
        break;
    case CAMERALABEL::Camera3_2:
         num = QString("%1").arg(PictureNums[2]);
         name = SavePath_Copy+"/3_2_"+num+"_"+camerasDis.Dis3+".bmp";
         PictureNums[2]++;
        break;
    case CAMERALABEL::Camera4_1:
         num = QString("%1").arg(PictureNums[3]);
         name = SavePath_Copy+"/4_1_"+num+"_"+camerasDis.Dis4+".bmp";
         PictureNums[3]++;
        break;
    case CAMERALABEL::Camera4_2:
         num = QString("%1").arg(PictureNums[3]);
         name = SavePath_Copy+"/4_2_"+num+"_"+camerasDis.Dis4+".bmp";
         PictureNums[3]++;
        break;
    default:
        break;
    }
    return name;
}

/**********************************************
  ???????????????getImageOfCamera
  ???????????????cameralabel:?????????;isLightON:?????????????????????true?????????????????????false??????????????????
  ??????????????????????????????????????????????????????????????????????????????????????????????????????
  ????????????????????????????????????????????????????????????????????????????????????
**********************************************/
QString omron::Cameras::getImageOfCamera(omron::CAMERALABEL cameralabel, bool isLightON)
{
    switch (cameralabel) {
    case CAMERALABEL::Camera1_1:
        if(Camera1_1!=nullptr){
            if(isLightON){
                if(Camera1_2!=nullptr)
                    Camera1_2->openDigitalIO();//???????????????
                QString Imagename = CalculatePictureName(CAMERALABEL::Camera1_1);
                bool res = Camera1_1->getImage(Imagename);//????????????
                if(Camera1_2!=nullptr)
                    Camera1_2->closeDigitalIO();//???????????????
                if(res)
                    return Imagename;
                else
                    return "";
            }
            else{
                QString Imagename = CalculatePictureName(CAMERALABEL::Camera1_1);
                if(Camera1_2!=nullptr)
                    Camera1_2->closeDigitalIO();//???????????????
                bool res = Camera1_1->getImage(Imagename);//????????????
                if(res)
                    return Imagename;
                else
                    return "";
            }
        }
        break;
    case CAMERALABEL::Camera1_2:
        if(Camera1_2!=nullptr){
            if(isLightON){
                Camera1_2->openDigitalIO();
                QString Imagename = CalculatePictureName(CAMERALABEL::Camera1_2);
                bool res = Camera1_2->getImage(Imagename);
                Camera1_2->closeDigitalIO();
                if(res)
                    return Imagename;
                else
                    return "";
            }
            else{
                Camera1_2->closeDigitalIO();
                QString Imagename = CalculatePictureName(CAMERALABEL::Camera1_2);
                bool res = Camera1_2->getImage(Imagename);
                if(res)
                    return Imagename;
                else
                    return "";
            }
        }
        break;
    case CAMERALABEL::Camera2_1:
        if(Camera2_1!=nullptr){
            if(isLightON){
                if(Camera2_2!=nullptr)
                    Camera2_2->openDigitalIO();//???????????????
                QString Imagename = CalculatePictureName(CAMERALABEL::Camera2_1);
                bool res = Camera2_1->getImage(Imagename);//????????????
                if(Camera2_2!=nullptr)
                    Camera2_2->closeDigitalIO();//???????????????
                if(res)
                    return Imagename;
                else
                    return "";
            }
            else{
                QString Imagename = CalculatePictureName(CAMERALABEL::Camera2_1);
                if(Camera2_2!=nullptr)
                    Camera2_2->closeDigitalIO();//???????????????

                bool res = Camera2_1->getImage(Imagename);//????????????
                if(res)
                    return Imagename;
                else
                    return "";
            }
        }
        break;
    case CAMERALABEL::Camera2_2:
        if(Camera2_2!=nullptr){
            if(isLightON){
                Camera2_2->openDigitalIO();
                QString Imagename = CalculatePictureName(CAMERALABEL::Camera2_2);
                bool res = Camera2_2->getImage(Imagename);
                Camera2_2->closeDigitalIO();
                if(res)
                    return Imagename;
                else
                    return "";
            }
            else{
                Camera2_2->closeDigitalIO();
                QString Imagename = CalculatePictureName(CAMERALABEL::Camera2_2);
                bool res = Camera2_2->getImage(Imagename);
                if(res)
                    return Imagename;
                else
                    return "";
            }
        }
        break;
    case CAMERALABEL::Camera3_1:
        if(Camera3_1!=nullptr){
            if(isLightON){
                if(Camera3_2!=nullptr)
                    Camera3_2->openDigitalIO();//???????????????
                QString Imagename = CalculatePictureName(CAMERALABEL::Camera3_1);
                bool res = Camera3_1->getImage(Imagename);//????????????
                if(Camera3_2!=nullptr)
                    Camera3_2->closeDigitalIO();//???????????????
                if(res)
                    return Imagename;
                else
                    return "";
            }
            else{
                QString Imagename = CalculatePictureName(CAMERALABEL::Camera3_1);
                if(Camera3_2!=nullptr)
                    Camera3_2->closeDigitalIO();//???????????????
                bool res = Camera3_1->getImage(Imagename);//????????????
                if(res)
                    return Imagename;
                else
                    return "";
            }
        }
        break;
    case CAMERALABEL::Camera3_2:
        if(Camera3_2!=nullptr){
            if(isLightON){
                Camera3_2->openDigitalIO();
                QString Imagename = CalculatePictureName(CAMERALABEL::Camera3_2);
                bool res = Camera3_2->getImage(Imagename);
                Camera3_2->closeDigitalIO();
                if(res)
                    return Imagename;
                else
                    return "";
            }
            else{
                Camera3_2->closeDigitalIO();
                QString Imagename = CalculatePictureName(CAMERALABEL::Camera3_2);
                bool res = Camera3_2->getImage(Imagename);
                if(res)
                    return Imagename;
                else
                    return "";
            }
        }
        break;
    case CAMERALABEL::Camera4_1:
        if(Camera4_1!=nullptr){
            if(isLightON){
                if(Camera4_2!=nullptr)
                    Camera4_2->openDigitalIO();//???????????????
                QString Imagename = CalculatePictureName(CAMERALABEL::Camera4_1);
                bool res = Camera4_1->getImage(Imagename);//????????????
                if(Camera4_2!=nullptr)
                    Camera4_2->closeDigitalIO();//???????????????
                if(res)
                    return Imagename;
                else
                    return "";
            }
            else{
                QString Imagename = CalculatePictureName(CAMERALABEL::Camera4_1);
                if(Camera4_2!=nullptr)
                    Camera4_2->closeDigitalIO();//???????????????
                bool res = Camera4_1->getImage(Imagename);//????????????
                if(res)
                    return Imagename;
                else
                    return "";
            }
        }
        break;
    case CAMERALABEL::Camera4_2:
        if(Camera4_2!=nullptr){
            if(isLightON){
                Camera4_2->openDigitalIO();
                QString Imagename = CalculatePictureName(CAMERALABEL::Camera4_2);
                bool res = Camera4_2->getImage(Imagename);
                Camera4_2->closeDigitalIO();
                if(res)
                    return Imagename;
                else
                    return "";
            }
            else{
                Camera4_2->closeDigitalIO();
                QString Imagename = CalculatePictureName(CAMERALABEL::Camera4_2);
                bool res = Camera4_2->getImage(Imagename);
                if(res)
                    return Imagename;
                else
                    return "";
            }
        }
        break;
    default:
        break;
    }
    return "";
}

void omron::Cameras::newTimeFolder()
{
    //????????????????????????????????????????????????????????????????????????????????????????????????
    QDateTime current_data_time = QDateTime::currentDateTime();
    QString current_time =  current_data_time.toString("yyyy_MMdd_hh_mm_ss");
    SavePath_Copy = SavePath+"/"+current_time;
    QDir dir;
    if(!dir.exists(SavePath_Copy))
        dir.mkpath(SavePath_Copy);
    clearCount();//??????????????????
}

void omron::Cameras::clearCount()
{
    for(int i =0;i<4;++i)
        PictureNums[i] = 0;
}



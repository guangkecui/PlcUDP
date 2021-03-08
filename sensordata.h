#ifndef SENSORDATA_H
#define SENSORDATA_H
#include"cameradata.h"
#include<QDebug>
#include <QObject>
/*
 * 传感器数据类
 * Camera_Master:主相机数据
 * Camera_Attached：从相机数据
 * lightplane：相机平面参数，4个double为1组
 * */
class Sensordata
{
public:
    Sensordata();
    ~Sensordata();
    bool ReadData(QString FileName,bool FileFormat);
    bool LoadSensorData(QString FileName);
    void setR(const cv::Mat InputR);
    void setT(const cv::Mat InputT);
    void setLight(const int LightNums);
    void setRToTrack(const Mat InputR);
    void setTToTrack(const Mat InputT);
    void setRTToTrack(const Mat InputRT);
    void setLinearMatrix(const Mat InputM);
    Mat getR()const;
    Mat getT()const;
    Mat getROfTrack()const;//获得从传感器坐标系到轨道坐标系的R
    Mat getTOfTrack()const;//获得从传感器坐标系到轨道坐标系的R
    Mat getRTOfTrack()const;//获得从传感器坐标系到轨道坐标系的RT
    Mat getLinearMatrix()const;
    double* getLight1()const;
    double* getLight2()const;
    Cameradata* getCamera_Master()const;
    Cameradata* getCamera_Attached()const;
private:
    Cameradata* Camera_Master;
    Cameradata* Camera_Attached;
    Mat RToTrackFromSensor;//从传感器坐标系到轨道坐标系的R
    Mat TToTrackFromSensor;//从传感器坐标系到轨道坐标系的T
    Mat RTtoTrackFromSensor;//从传感器坐标系到轨道坐标系的RT
    Mat LinearEquationMatrix;//传感器的直线方程矩阵
    double* lightplane1;//主相机光平面参数
    double* lightplane2;//从相机光平面参数
    Mat R;//从相机到主相机的R
    Mat T;//从相机到主相机的T

};

#endif // SENSORDATA_H

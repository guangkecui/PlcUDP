#ifndef CAMERADATA_H
#define CAMERADATA_H
#include<QString>
#include<opencv2/core/core.hpp>

using cv::Mat;
/*
 * 保存单相机数据
 * SerialNum:相机序列号
 * M：内参3*3
 * Dist：畸变参数1*5
 * isHorizontal:是否水平镜像
 * isVertial:是否垂直镜像
 */
class Cameradata
{
public:
    Cameradata();
    ~Cameradata();
    void setSerialNum(QString InputSerNum);
    void setM(const Mat InputM);
    void setDist(const Mat InputDist);
    void setRToSensor(const Mat InputR);
    void setTToSensor(const Mat InputT);

    void setHorizontal(bool InputHorizontal);
    void setVertial(bool InputVertial);
    Mat getM()const;
    Mat getDist()const;
    Mat getROfSensor()const;//获得相机坐标系到传感器坐标系的R
    Mat getTOfSensor()const;//获得相机坐标系到传感器坐标系的T

    QString getSerialNum()const;
    bool isHorizontal()const;
    bool isVertial()const;
private:
    cv::Mat M;//内参矩阵
    cv::Mat Dist;//畸变参数矩阵
    QString SerialNum;//相机序列号
    Mat RToSensorFromCamera;//从相机坐标系到传感器坐标系的R
    Mat TToSensorFromCamera;//从相机坐标系到传感器坐标系的T

    bool Horizontal;//是否垂直方向镜像
    bool Vertial;//是否水平方向镜像
};

#endif // CAMERADATA_H

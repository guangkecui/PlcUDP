#ifndef IMAGEPROCE_H
#define IMAGEPROCE_H

#include <QObject>
#include <opencv2/opencv.hpp>
#include <vector>
#include "sensorunit.h"
#include <QFileInfoList>
using cv::Point3d;
using cv::Point2d;
using cv::Mat;
class ImageProce : public QObject
{
    Q_OBJECT
public:
    explicit ImageProce(QString InputFilePath = "",sensorunit* sensors = nullptr,QObject *parent = 0);
    //*图片畸变矫正*/
    void UndistortPoint2d(std::vector<cv::Mat> &src, std::vector<cv::Mat> &dst, cv::Mat &M, cv::Mat &D);
    //*传入传感器数据*/
    void setSensorUnit(sensorunit *_sensors);
    //*zhangsuen法光条细化 1次迭代*/
    void thinningIteration(cv::Mat& img, int iter);
    //*zhangsuen法光条细化*/
    void thinning(const cv::Mat& src, cv::Mat& dst);
    //*检测是否含有三根激光条，如果含有三根激光条，将三根激光条变成三幅图像*/
    std::vector<cv::Mat> isHasThreelight(cv::Mat &InputImg);
    //*寻找光条中心（单激光条）*/
    void findLightbarCenter(cv::Mat &InputImg, std::vector<cv::Mat> &ImaeCenter, int TYPE = 2);
    //*寻找光条中心（多激光条）*/
    void findLightbarCenterManylight(cv::Mat &InputImg,
                                      std::vector<std::vector<cv::Mat> > &ImaeCenter,
                                      int TYPE = 1);
    //*非实时处理-设置图片路径并寻找文件夹下所有的图片*/
    void setPictureFilePath(QString InputFilePath);
    //*非实时处理-寻找文件夹下所有的图片*/
    void findPictures(const QString& _filePath);
    //*单目模式下计算坐标*/
    void processSingleMonocular(Mat& InputSrc, double _distance, bool isSinglePoint, int sensorNum);
    //*双目模式下计算坐标*/
    void processMultipleMonocular();
    //*根据图片名称设置相机内参，即根据图片名称判断是哪个相机拍的*/
    double_t setMatrixFromImagename(QString& imageFile, int &sensorNum);
    //*单点显示程序*/
    void singlePointShow(QVector<double>& xVec, QVector<double>& yVec, QVector<double>& zVec, int sensor);
signals:
    void sendPointToMainwindow(QVector<double> x,QVector<double>y,QVector<double>z );
    void sendMessageToMainwindow(QString msg);
public slots:
    void receiveThresholdFromMaindow(int threshold_val);
    void receiveIsSinglePointShowFromMaindow(bool isSingleShow);
    void TestSlot();
    //*接收从manager（指令管理器）发来的图片路径，根据图片路径对图片进行处理*/
    void receiveFilepathFromManagerToImageProcess(QString ImagePath_LightOFF,QString ImagePath_LightON);
private:
    sensorunit* m_SensorUnit;//四个传感器的信息
    Mat workingCameraMatrix;//相机内参
    Mat workingDistCoeffs;//相机畸变参数
    Mat workingRtoSensor;//相机坐标系转到传感器坐标系的RT
    Mat workingTtoSensor;
    Mat workingRTtoTrack;//传感器坐标系转到轨道坐标系RT
    Mat workingLinearMatrix;//直线方程矩阵
    double* LightPlane;//光平面参数
    QString workingFilePath;//图片的路径
    QFileInfoList fileList;//图片集合
    bool isSinglePointShow;//是否单点显示，整个激光条中取y值最大的点
    int m_threshold;
};

#endif // IMAGEPROCE_H

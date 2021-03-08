#ifndef CAMERAS_H
#define CAMERAS_H

#include"onecamera.h"
#include"omronpst.h"
#include<QVector>
#include <QObject>
namespace omron {

/*
 * 相机在杆上的位置
 * 记录在图片名字上便于后续图像处理
  */
typedef struct
{
    QString Dis1;
    QString Dis2;
    QString Dis3;
    QString Dis4;
}Distance;
/*
 * 相机操作类，包含8个相机
 * 对相机进行拍照、拉流、触发等操作
 * */ 
class Cameras :public QObject
{
    Q_OBJECT
public:
    Cameras();
    ~Cameras();
    int workingCameras;
    Dahua::Infra::TVector<Dahua::GenICam::ICameraPtr> getCameraPtrList();
    void findCameras();
    void CamerasOpen();
    void CamerasClose();
    QString CalculatePictureName(CAMERALABEL cameralabel);
    QString getImageOfCamera(CAMERALABEL cameralabel,bool isLightON);
    void newTimeFolder();
    void clearCount();
    Distance camerasDis;//相机对应的位置，加在图片名字上
    QVector<quint32> PictureNums;
    QString SavePath;
    QString SavePath_Copy;//文件路径副本
private:
    oneCamera* Camera1_1;							// 1-1相机
    oneCamera* Camera1_2;							// 1-2相机
    oneCamera* Camera2_1;							// 2-1相机
    oneCamera* Camera2_2;							// 2-2相机
    oneCamera* Camera3_1;							// 3-1相机
    oneCamera* Camera3_2;							// 3-2相机
    oneCamera* Camera4_1;							// 4-1相机
    oneCamera* Camera4_2;							// 4-2相机
    Dahua::Infra::TVector<Dahua::GenICam::ICameraPtr> m_vCameraPtrList;	// 发现的相机列表 | List of cameras found
signals:
    void message(QString msg);
private slots:
};
}
#endif // CAMERAS_H

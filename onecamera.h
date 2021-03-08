#ifndef ONECAMERA_H
#define ONECAMERA_H

#include "GenICam/System.h"
#include <QString>
#include <QImage>

using namespace Dahua::GenICam;
using namespace Dahua::Infra;
namespace omron {
/*
 * 单相机操作类
 * 可对单个相机进行拍照、拉流、触发等操作
 * */
class oneCamera
{
public:
    QString Name;           // 相机名称
    oneCamera();
    oneCamera(ICameraPtr inputCamera);
    // 枚举触发方式
    // Enumeration trigger mode
    enum ETrigType
    {
        trigContinous = 0,	// 连续拉流 | continue grabbing
        trigSoftware = 1,	// 软件触发 | software trigger
        trigLine = 2,		// 外部触发	| external trigger
    };
    // 打开相机
    // open cmaera
    bool CameraOpen(void);
    // 关闭相机
    // close camera
    bool CameraClose(void);
    //创建流对象
    bool creatStreamSource(void);
    // 设置采集方式为软件触发
    bool CameraSetSoftTrig(void);
    // 执行一次软触发
    // Execute a soft trigger
    bool ExecuteSoftTrig(void);
    // 取流回调函数
    // get frame callback function
    void FrameCallback(const Dahua::GenICam::CFrame & frame);
    //获取图像
    bool getImage(QString SavePath, bool horizontal =true, bool vertical=false);
    //打开数字IO
    void openDigitalIO(void);
    //关闭数字IO
    void closeDigitalIO(void);
    //读取配置信息
    QVector<QString> loadCameraCfg(QString xmlFilename);

private:
    ICameraPtr m_pCamera;							// 相机指针
    IStreamSourcePtr m_pStreamSource;               // 流指针
    QImage  imageBuff;                              // 图像缓存
};
}

#endif // ONECAMERA_H

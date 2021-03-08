#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QUdpSocket>
#include <QThread>
#include <QTimer>
#include "fins.h"
#include "mode.h"
#include "cameras.h"
#include "setcamerasprtwidget.h"
#include <QMutex>
#include "omronpst.h"
#include "parametersetting.h"
#include "manager.h"
#include "manualmodedialog.h"
#include "sensorunit.h"
#include "readsensorsdialog.h"
#include <QtDataVisualization/QtDataVisualization>
#include <Q3DScatter>
#include "imageproce.h"
#include <opencv2/opencv.hpp>
#include "findpicfile.h"

using namespace cv;
using namespace QtDataVisualization;
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    /**********************************************
      函数功能：主窗口显示字符串str
    **********************************************/
    void DisplayText(const QString& str);
    void DisplayText(const QByteArray& bytes);

    /**********************************************
      函数功能：自定义的控件排布
    **********************************************/
    void unitUi(void);

    /**********************************************
      函数功能：开始监听udp信息
    **********************************************/
    void StartListen(void);

    /**********************************************
      函数功能：停止监听udp信息
    **********************************************/
    void EndListen(void);

    /**********************************************
      函数功能：设置电机参数
    **********************************************/
    void setMotorsPtr(void);

    /**********************************************
      函数功能：设置图片的保存路径，路径一般从子窗口读取
    **********************************************/
    void setPicturePath(void);

    /**********************************************
      函数功能：在主窗口绘制x,y,z坐标点
    **********************************************/
    void ScatterAddonePoint(double x,double y,double z);

    /**********************************************
      函数功能：清空widget上的点
    **********************************************/
    void ScatterClearPoints();

    /**********************************************
      函数功能：获得相机当前的位置
    **********************************************/
    QByteArray getCameraPosition(int cameraLable);

    bool getCameraPosition(QString cameraLable);

    //****************读取限界文件****************//
    void readLimitInf(QString LimitInfFile);
    //****************判断限界****************//
    bool isInLimits(int Inputx, int Inputy, int Inputz);
signals:
    void ImageProcessStart();
    void ManagerStart();
    void ManualStart();
    void ManualEnd(QByteArray step,QByteArray continuous);
    void AutoEnd();
    void ManagerMotorPowerOn(int motor);
    void ManagerMotorPowerOff(int motor);
    void startGetImage(int camera);
    void cmdToOrigin(int motor);
    void cmdToSafeLocation(int motor);
    void setMotorFlagZero(int motor);
    void sendMotorToPosition(int motor,double position);
    void sendCmdToManger(QString memory,bool flag);
    void sendIsSinglePointShow(bool isSingleShow);
private slots:
    //消息处理函数,接收数据的响应函数
    void dealMsg();
    //参数更新槽函数
    void UpdateParameters();
    //接收从Manager发来的信息
    void receiveMessage(QString msg);
    //接收从manualDialog发来的消息
    void receiveMessageFromManualDiaglog(QString msg);
    //接收从cmerasPLC发来的信息
    void receiveMessageFromCameras(QString msg);
    //接收从manualDialog发来的指令
    void receiveCommandFromManualDiaglog(QByteArray cmd, double dis,double vec, int _workingMode,int motor);
    //接收从图像处理线程中的坐标
    void receivePointFromImageProcess(QVector<double> x,QVector<double> y,QVector<double> z);
    //接收从图像处理线程中的消息
    void receiveMessageFromImageProcess(QString msg);
    //接收从图片选择路径的窗口  的 路径
    void receivePathdFromPicfileDiaglog(QString path);
    //手动控制界面关闭槽函数
    void manualDialogDistroyed();
    //自动控制关闭槽函数
    void autoModeDistroyed();
    //开始监听
    void on_StartListen_clicked();
    //停止监听
    void on_EndListen_clicked();
    //手动模式选项选中
    void on_manualMode_clicked();
    //自动模式选项选中
    void on_autoMode_clicked();
    //文字显示清零
    void on_textClear_clicked();
    //从手动控制界面接受需要拍照的相机标号，将标号发给指令控制器执行
    void CamerasGetImage(uchar cam);
    //设置界面
    void on_actionSetting_triggered();
    //相机设置界面
    void on_actionCameraSetting_triggered();
    //开始按键按下
    void on_ModeStart_clicked();
    //传感器数据界面
    void on_actionCameraParm_triggered();
    //打开图片文件夹
    void on_openPictureFile_clicked();
    //开始处理按键按下
    void on_startProcess_clicked();
    //停止按键按下
    void on_ModeStop_clicked();
    //1号电机回原点
    void on_BacktoOrigin_1_clicked();
    //2号电机回原点
    void on_BacktoOrigin_2_clicked();
    //3号电机回原点
    void on_BacktoOrigin_3_clicked();
    //4号电机回原点
    void on_BacktoOrigin_4_clicked();
    //全部电机回原点
    void on_BacktoOrigin_all_clicked();

    void getCmdMotorToPosition(int motor,double position);

    void on_BacktoSafe_1_clicked();

    void on_BacktoSafe_2_clicked();

    void on_BacktoSafe_3_clicked();

    void on_BacktoSafe_4_clicked();

    void on_BacktoSafe_all_clicked();

    void on_clearScatter_clicked();

    void on_motorsPowerOn_clicked();

    void on_motorsPowerOff_clicked();

    void on_actionSavePointCloud_triggered();

    void on_actionReadPointCloud_triggered();

    void on_readLimit_currentIndexChanged(int index);

    void on_FrontView_clicked();

    void on_isSinglePointShow_stateChanged(int arg1);

private:
    Ui::MainWindow *ui;//主界面
    omron::MotorUnit* motorsPLC;//电机管理
    omron::Fins* finsPLC;//fins指令
    omron::Mode* modePLC;//模式管理器
    omron::Cameras* camerasPLC;//相机管理器
    SetCamerasPrtWidget* CamerasPrtWidget;//相机参数界面
    ParameterSetting* ParSet;//参数设置窗口
    QThread managerThread;//指令管理器的线程
    Manager* m_manager;//指令管理器
    manualmodeDialog* manualDialog;//手动控制器界面
    FindPicFile* picFileDialog;//选择图片保存路径
    sensorunit* m_SensorUnit;//四个传感器的信息
    ReadSensorsDialog* ReadSensors;//传感器读入文件界面
    Q3DScatter *scatter;//三维点显示器
    QScatter3DSeries* series;//三维点代理
    QScatter3DSeries* unLimitseries;//不在限界内的三维点代理
    QScatter3DSeries* Limitseries;//限界的三维点代理
    LimitInf m_limit;//限界信息
    QThread ImageProcessThread;//图像处理线程
    ImageProce* ImageProcessWorker;//图像处理工作对象

};

#endif // MAINWINDOW_H

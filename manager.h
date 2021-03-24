#ifndef MANAGER_H
#define MANAGER_H

#include <QObject>
#include <QMutex>
#include<QTimer>
#include<QThread>
#include"fins.h"
#include"cameras.h"

using namespace omron;
class Manager: public QObject
{
    Q_OBJECT
private:
    bool isworking;
    QByteArray Command;
    Fins* m_fins;
    Cameras* m_cameras;
    QTimer* m_pTimer;            //定时器
    QMutex _mutex;              //互斥锁
    int workingMode;            //当前正在工作的模式
    double manualWorkDist;      //手动控制模式的距离/mm
    int workingMotor;           //手动模式下正在工作的电机
    double velocity;            //手动模式下电机的速度
    int cmdWaitTimes;
public:
    Manager(Fins* fins,Cameras* cams);
    bool isPolling;             //是否正在轮询
    QByteArray PollingMessage;  //需要轮询的消息
    QVector<QString> MotorPolled_Start;//自动模式下需要轮询的开始标志位
    QVector<QString> MotorPolled_Inplace;//自动模式下需要轮询的到位标志位
    QVector<QString> MotorPolled_End;//自动模式下需要轮询的结束标志位
    QVector<int> MotorPolled_IsWorking;//自动模式下记录正在工作的电机
    QVector<int> MotorPolled_EndWorking;//自动模式下记录已经结束工作的电机
    bool isWorking();
    void setWorking();
    void setMode(int mode);
    void setMotor(int motor);
    void setVelocity(double vec);
    void ManualWorkStepping();
    void ManualWorkContinuous();
    void setManualWorkDist(double dis = 1.0);
    void AutoWork();
    void concelWorking();
    void addCommand(QByteArray cmd);
    bool MemoryClear(QByteArray mem);
    bool isSuccessfulResponse();
    void setCmdWaitTimes(int time = 0);
    QByteArray getCommand();
    double_t getMotorPosition(QByteArray Position);
signals:
    void message(QString msg);
    void singleImageProcess(QString ImageName_LightOFF,QString ImageName_LightON);//相机已拍下图片，传给图像处理线程处理
    void AutoModeEnd();
private slots:
    void getPosition(int camera);
    void getCameraImage(int camera);
    void powerOnMotors(int motor);
    void powerOffMotors(int motor);
    void manualEnd(QByteArray step,QByteArray continuous);
    void autoEnd();
    void start();
    void timerPollDeal();
    //void udpReceiveDeal();
    void backToOrigin(int motor);
    void backToSafeLocation(int motor);
    bool isOrigin(int motor);
    void setOriginZero(int motor);
    void sendVelocity(int motor, double inputVec);
    void setZeroMotorFlags(int motor);//将motor号电机相关的标志位清零
    void setMotorToPosition(int motor,double position);//设置电机到达指定位置
    void receiveCmdFromOrders(QString memory, bool flag);
};

#endif // MANAGER_H

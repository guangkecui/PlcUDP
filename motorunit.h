#ifndef MOTORUNIT_H
#define MOTORUNIT_H
#include "motor.h"
#include "omronpst.h"
namespace omron {
    //电机组，包含4个电机
    class MotorUnit
    {
    private:

        QByteArray* autoFlag;//automatic control label
        QByteArray* camsFlag;//相机标志位,plc告诉PC哪个相机该拍照
        QByteArray* manualContinuousFlag;//手动连续模式
        QByteArray* manualStepFlag;//手动步进模式
    public:
        Motor* motor1;
        Motor* motor2;
        Motor* motor3;
        Motor* motor4;
        MotorUnit();
        ~MotorUnit();
        bool setMotor1(QByteArray motorlabel);//set motor's label
        bool setMotor2(QByteArray motorlabel);
        bool setMotor3(QByteArray motorlabel);
        bool setMotor4(QByteArray motorlabel);
        bool setAutoFlag(QByteArray input_autoflag);
        bool setCamsFlag(QByteArray input_camsflag);
        bool setManualContinuousFlag(QByteArray inputFlag);
        bool setManualStepFlag(QByteArray inputFlag);

        QByteArray getMotor1();//get label of motor
        QByteArray getMotor2();
        QByteArray getMotor3();
        QByteArray getMotor4();
        QByteArray getAutoFlag();
        QByteArray getCamsFlag();
        QByteArray getManualContinuousFlag();
        QByteArray getManualStepFlag();



        QByteArray StartAuto();//start automatic mode;

        QByteArray MotorMoveUp(int motor);
        QByteArray MotorMoveUpZero(int motor);
        QByteArray MotorMoveUpStop(int motor);
        QByteArray MotorMoveUpStopZero(int motor);
        QByteArray MotorMoveDown(int motor);
        QByteArray MotorMoveDownZero(int motor);
        QByteArray MotorMoveDownStop(int motor);
        QByteArray MotorMoveDownStopZero(int motor);
    };
}


#endif // MOTORUNIT_H


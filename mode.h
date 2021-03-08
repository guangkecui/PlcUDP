#ifndef MODE_H
#define MODE_H
#include"abstractmode.h"
#include"motorunit.h"

namespace omron {


    class Mode
    {
    private:
        AbstractMode* _workingMode;
    public:
        Mode(ModeType MType = ModeType::Automatic,MotorUnit& plcMotors=MotorUnit());
        QByteArray StartWorking();//返回自动控制模式指令

        QByteArray Motor1MoveUp();
        QByteArray Motor2MoveUp();
        QByteArray Motor3MoveUp();
        QByteArray Motor4MoveUp();
        QByteArray Motor1MoveDown();
        QByteArray Motor2MoveDown();
        QByteArray Motor3MoveDown();
        QByteArray Motor4MoveDown();

        QByteArray getMotor1Prt();
        QByteArray getMotor2Prt();
        QByteArray getMotor3Prt();
        QByteArray getMotor4Prt();
        QByteArray getAutoPrt();

        ModeType getModeType();
        ~Mode();
    };
}


#endif // MODE_H

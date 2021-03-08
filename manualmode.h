#ifndef MANUALMODE_H
#define MANUALMODE_H
#include "abstractmode.h"
#include "motorunit.h"

namespace omron {
    class ManualMode : public AbstractMode
    {
    private:
        MotorUnit* Motors;
    public:
        ManualMode();
        ManualMode(MotorUnit &plcMotors);
        ~ManualMode();
        virtual QByteArray Motor1MoveUp();
        virtual QByteArray Motor2MoveUp();
        virtual QByteArray Motor3MoveUp();
        virtual QByteArray Motor4MoveUp();
        virtual QByteArray Motor1MoveDown();
        virtual QByteArray Motor2MoveDown();
        virtual QByteArray Motor3MoveDown();
        virtual QByteArray Motor4MoveDown();

        virtual QByteArray getMotor1Prt();
        virtual QByteArray getMotor2Prt();
        virtual QByteArray getMotor3Prt();
        virtual QByteArray getMotor4Prt();
        virtual QByteArray getAutoPrt(){return QByteArray();}

        virtual QByteArray StartAuto(){return QByteArray();}
        virtual ModeType getModeType();
    };
}


#endif // MANUALMODE_H

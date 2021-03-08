#ifndef AUTOMATICMODE_H
#define AUTOMATICMODE_H

#include "abstractmode.h"
#include"motorunit.h"
namespace omron {
    class AutomaticMode : public AbstractMode
    {
    private:
        MotorUnit* Motors;
    public:
        AutomaticMode();
        AutomaticMode(QByteArray input_autoflag);
        AutomaticMode(MotorUnit& plcMotors);
        ~AutomaticMode();
        virtual QByteArray Motor1MoveUp(){return QByteArray();}
        virtual QByteArray Motor2MoveUp(){return QByteArray();}
        virtual QByteArray Motor3MoveUp(){return QByteArray();}
        virtual QByteArray Motor4MoveUp(){return QByteArray();}
        virtual QByteArray Motor1MoveDown(){return QByteArray();}
        virtual QByteArray Motor2MoveDown(){return QByteArray();}
        virtual QByteArray Motor3MoveDown(){return QByteArray();}
        virtual QByteArray Motor4MoveDown(){return QByteArray();}

        virtual QByteArray getMotor1Prt(){return QByteArray();}
        virtual QByteArray getMotor2Prt(){return QByteArray();}
        virtual QByteArray getMotor3Prt(){return QByteArray();}
        virtual QByteArray getMotor4Prt(){return QByteArray();}
        virtual QByteArray getAutoPrt();
        virtual QByteArray StartAuto();
        virtual ModeType getModeType();
    };
}


#endif // AUTOMATICMODE_H

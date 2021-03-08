#ifndef ABSTRACTMODE_H
#define ABSTRACTMODE_H
#include <QByteArray>
#include "omronpst.h"
namespace omron {

    class AbstractMode
    {
    public:
        explicit AbstractMode(){}
        virtual ~AbstractMode(){}
        virtual QByteArray Motor1MoveUp()=0;
        virtual QByteArray Motor2MoveUp()=0;
        virtual QByteArray Motor3MoveUp()=0;
        virtual QByteArray Motor4MoveUp()=0;
        virtual QByteArray Motor1MoveDown()=0;
        virtual QByteArray Motor2MoveDown()=0;
        virtual QByteArray Motor3MoveDown()=0;
        virtual QByteArray Motor4MoveDown()=0;
        virtual QByteArray getMotor1Prt()=0;
        virtual QByteArray getMotor2Prt()=0;
        virtual QByteArray getMotor3Prt()=0;
        virtual QByteArray getMotor4Prt()=0;
        virtual QByteArray getAutoPrt()=0;
        virtual QByteArray StartAuto()=0;
        virtual ModeType getModeType()=0;
    };

}

#endif // ABSTRACTMODE_H

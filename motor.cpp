#include "motor.h"

omron::Motor::Motor(const QByteArray &motorlabel)
{
    MotorLabel = motorlabel;
    isPower = false;
}

QByteArray omron::Motor::MoveUp()
{
    QByteArray res = MotorLabel;
    return res;
}

QByteArray omron::Motor::MoveUpZero()
{
    return lastByteSetZero(MotorLabel);
}

QByteArray omron::Motor::MoveUpStop()
{
    QByteArray res = MotorLabel;
    if(res.size()<4)
        return res;
    res[3] = res.at(3)+(uint8_t)0x02;
    return res;
}

QByteArray omron::Motor::MoveUpStopZero()
{
    QByteArray res = MotorLabel;
    if(res.size()<4)
        return res;
    res[3] = res.at(3)+(uint8_t)0x02;
    return lastByteSetZero(res);
}

QByteArray omron::Motor::MoveDown()
{
    QByteArray res = MotorLabel;
    if(res.size()<4)
        return res;
    res[3] = res.at(3)+(uint8_t)0x01;
    return res;
}

QByteArray omron::Motor::MoveDownZero()
{
    QByteArray res = MotorLabel;
    if(res.size()<4)
        return res;
    res[3] = res.at(3)+(uint8_t)0x01;
    return lastByteSetZero(res);
}

QByteArray omron::Motor::MoveDownStop()
{
    QByteArray res = MotorLabel;
    if(res.size()<4)
        return res;
    res[3] = res.at(3)+(uint8_t)0x02;
    return res;
}

QByteArray omron::Motor::MoveDownStopZero()
{
    QByteArray res = MotorLabel;
    if(res.size()<4)
        return res;
    res[3] = res.at(3)+(uint8_t)0x02;
    return lastByteSetZero(res);
}

QByteArray omron::Motor::lastByteSetZero(QByteArray input)
{
    QByteArray res = input;
    res[res.size()-1] = (uint8_t)0x00;
    return res;
}

QByteArray omron::Motor::getMotorLabel()
{
    return MotorLabel;
}

void omron::Motor::setMotorLabel(const QByteArray &motorlabel)
{
    MotorLabel = motorlabel;
}

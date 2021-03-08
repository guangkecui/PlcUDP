#include "mode.h"
#include "manualmode.h"
#include "automaticmode.h"
#include <QMessageBox>


omron::Mode::Mode(omron::ModeType MType, omron::MotorUnit &plcMotors)
{
    switch (MType)
    {
    case Manual:
        _workingMode = new ManualMode(plcMotors);
        break;
    case Automatic:
        _workingMode = new AutomaticMode(plcMotors);
        break;
    default:
        QMessageBox msg;
        msg.setText("Mode initialization failed!");
        msg.exec();
        break;
    }
}

QByteArray omron::Mode::StartWorking()
{
    return _workingMode->StartAuto();
}

QByteArray omron::Mode::Motor1MoveUp()
{
    return _workingMode->Motor1MoveUp();
}

QByteArray omron::Mode::Motor2MoveUp()
{
    return _workingMode->Motor2MoveUp();
}

QByteArray omron::Mode::Motor3MoveUp()
{
    return _workingMode->Motor3MoveUp();
}

QByteArray omron::Mode::Motor4MoveUp()
{
    return _workingMode->Motor4MoveUp();
}

QByteArray omron::Mode::Motor1MoveDown()
{
    return _workingMode->Motor1MoveDown();
}

QByteArray omron::Mode::Motor2MoveDown()
{
    return _workingMode->Motor2MoveDown();
}

QByteArray omron::Mode::Motor3MoveDown()
{
    return _workingMode->Motor3MoveDown();
}

QByteArray omron::Mode::Motor4MoveDown()
{
    return _workingMode->Motor4MoveDown();
}

QByteArray omron::Mode::getMotor1Prt()
{
    return _workingMode->getMotor1Prt();
}

QByteArray omron::Mode::getMotor2Prt()
{
    return _workingMode->getMotor2Prt();
}

QByteArray omron::Mode::getMotor3Prt()
{
    return _workingMode->getMotor3Prt();
}

QByteArray omron::Mode::getMotor4Prt()
{
    return _workingMode->getMotor4Prt();
}

QByteArray omron::Mode::getAutoPrt()
{
    return _workingMode->getAutoPrt();
}

omron::ModeType omron::Mode::getModeType()
{
    return _workingMode->getModeType();
}

omron::Mode::~Mode()
{
    if(_workingMode!=nullptr){
        delete _workingMode;
        _workingMode = nullptr;
    }
}

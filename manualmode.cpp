#include "manualmode.h"

omron::ManualMode::ManualMode()
{
    Motors = new MotorUnit();
}

omron::ManualMode::ManualMode(omron::MotorUnit &plcMotors)
{
    Motors = new MotorUnit();
    if(!plcMotors.getMotor1().isEmpty())
        Motors->setMotor1(plcMotors.getMotor1());
    if(!plcMotors.getMotor2().isEmpty())
        Motors->setMotor2(plcMotors.getMotor2());
    if(!plcMotors.getMotor3().isEmpty())
        Motors->setMotor3(plcMotors.getMotor3());
    if(!plcMotors.getMotor4().isEmpty())
        Motors->setMotor4(plcMotors.getMotor4());
    if(!plcMotors.getAutoFlag().isEmpty())
        Motors->setAutoFlag(plcMotors.getAutoFlag());
}

omron::ManualMode::~ManualMode()
{
    if(Motors!=nullptr){
        delete Motors;
        Motors = nullptr;
    }
}

QByteArray omron::ManualMode::Motor1MoveUp()
{
    return Motors->MotorMoveUp(1);
}

QByteArray omron::ManualMode::Motor2MoveUp()
{
    return Motors->MotorMoveUp(2);
}

QByteArray omron::ManualMode::Motor3MoveUp()
{
    return Motors->MotorMoveUp(3);
}

QByteArray omron::ManualMode::Motor4MoveUp()
{
    return Motors->MotorMoveUp(4);
}

QByteArray omron::ManualMode::Motor1MoveDown()
{
    return Motors->MotorMoveDown(1);
}

QByteArray omron::ManualMode::Motor2MoveDown()
{
    return Motors->MotorMoveDown(2);
}

QByteArray omron::ManualMode::Motor3MoveDown()
{
    return Motors->MotorMoveDown(3);
}

QByteArray omron::ManualMode::Motor4MoveDown()
{
    return Motors->MotorMoveDown(4);
}

QByteArray omron::ManualMode::getMotor1Prt()
{
    return Motors->getMotor1();
}

QByteArray omron::ManualMode::getMotor2Prt()
{
    return Motors->getMotor2();
}

QByteArray omron::ManualMode::getMotor3Prt()
{
    return Motors->getMotor3();
}

QByteArray omron::ManualMode::getMotor4Prt()
{
    return Motors->getMotor4();
}

omron::ModeType omron::ManualMode::getModeType()
{
    return ModeType::Manual;
}

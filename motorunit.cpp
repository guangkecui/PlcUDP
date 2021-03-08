#include "motorunit.h"

omron::MotorUnit::MotorUnit()
{
    motor1 = new Motor();
    motor2 = new Motor();
    motor3 = new Motor();
    motor4 = new Motor();
    autoFlag = new QByteArray();
    camsFlag = new QByteArray();
    manualContinuousFlag = new QByteArray();
    manualStepFlag = new QByteArray();
}

omron::MotorUnit::~MotorUnit()
{
    if(motor1!=nullptr){
        delete motor1;
        motor1 = nullptr;
    }
    if(motor2!=nullptr){
        delete motor2;
        motor2 = nullptr;
    }
    if(motor3!=nullptr){
        delete motor3;
        motor3 = nullptr;
    }
    if(motor4!=nullptr){
        delete motor4;
        motor4 = nullptr;
    }
    if(autoFlag!=nullptr){
        delete autoFlag;
        autoFlag = nullptr;
    }
    if(camsFlag!=nullptr){
        delete camsFlag;
        camsFlag = nullptr;
    }
    if(manualContinuousFlag!=nullptr){
        delete manualContinuousFlag;
        manualContinuousFlag = nullptr;
    }
    if(manualStepFlag!=nullptr){
        delete manualStepFlag;
        manualStepFlag = nullptr;
    }


}

bool omron::MotorUnit::setMotor1(QByteArray motorlabel)
{
    if(motorlabel.size()!=MOTORLABELLEN)
        return false;
    motor1->setMotorLabel(motorlabel);
    return true;
}

bool omron::MotorUnit::setMotor2(QByteArray motorlabel)
{
    if(motorlabel.size()!=MOTORLABELLEN)
        return false;
    motor2->setMotorLabel(motorlabel);
    return true;
}

bool omron::MotorUnit::setMotor3(QByteArray motorlabel)
{
    if(motorlabel.size()!=MOTORLABELLEN)
        return false;
    motor3->setMotorLabel(motorlabel);
    return true;
}

bool omron::MotorUnit::setMotor4(QByteArray motorlabel)
{
    if(motorlabel.size()!=MOTORLABELLEN)
        return false;
    motor4->setMotorLabel(motorlabel);
    return true;
}

bool omron::MotorUnit::setAutoFlag(QByteArray input_autoflag)
{
    if(input_autoflag.size()!=MOTORLABELLEN)
        return false;
    if(autoFlag!=nullptr){
        delete autoFlag;
        autoFlag = nullptr;
    }
    autoFlag = new QByteArray(input_autoflag);
    return true;
}

bool omron::MotorUnit::setCamsFlag(QByteArray input_camsflag)
{
    if(input_camsflag.size()!=CAMSLEN)
        return false;
    if(camsFlag!=nullptr){
        delete camsFlag;
        camsFlag = nullptr;
    }
    camsFlag = new QByteArray(input_camsflag);
    return true;
}

bool omron::MotorUnit::setManualContinuousFlag(QByteArray inputFlag)
{
    if(inputFlag.size()!=MOTORLABELLEN)
        return false;
    if(manualContinuousFlag!=nullptr){
        delete manualContinuousFlag;
        manualContinuousFlag = nullptr;
    }
    manualContinuousFlag = new QByteArray(inputFlag);
    return true;
}

bool omron::MotorUnit::setManualStepFlag(QByteArray inputFlag)
{
    if(inputFlag.size()!=MOTORLABELLEN)
        return false;
    if(manualStepFlag!=nullptr){
        delete manualStepFlag;
        manualStepFlag = nullptr;
    }
    manualStepFlag = new QByteArray(inputFlag);
    return true;
}

QByteArray omron::MotorUnit::getMotor1()
{
    return motor1->getMotorLabel();
}

QByteArray omron::MotorUnit::getMotor2()
{
    return motor2->getMotorLabel();
}

QByteArray omron::MotorUnit::getMotor3()
{
    return motor3->getMotorLabel();
}

QByteArray omron::MotorUnit::getMotor4()
{
    return motor4->getMotorLabel();
}

QByteArray omron::MotorUnit::getAutoFlag()
{
    return *autoFlag;
}

QByteArray omron::MotorUnit::getCamsFlag()
{
    return *camsFlag;
}

QByteArray omron::MotorUnit::getManualContinuousFlag()
{
    return *manualContinuousFlag;
}

QByteArray omron::MotorUnit::getManualStepFlag()
{
    return *manualStepFlag;
}

QByteArray omron::MotorUnit::MotorMoveUp(int motor)
{
    switch (motor) {
    case 1:
        return motor1->MoveUp();
        break;
    case 2:
        return motor2->MoveUp();
        break;
    case 3:
        return motor3->MoveUp();
        break;
    case 4:
        return motor4->MoveUp();
        break;
    default:
        break;
    }
}


QByteArray omron::MotorUnit::StartAuto()
{
    return *autoFlag;
}

/**********************************************
  函数名称：MotorMoveUpZero
  输入参数：
  输出参数：
  函数功能：对相应的相机的up标志位置零
**********************************************/
QByteArray omron::MotorUnit::MotorMoveUpZero(int motor)
{
    switch (motor) {
    case 1:
        return motor1->MoveUpZero();
        break;
    case 2:
        return motor2->MoveUpZero();
        break;
    case 3:
        return motor3->MoveUpZero();
        break;
    case 4:
        return motor4->MoveUpZero();
        break;
    default:
        break;
    }
}

QByteArray omron::MotorUnit::MotorMoveUpStop(int motor)
{
    switch (motor) {
    case 1:
        return motor1->MoveUpStop();
        break;
    case 2:
        return motor2->MoveUpStop();
        break;
    case 3:
        return motor3->MoveUpStop();
        break;
    case 4:
        return motor4->MoveUpStop();
        break;
    default:
        break;
    }
}

/**********************************************
  函数名称：MotorMoveUpStopZero
  输入参数：
  输出参数：
  函数功能：对相应的相机的up-stop标志位置零
**********************************************/
QByteArray omron::MotorUnit::MotorMoveUpStopZero(int motor)
{
    switch (motor) {
    case 1:
        return motor1->MoveUpStopZero();
        break;
    case 2:
        return motor2->MoveUpStopZero();
        break;
    case 3:
        return motor3->MoveUpStopZero();
        break;
    case 4:
        return motor4->MoveUpStopZero();
        break;
    default:
        break;
    }
}

QByteArray omron::MotorUnit::MotorMoveDown(int motor)
{
    switch (motor) {
    case 1:
        return motor1->MoveDown();
        break;
    case 2:
        return motor2->MoveDown();
        break;
    case 3:
        return motor3->MoveDown();
        break;
    case 4:
        return motor4->MoveDown();
        break;
    default:
        break;
    }
}

/**********************************************
  函数名称：MotorMoveDownZero
  输入参数：
  输出参数：
  函数功能：对相应的相机的down标志位置零
**********************************************/
QByteArray omron::MotorUnit::MotorMoveDownZero(int motor)
{
    switch (motor) {
    case 1:
        return motor1->MoveDownZero();
        break;
    case 2:
        return motor2->MoveDownZero();
        break;
    case 3:
        return motor3->MoveDownZero();
        break;
    case 4:
        return motor4->MoveDownZero();
        break;
    default:
        break;
    }
}

QByteArray omron::MotorUnit::MotorMoveDownStop(int motor)
{
    switch (motor) {
    case 1:
        return motor1->MoveDownStop();
        break;
    case 2:
        return motor2->MoveDownStop();
        break;
    case 3:
        return motor3->MoveDownStop();
        break;
    case 4:
        return motor4->MoveDownStop();
        break;
    default:
        break;
    }
}

/**********************************************
  函数名称：MotorMoveDownStopZero
  输入参数：
  输出参数：
  函数功能：对相应的相机的down-stop标志位置零
**********************************************/
QByteArray omron::MotorUnit::MotorMoveDownStopZero(int motor)
{
    switch (motor) {
    case 1:
        return motor1->MoveDownStopZero();
        break;
    case 2:
        return motor2->MoveDownStopZero();
        break;
    case 3:
        return motor3->MoveDownStopZero();
        break;
    case 4:
        return motor4->MoveDownStopZero();
        break;
    default:
        break;
    }
}

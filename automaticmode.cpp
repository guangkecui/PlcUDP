#include "automaticmode.h"

omron::AutomaticMode::AutomaticMode()
{
    Motors = new MotorUnit();
}

omron::AutomaticMode::AutomaticMode(QByteArray input_autoflag)
{
    if(Motors!=nullptr){
        delete Motors;
        Motors = new MotorUnit();
    }
    Motors->setAutoFlag(input_autoflag);
}

omron::AutomaticMode::AutomaticMode(omron::MotorUnit &plcMotors)
{
    Motors = new MotorUnit();
    Motors->setAutoFlag(plcMotors.getAutoFlag());
}

omron::AutomaticMode::~AutomaticMode()
{
    if(Motors!=nullptr){
        delete Motors;
        Motors = nullptr;
    }
}

QByteArray omron::AutomaticMode::getAutoPrt()
{
    return Motors->getAutoFlag();
}

QByteArray omron::AutomaticMode::StartAuto()
{
    return Motors->StartAuto();
}

omron::ModeType omron::AutomaticMode::getModeType()
{
    return ModeType::Automatic;
}

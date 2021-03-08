#include "cameradata.h"

Cameradata::Cameradata():
    SerialNum(""),
    Horizontal(false),
    Vertial(false)
{

}

Cameradata::~Cameradata()
{
}

void Cameradata::setM(const cv::Mat InputM)
{
    M = InputM.clone();
}

cv::Mat Cameradata::getM() const
{
    return M;
}

cv::Mat Cameradata::getDist() const
{
    return Dist;
}

cv::Mat Cameradata::getROfSensor() const
{
    return RToSensorFromCamera;
}

cv::Mat Cameradata::getTOfSensor() const
{
    return TToSensorFromCamera;
}


void Cameradata::setDist(const cv::Mat InputDist)
{
    Dist = InputDist.clone();
}

void Cameradata::setRToSensor(const cv::Mat InputR)
{
    RToSensorFromCamera = InputR.clone();
}

void Cameradata::setTToSensor(const cv::Mat InputT)
{
    TToSensorFromCamera = InputT.clone();
}



void Cameradata::setHorizontal(bool InputHorizontal)
{
    Horizontal = InputHorizontal;
}

void Cameradata::setVertial(bool InputVertial)
{
    Vertial = InputVertial;
}

void Cameradata::setSerialNum(QString InputSerNum)
{
    SerialNum = InputSerNum;
}

QString Cameradata::getSerialNum() const
{
    return SerialNum;
}

bool Cameradata::isHorizontal() const
{
    return Horizontal;
}

bool Cameradata::isVertial() const
{
    return Vertial;
}

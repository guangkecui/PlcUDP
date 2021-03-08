#ifndef SENSORUNIT_H
#define SENSORUNIT_H
#include<memory>
#include"sensordata.h"


class sensorunit
{
public:
    sensorunit();
    ~sensorunit();

    Sensordata* Sensor_1;//1号传感器
    Sensordata* Sensor_2;
    Sensordata* Sensor_3;
    Sensordata* Sensor_4;
};

#endif // SENSORUNIT_H

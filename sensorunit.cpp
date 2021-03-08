#include "sensorunit.h"
#include"omronpst.h"
sensorunit::sensorunit()
{
    Sensor_1 = new Sensordata();
    Sensor_2 = new Sensordata();
    Sensor_3 = new Sensordata();
    Sensor_4 = new Sensordata();
}

sensorunit::~sensorunit()
{
    delete Sensor_1;
    delete Sensor_2;
    delete Sensor_3;
    delete Sensor_4;
}

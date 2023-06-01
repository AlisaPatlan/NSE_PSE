#ifndef ACCELEROMETER_H
#define ACCELEROMETER_H

#include <Wire.h>
#include <Zumo32U4.h>

class Accelerometer {
public:
    Accelerometer();
    void leesSensor();
    void initSensor();
private:
  Zumo32U4IMU imu;
  Zumo32U4Motors motors;
  Zumo32U4ButtonA buttonA;
  Zumo32U4Encoders encoders;
};


#endif
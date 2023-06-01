
#ifndef PROXSENSOR_H
#define PROXSENSOR_H
#include <Wire.h>
#include <Zumo32U4.h>
#include <Zumo32U4ProximitySensors.h>
class proxSensor:public Sensors
{
  public:
  proxSensors();
  ~proxSensors();
  int read();
  int SensorStatus();
  
  private:
 bool detectedObstacle;
  int statusProxSensor;

};

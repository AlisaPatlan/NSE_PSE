
#ifndef PROXSENSOR_H
#define PROXSENSOR_H
#include <Wire.h>
#include <Zumo32U4.h>
#include <Zumo32U4ProximitySensors.h>
#include <MotorsControler.h>


class proxSensor:
{
  public:
  proxSensors();
  ~proxSensors();
  bool Obstakel();
  
  
  private:
  int rechterSensor;
  int linkerSensor;
  MotorsControler motorcont;

  


}

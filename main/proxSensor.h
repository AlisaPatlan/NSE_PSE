
#ifndef PROXSENSOR_H
#define PROXSENSOR_H
#include <Wire.h>
#include "Zumo32U4.h"
#include "Zumo32U4ProximitySensors.h"
#include "MotorsControler.h"
/*! Header-file van de proxSensor bevat alle attributten en methodes van class proxSensor. 
* De methodes worden in de proxSensor.cpp file geïmplementeerd. Deze class maakt gebruik van de standart library van Pololu.
*/



class proxSensor{
  public:
  proxSensor();
  bool Obstakel();
  void InitSensors();
  
  
  private:
  int rechterSensor;
  int linkerSensor;
  MotorsControler motorcont;

};

#endif
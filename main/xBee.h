#ifndef ZUMO_ROBOT_H
#define ZUMO_ROBOT_H

#include <Zumo32U4.h>
#include <Wire.h>

/*! Header-file van de xBee bevat alle attributten en methodes van class xBee. 
* De methodes worden in de xBee.cpp file geïmplementeerd. Deze class maakt gebruik van de standart library van Pololu.
*/

class ZumoRobot {
private:
  Zumo32U4Motors motors;

public:
  ZumoRobot();
  void handleCommands();
};

#endif

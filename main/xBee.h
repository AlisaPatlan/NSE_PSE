#ifndef ZUMO_ROBOT_H
#define ZUMO_ROBOT_H

#include <Zumo32U4.h>
#include <Wire.h>

class ZumoRobot {
private:
  Zumo32U4Motors motors;

public:
  ZumoRobot();
  void handleCommands();
};

#endif

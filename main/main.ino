#include "MotorsControler.h"
#include "LineSensor.h"
#include "xBee.h"
#include "proxSensor.h"
#include "Accelerometer.h"
#include <Wire.h>
using namespace std;
MotorsControler ZumoMotor;
LineSensor LineSensors;
Accelerometer accMeter;
ZumoRobot zumo;
proxSensor proxSensor;
Zumo32U4ButtonA buttonA;
Zumo32U4ButtonB buttonB;

String gedrukteKnop = "";
bool knopGedrukt = false;


void setup()
{
  Serial1.begin(9000);
  //LineSensors.initSensor();
  //LineSensors.calibrateSensors();
  do{
  if(buttonA.isPressed()){
    gedrukteKnop = "a";
    knopGedrukt = true;
  }
  if(buttonB.isPressed()){
    gedrukteKnop = "b";
    knopGedrukt = true;
  }
  } while (!knopGedrukt);

}

void loop()
{
  if(gedrukteKnop == "a"){
    LineSensors.volgLijn();
    LineSensors.rijdOpGroen();
  }
  if(gedrukteKnop == "b"){
    zumo.handleCommands();
  }
}


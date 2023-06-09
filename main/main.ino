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
xBee xBeeConnectie;
proxSensor proxSensor;
Zumo32U4ButtonA buttonA;
Zumo32U4ButtonB buttonB;

String gedrukteKnop = "";
bool knopGedrukt = false;


void setup()
{
  Serial.begin(9000);
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
<<<<<<< HEAD
  //het duwen van het blokje


  uint16_t sensorValues  [0]; //value left sensor
  uint16_t sensorValues[2]; //value right sensor
  LineSensors.read(sensorValues);
  /* als de sensor bruine dwarsliggende lijn detecteert rijdt hij 20 cm naar voren
      en doet 3 pogingen om het blokje te detecteren.
      ZUMO draait om zijn as en gebruikt proximity sensor.
      Als hij het blokje detecteert, rijdt hij naar voren op hoge snelheid.
      */
  if (LineSensors.bruinBeideGezien){
    motors.StartRijdenCirkel(200,200);
=======
  if(gedrukteKnop == "a"){
      LineSensors.leesWaarde();
      bool bruinGezien = LineSensors.bruinBeideGezien();
      if (bruinGezien){
        ZumoMotor.startRijdenCirkel(200,200);
      }
      ZumoMotor.startRijden(200,0);  
      bool obstakel = proxSensor.Obstakel();
      if (obstakel == true) {
        ZumoMotor.stopRijden();
        delay(100);
        ZumoMotor.startRijden(400,400);
      }
      else{
        ZumoMotor.startRijden(200,0);
>>>>>>> 85927f799481cf6f2e794a34b2fbce3e1b022d07
      }
  }
  if(gedrukteKnop == "b"){
    if (Serial1.available()){
    char command = Serial1.read();
    Serial1.write(command);
     switch (command){
      case 'W': // Forward
        ZumoMotor.startRijden(200, 200); // Adjust the motor speeds as needed
        break;
      
      case 'S': // Backward
        ZumoMotor.startRijden(-200, -200); // Adjust the motor speeds as needed
        break;
      
      case 'A': // Turn left
        ZumoMotor.startRijden(-200, 200); // Adjust the motor speeds as needed
        break;
      
      case 'D': // Turn right
        ZumoMotor.startRijden(200, -200); // Adjust the motor speeds as needed
        break;
      case 'X': // Stop
        ZumoMotor.stopRijden();
        break;
    }
  }
  }
}

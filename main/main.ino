#include "MotorsControler.h"
#include "LineSensor.h"
#include "xBee.h"
#include "proxSensor.h"
#include "Accelerometer.h"

using namespace std;
MotorsControler ZumoMotor;
LineSensor LineSensors;
Accelerometer accMeter;
xBee xBeeConnectie;
proxSensor proxSensor;


void setup()
{
  Serial.begin(9000);
}

void loop()
{
  /* als de sensor bruine dwarsliggende lijn detecteert rijdt hij 20 cm naar voren
      en doet 3 pogingen om het blokje te detecteren.
      ZUMO draait om zijn as en gebruikt proximity sensor.
      Als hij het blokje detecteert, rijdt hij naar voren op hoge snelheid.
      */
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
    
  }

  
}

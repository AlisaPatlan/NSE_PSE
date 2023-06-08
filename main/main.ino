#include "MotorsControler.h"
#include "LineSensor.h"
#include "accMeter.h"
#include "xBee.h"
#include "proxSensor.h"

using namespace std;
MotorsControler ZumoMotor;
LineSensor LineSensors;
accMeter acceleroMeter;
xBee xBeeConnectie;
proxSensor proxSensor;

void setup()
{
  Serial.begin(9000);
}

void loop()
{
  //het duwen van het blokje


  uint16_t sensorValues[0]; //value left sensor
  uint16_t sensorValues[2]; //value right sensor
  LineSensors.read(sensorValues);
  /* als de sensor bruine dwarsliggende lijn detecteert rijdt hij 20 cm naar voren
      en doet 3 pogingen om het blokje te detecteren.
      ZUMO draait om zijn as en gebruikt proximity sensor.
      Als hij het blokje detecteert, rijdt hij naar voren op hoge snelheid.
      */
  if (LineSensors.bruinBeideGezien){
    motors.StartRijdenCirkel(200,200);
      }
  motors.setSpeeds(200,0);  
  proxSensors.Obstakel();
  if (Obstakel == true) {
    motors.setSpeeds;
    Delay(100);
    motors.setSpeeds(400,400);

  }
  else{
    motors.setSpeeds(200,0);
    
  }
    // Controleer of een van de sensoren een obstakel detecteert
  //if (proxSensors.countsFrontWithLeftLeds() > 4  ||
      //proxSensors.countsFrontWithRightLeds() > 4) {
    // Blok gedetecteerd, ga vooruit rijden
    //motors.setSpeeds(400, 400); //op max speed 
      //} 
      //else { }

  
}

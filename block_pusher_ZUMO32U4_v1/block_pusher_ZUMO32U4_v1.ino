#include <Wire.h>
#include <Zumo32U4.h>
#include <Zumo32U4ProximitySensors.h>
#include <Zumo32U4LineSensors.h>

Zumo32U4Motors motors;
Zumo32U4ProximitySensors proxSensors;
Zumo32U4LineSensors lineSensors;


void setup() {
  motors.setSpeeds(0, 0);
  proxSensors.initThreeSensors();
  lineSensors.initThreeSensors();
}

void loop() {
  lineSensors.read();
  uint16_t sensorValues[3]; //value brown line
  lineSensors.read(sensorValues);
  /* als de sensor bruine dwarsliggende lijn detecteert rijdt hij 20 cm naar voren
      en doet 3 pogingen om het blokje te detecteren.
      ZUMO draait om zijn as en gebruikt proximity sensor.
      Als hij het blokje detecteert, rijdt hij naar voren op hoge snelheid.
      */
  if 
motors.setSpeeds(-200, -200);
  proxSensors.read();
  Serial.println("L:");
  Serial.println(proxSensors.countsFrontWithLeftLeds());
  Serial.println("R:");
  Serial.println(proxSensors.countsFrontWithRightLeds());
  // Controleer of een van de sensoren een obstakel detecteert
  //if (proxSensors.countsFrontWithLeftLeds() > 4  ||
  //    proxSensors.countsFrontWithRightLeds() > 4) {
    // Obstakel gedetecteerd, ga achteruit rijden
    //motors.setSpeeds(-200, -200);
   // delay(500); // Achteruit rijden gedurende 1 seconde
 //} 
  
  //else {
    // Geen obstakel gedetecteerd, ga vooruit rijden
    //motors.setSpeeds(200, 200);
 // }
}

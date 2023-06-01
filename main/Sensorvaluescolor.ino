#include <Wire.h>
#include <Zumo32U4.h>

Zumo32U4LineSensors lineSensors;
uint16_t lineSensorValues[3];

void setup()
{
  Serial.begin(9600);
  lineSensors.initThreeSensors(); //initialisatie sensoren
}




void loop()
{
  lineSensors.read(lineSensorValues);
  uint16_t leftSensorvalue = lineSensorValues[0];

//statement om de linkersensor de grijze kleur te laten zien en dan vervolgens naar links te draaien 
// zodra de linker of rechter sensor zwart opmerkt
bool grijsLinksGezien = sensorValues[0] > 400 && sensorValues[0] < 600;
if (grijsLinksGezien);
{
 
  if (sensorValues[0] || sensorValues[2] > 1000){

  motors.setSpeeds(-150, 150);
  delay(500);
  motors.setSpeeds(150, 150);
  }
}



lineSensors.read(lineSensorValues);
  uint16_t rightSensorvalue = lineSensorValues[2];

//statement om de rechtersensor de grijze kleur te laten zien en dan vervolgens naar rechts te draaien 
// zodra de linker of rechter sensor zwart opmerkt
bool grijsRechtsGezien = sensorValues[2] > 400 && sensorValues[2] < 600;
if (grijsRechtsGezien);
{
if (sensorValues[0] > 1000 || sensorValues[2] > 1000) {
  motors.setSpeeds(150, -150);
  delay(500);
  motors.setSpeeds(150, 150);

}

//deze code is voor de wipwap, zodat de robot van beide kanten grijs ziet en dan stopt als
// de waarde nog groter is dan 0, is de waarde kleiner dan 0 dan rijdt de robot weer door
if (sensorValues[0] > 400 && sensorValues[0] < 600) && (sensorValues[2] > 400 && sensorValues[2] < 600){
if (x>0) 
{ 
motors.setSpeeds(0,0);
}
else if (x < 0){
 motors.setSpeeds(150, 150); 
}
}

}

}

#include "LijnSensor.h"
#include <Wire.h>
#include <Zumo32U4.h>

uint16_t lineSensorValues[3];
Zumo32U4LineSensors lineSensors;

LineSensor::LineSensor(); {}

void LineSensor::initSensor(){

  lineSensors.initThreeSensors();
}

void LineSensor::leesWaarde() {
//leest de linesensors af en geeft aan welke kleur het is (gekoppeld met waardes)
if ((sensorValues[0] > 600 && sensorValues[0] < 1000) && (sensorValues[2] > 600 && sensorValues[2] < 1000)) {
    Serial.println("bruin");
  }

  else if ((sensorValues[0] > 400 && sensorValues[0] < 600) && (sensorValues[2] > 400 && sensorValues[2] < 600)) {
    Serial.println("grijs");
  }

  else if ((sensorValues[0] > 1000) && (sensorValues[2] > 1000)) {
    Serial.println("zwart");

    else if ((sensorValues[0] > 200 && sensorValues[0] < 300) && (sensorValues[2] > 200 && sensorValues[2] < 300)) {
      Serial.println("groen");
      motorControler.startRijden(100,100);
    }
  }
}

void leesKleurWaarde(){
  lineSensors.read(lineSensorValues);
  uint16_t linkerSensorWaarde = lineSensorValues[0];
  uint16_t rechterSensorWaarde = lineSensorValues[2];

  bool grijsLinksGezien = false; 
  bool grijsRechtsGezien = false;

  if (sensorValues[0] > 400 && sensorValues[0] < 600;);
  {
    grijsLinksGezien = true;
  }
  if(grijsLinksGezien && grijsRechtsGezien != true){
    if (sensorValues[0] || sensorValues[2] > 1000){
        motors.setSpeeds(-150, 150);
        delay(500);
        motors.setSpeeds(150, 150);
        grijsLinksGezien = false;
      }
  }

  if (sensorValues[2] > 400 && sensorValues[2] < 600;);
  {
    grijsRechtsGezien = true;
  }
  if(grijsRechtsGezien && grijsLinksGezien != true){
    if (sensorValues[0] > 1000 || sensorValues[2] > 1000) {
    motors.setSpeeds(150, -150);
    delay(500);
    motors.setSpeeds(150, 150);
    grijsRechtsGezien = false;
    }
  }
  
  if(grijsLinksGezien && grijsLinksGezien){
    if (x>0) 
      { 
        motors.setSpeeds(0,0);
      }
      else if (x < 0){
        motors.setSpeeds(150, 150); 
        grijsLinksGezien = false; 
        grijsRechtsGezien = false;
      }
  }
}
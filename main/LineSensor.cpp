#include "LineSensor.h"
#include "Accelerometer.h"
#include <Wire.h>
#include <Zumo32U4.h> 

//unsigned int lineSensorValues[NUM_SENSORS];//toegevoegd door Alisa, misschien verwijderen

uint16_t sensorValues[5];
uint16_t lineSensorValues[5];
int16_t lastError = 0; //toegevoegd door Alisa, misschien verwijderen
uint16_t maxSpeed = 200;

Zumo32U4LineSensors lineSensors;

LineSensor::LineSensor() {

}

void LineSensor::initSensor(){

  lineSensors.initFiveSensors();
  calibrateSensors();
}

void LineSensor::volgLijn() {

  int16_t positie = lineSensors.readLine(lineSensorValues);

  int16_t error = positie - 2000;
  int16_t speedDifference = error / 6 + 2 * (error - lastError);

  lastError = error;

  int16_t leftSpeed = (int16_t)maxSpeed + speedDifference;
  int16_t rightSpeed = (int16_t)maxSpeed - speedDifference;

  leftSpeed = constrain(leftSpeed, 0, (int16_t)maxSpeed);
  rightSpeed = constrain(rightSpeed, 0, (int16_t)maxSpeed);

  motorControler.startRijden(leftSpeed, rightSpeed);
}

void LineSensor::calibrateSensors()
{


  // Wait 1 second and then begin automatic sensor calibration
  // by rotating in place to sweep the sensors over the line
  delay(1000);
  for(uint16_t i = 0; i < 120; i++)
  {
    if (i > 30 && i <= 90)
    {
      motorControler.startRijden(-200, 200);
    }
    else
    {
      motorControler.startRijden(200, -200);
    }

    lineSensors.calibrate();
  }
  motorControler.startRijden(0, 0);
}

void LineSensor::rijdOpGroen(){
  lineSensors.read(sensorValues);
  if ((sensorValues[3] > 300) && (sensorValues[3] < 399)){
  int16_t positie = lineSensors.readLine(sensorValues[3]);

  int16_t error = positie - 2000;
  int16_t speedDifference = error / 6 + 2 * (error - lastError);

  lastError = error;

  int16_t leftSpeed = (int16_t)(maxSpeed/2) + speedDifference;
  int16_t rightSpeed = (int16_t)(maxSpeed/2) - speedDifference;

  leftSpeed = constrain(leftSpeed, 0, (int16_t)(maxSpeed/2));
  rightSpeed = constrain(rightSpeed, 0, (int16_t)(maxSpeed/2));

  motorControler.startRijden(leftSpeed, rightSpeed);
  }
}

int LineSensor::leesWaarde() {
//leest de linesensors af en geeft aan welke kleur het is (gekoppeld met waardes)
lineSensors.read(sensorValues);
if ((sensorValues[0] > 500 && sensorValues[0] < 999) && (sensorValues[5] > 500 && sensorValues[5] < 999)) {
    Serial.println("bruin");
    return 1;
  }
  else if ((sensorValues[0] > 400 && sensorValues[0] < 499) && (sensorValues[2] > 400 && sensorValues[2] < 499)) {
    Serial.println("grijs");
    return 2;
  }
    
    else if ((sensorValues[0] > 300 && sensorValues[0] < 399) && (sensorValues[5] > 300 && sensorValues[5] < 399)) {
      Serial.println("groen");
      return 3;
    }
  else if ((sensorValues[3] > 1000)) {
    Serial.println("zwart");
    return 5;
  }

}


//void LineSensor::leesKleurWaarde(){
/*void LineSensor::leesKleurWaarde(){
  uint16_t xWaarde = 0 ;
>>>>>>> 14474ebacb15c4ae63c01386145093a1c2588460
  lineSensors.read(sensorValues);
  uint16_t linkerSensorWaarde = sensorValues[0];
  uint16_t rechterSensorWaarde = sensorValues[5];

  bool grijsLinksGezien = false; 
  bool grijsRechtsGezien = false;

  if (sensorValues[0] > 400 && sensorValues[0] < 600)
  {
    grijsLinksGezien = true;
  }
  if(grijsLinksGezien && grijsRechtsGezien != true){
    if (sensorValues[0] || sensorValues[2] > 1000){
        motorControler.startRijden(-150, 150);
        delay(500);
        motorControler.startRijden(150, 150);
        grijsLinksGezien = false;
      }
  }

  if (sensorValues[5] > 400 && sensorValues[5] < 600)
  {
    grijsRechtsGezien = true;
  }
  if(grijsRechtsGezien && grijsLinksGezien != true){
    if (sensorValues[0] > 1000 || sensorValues[2] > 1000) {
    motorControler.startRijden(150, -150);
    delay(500);
    motorControler.startRijden(150, 150);
    grijsRechtsGezien = false;
    }
  }
}
  void LineSensor::Helling(){
    uint16_t xWaarde = 0 ;
  lineSensors.read(sensorValues);
  uint16_t linkerSensorWaarde = sensorValues[0];
  uint16_t rechterSensorWaarde = sensorValues[5];
    bool grijsLinksGezien = false; 
  bool grijsRechtsGezien = false;

  if(grijsLinksGezien && grijsLinksGezien){
    if (xWaarde>0) 
      { 
        motorControler.stopRijden();
      }
      else if (xWaarde < 0){
        motorControler.startRijden(150, 150); 
        grijsLinksGezien = false; 
        grijsRechtsGezien = false;
      }
  }else{
    motorControler.startRijden(150,150);
  }
  
}*/

bool LineSensor::bruinBeideGezien(){
  lineSensors.read(lineSensorValues);
  uint16_t linkerSensorWaarde = sensorValues[0];
  uint16_t rechterSensorWaarde = sensorValues[2];

  if (((sensorValues[0] > 600) && (sensorValues[0] < 1000))&&((sensorValues[0] > 600) && (sensorValues[0] < 1000)))
  {
    return true;
  }
  return false;
}
  
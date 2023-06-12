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


  // put your main code here, to run repeatedly:
  int16_t position = lineSensors.readLine(lineSensorValues);
  int16_t error = position - 2000;
   int16_t speedDifference = error / 4 + 6 * (error - lastError);
   lastError = error;
   int16_t leftSpeed = (int16_t)maxSpeed + speedDifference;
  int16_t rightSpeed = (int16_t)maxSpeed - speedDifference;
   leftSpeed = constrain(leftSpeed, 0, (int16_t)maxSpeed);
  rightSpeed = constrain(rightSpeed, 0, (int16_t)maxSpeed);

  motorControler.startRijden(150, 150);
}

void LineSensor::calibrateSensors()
{
  lineSensors.initFiveSensors(); 


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


void LineSensor::leesWaarde() {
//leest de linesensors af en geeft aan welke kleur het is (gekoppeld met waardes)
if ((sensorValues[0] > 600 && sensorValues[0] < 1000) && (sensorValues[2] > 600 && sensorValues[2] < 1000)) {
    Serial.println("bruin");
  }

  else if ((sensorValues[0] > 400 && sensorValues[0] < 600) && (sensorValues[2] > 400 && sensorValues[2] < 600)) {
    Serial.println("grijs");
  }

  else if ((sensorValues[1] > 1000)) {
    Serial.println("zwart");
    motorControler.startRijden(200, 200);
    
  }

    else if ((sensorValues[0] > 200 && sensorValues[0] < 300) && (sensorValues[2] > 200 && sensorValues[2] < 300)) {
      Serial.println("groen");
      motorControler.startRijden(100,100);
    }
  }


void LineSensor::leesKleurWaarde(){
  uint16_t xWaarde = 0 ;
  lineSensors.read(sensorValues);
  uint16_t linkerSensorWaarde = sensorValues[0];
  uint16_t rechterSensorWaarde = sensorValues[2];

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

  if (sensorValues[2] > 400 && sensorValues[2] < 600)
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
  
}

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
  
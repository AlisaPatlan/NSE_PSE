#include "LijnSensor.h"

LineSensor::LineSensor(); {}

void LineSensor::initSensor(); 
  Serial.begin(9600);
  while (!Serial)
    ;  // Wait for serial port to connect

  lineSensors.initThreeSensors();


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
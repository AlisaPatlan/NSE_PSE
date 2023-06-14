#ifndef LINESENSOR_H
#define LINESENSOR_H
#define NUM_SENSORS 5//toegevoegd door Alisa, misschien verwijderen
#include <Wire.h>
#include <Zumo32U4.h>
#include "MotorsControler.h"
#include "Accelerometer.h"


class LineSensor{
  public:
    LineSensor();
    int leesWaarde();
    void initSensor();
    void leesKleurWaarde();
    bool bruinBeideGezien();
    void volgLijn();
    void calibrateSensors();
    void Helling();
    void rijdOpGroen();
   // void Helling();

private:
    Zumo32U4LineSensors lineSensors;
    MotorsControler motorControler;
    uint16_t rechterSensorWaarde;
    uint16_t linkerSensorWaarde;
    unsigned int lineSensorValues[NUM_SENSORS];
    uint16_t sensorValues[5];
    int16_t lastError;



};

#endif
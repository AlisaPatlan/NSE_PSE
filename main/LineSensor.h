#ifndef LINESENSOR_H
#define LINESENSOR_H
#define NUM_SENSORS 3//toegevoegd door Alisa, misschien verwijderen
#include <Wire.h>
#include <Zumo32U4.h>
#include "MotorsControler.h"
#include "Accelerometer.h"


class LineSensor{
  public:
    LineSensor();
    void leesWaarde();
    void initSensor();
    void leesKleurWaarde();
    bool bruinBeideGezien();
    void volgLijn();
    void calibrateSensors();

private:
    Zumo32U4LineSensors lineSensors;
    MotorsControler motorControler;
    uint16_t rechterSensorWaarde;
    uint16_t linkerSensorWaarde;
    unsigned int lineSensorValues[NUM_SENSORS];
    uint16_t sensorValues[3];
    int16_t lastError;



};

#endif
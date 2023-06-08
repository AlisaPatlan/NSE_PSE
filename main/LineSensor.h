#ifndef LijnSensor_H
#define LijnSensor_H
#include <Wire.h>
#include <Zumo32U4.h>
#include "MotorsControler.h"

class LineSensor{
  public:
    lineSensor();
    void leesWaarde();
    void initSensor();
    void leesKleurWaarde();
    void bruinBeideGezien();


private:
  Zumo32U4LineSensors lineSensors;
   MotorsControler motorControler ;
    uint16_t rechterSensorWaarde;
    uint16_t linkerSensorWaarde;



};
#ifndef LINESENSOR_H
#define LINESENSOR_H
#include <Wire.h>
#include <Zumo32U4.h>
#include "MotorsControler.h"

class LineSensor{
  public:
    LineSensor();
    void leesWaarde();
    void initSensor();
    void leesKleurWaarde();
    bool bruinBeideGezien();


private:
    Zumo32U4LineSensors lineSensors;
    MotorsControler motorControler ;
    uint16_t rechterSensorWaarde;
    uint16_t linkerSensorWaarde;



};

#endif
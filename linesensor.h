#include <Wire.h>
#include <Zumo32U4.h>

class linesensors(

public:
void setup();
void loop();
delay();

private:
  Zumo32U4LineSensors lineSensors;
    uint16_t lineSensorValues[3];
    Zumo32U4Motors motors;

)
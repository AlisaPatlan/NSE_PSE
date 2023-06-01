#include "Accelerometer.h"
#include "Motor.h"

Accelerometer accel;
Motor motor;

void setup()
{
  accel.initSensor();
}

void loop()
{
  accel.leesSensor();
  motor.zetAan();
}

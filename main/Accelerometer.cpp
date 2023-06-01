 #include "Accelerometer.h"
 
 Accelerometer::Accelerometer() {}

 void Accelerometer::initSensor() {
   Serial.begin(9600);
  // initialisatie 
  Wire.begin();
  imu.init();
  imu.enableDefault();
  imu.configureForFaceUphill();
 }

void Accelerometer::leesSensor() {
  buttonA.waitForPress(); //Als er op button A wordt geklikt dan begint de sensor leeswaardes uit te geven

  imu.readAcc();
  int16_t x = imu.a.x;
  int16_t y = imu.a.y;
  int32_t magnitudeSquared = (int32_t)x * x + (int32_t)y * y;



 int32_t inclineThreshold = 1427 * 1427;

 bool onIncline = magnitudeSquared > inclineThreshold;

//Als de waarde groter is dan 1000 dan staat de robot op een helling
 if (x > 1000) {
   Serial.println("Robot is on an incline");
 } else {
   Serial.println("Robot is not on an incline");
 }
  Serial.print("X: "); Serial.print(x);
  Serial.print(" | Y: "); Serial.print(y);
 

}
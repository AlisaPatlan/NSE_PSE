 #include "Accelerometer.h"
 
 Accelerometer::Accelerometer() {}

 void Accelerometer::initSensor() {
  // initialisatie 
  Wire.begin();
  imu.init();
  imu.enableDefault();
  imu.configureForFaceUphill();
 }
int Accelerometer::leesSensor() {
  //buttonA.waitForPress(); //Als er op button A wordt geklikt dan begint de sensor leeswaardes uit te geven

  imu.readAcc();
  int16_t xWaarde = imu.a.x;
  int16_t yWaarde = imu.a.y;
  int32_t magnitudeSquared = (int32_t)xWaarde * xWaarde + (int32_t)yWaarde * yWaarde;



 int32_t inclineThreshold = 1427 * 1427;

 bool onIncline = magnitudeSquared > inclineThreshold;

//Als de waarde groter is dan 1000 dan staat de robot op een helling
 if (xWaarde > 1000) {
   Serial.println("Robot is on an incline");
   
 } else {
   Serial.println("Robot is not on an incline");

 }
  return xWaarde;
  Serial.print("X: "); Serial.print(xWaarde);
  Serial.print(" | Y: "); Serial.print(yWaarde);
}
 

 #include "Accelerometer.h"
 
 Accelerometer::Accelerometer() {
   /*! Constructor van de Class Accelerometer
   */
 }

 void Accelerometer::initSensor() {
  /*! Initialisatie van de sensor van Accelerometer
  *   Deze methose maakt gebruik van standard libraries en functies van Pololu
  */
  Wire.begin();
  imu.init();
  imu.enableDefault();
  imu.configureForFaceUphill();
 }
int Accelerometer::leesSensor() {
  /*! Methode leesSensor leest aswaardes x en y af. Dat bepaalt wat voor hoek de helling heeft waat ZUMO32U4 op staat.
  *   Er wordt bepaald op de ZUMO32U4 op een incline staat of niet. 
  *   Daarvoor is er een Threshold berekend om 
  */

  //buttonC.waitForPress(); //Als er op button C wordt geklikt dan begint de sensor leeswaardes uit te geven

  imu.readAcc();
  int16_t xWaarde = imu.a.x;      //xWaarde wordt aan de hand van kanteling op x-as bepaald
  int16_t yWaarde = imu.a.y;      //yWaarde wordt aan de hand van kanteling op y-as bepaald
  int32_t magnitudeSquared = (int32_t)xWaarde * xWaarde + (int32_t)yWaarde * yWaarde;    //sommatie van de kwadraten van xWaarde en yWaarde


int inclineThreshold = 0;         //de Threshold voor de incline is 0 bij initialisatie
 inclineThreshold = 1427 * 1427;  // een bepaalde waarde dat met een trial en error methode bepaald is om threshold te bepalen

 bool onIncline = magnitudeSquared > inclineThreshold;    //als de magnitudeSquared groter is dan de Threshold krijgt variabel onIncline (op heuvel) TRUE waarde 


 if (xWaarde > 1000) {              //Als de waarde groter is dan 1000 dan staat de robot op een helling


   Serial.println("Robot is on an incline");  //Seriële uitvoer geeft aan dat Robot op de Incline staat
   
 } else {
   Serial.println("Robot is not on an incline");//Seriële uitvoer geeft aan dat Robot (ZUMO32U4) NIET op een helling staat.

 }
  return xWaarde;
  Serial.print("X: "); Serial.print(xWaarde);    //xWaarde wordt op het scherm geprint
  Serial.print(" | Y: "); Serial.print(yWaarde); //yWaarde wordt op het scherm geprint
}
 

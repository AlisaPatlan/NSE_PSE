#include "autonoom.h"

autonoom::autonoom(){
  Serial1.begin(9600);
}

Void autonoom::initSensor(){
Wire.begin();
  imu.init();
  imu.enableDefault();
  imu.configureForFaceUphill();
}


int autonoom::leesSensor() {
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

void autonoom::startRijden(int links, int rechts){
  rechterSnelheid = rechts;
  linkerSnelheid = links;
  motors.setSpeeds(linkerSnelheid, rechterSnelheid);
}

void autonoom::stopRijden(){
  rechterSnelheid = 0;
  linkerSnelheid = 0;
  
  motors.setSpeeds(linkerSnelheid, rechterSnelheid);
}

void autonoom::startRijdenCirkel(int links, int rechts){

  toerenRechts = 0;
  toerenLinks = 0;
  motors.setSpeeds(links, rechts);
  toerenRechts = encoders.getCountsRight();
  toerenLinks = encoders.getCountsLeft();
  if ((toerenRechts = 3100) && (toerenLinks = 3100)){
    motors.setSpeeds(0,0);
  }

  void autonoom::InitSensors(){
  proxSensors.initThreeSensors();
  }
  
  bool autonoom::Obstakel(){
  motorcont.startRijden(150,0);
  proxSensors.read();
  if (proxSensors.countsFrontWithLeftLeds() >= 4  ||
      proxSensors.countsFrontWithRightLeds() >= 4) {
        motorcont.startRijden(400, 400);
        return true;
}
else {

  return false;
}

void autonoom::volgLijn() {


  // put your main code here, to run repeatedly:
  int16_t position = lineSensors.readLine(lineSensorValues);
  int16_t error = position - 2000;
   int16_t speedDifference = error / 1 + 6 * (error - lastError);
   lastError = error;
   int16_t leftSpeed = (int16_t)maxSpeed + speedDifference;
  int16_t rightSpeed = (int16_t)maxSpeed - speedDifference;
   leftSpeed = constrain(leftSpeed, 0, (int16_t)maxSpeed);
  rightSpeed = constrain(rightSpeed, 0, (int16_t)maxSpeed);

  motorControler.startRijden(150, 150);
}

void autonoom::calibrateSensors()
{
  lineSensors.initFiveSensors(); 


  // Wait 1 second and then begin automatic sensor calibration
  // by rotating in place to sweep the sensors over the line
  delay(1000);
  for(uint16_t i = 0; i < 120; i++)
  {
    if (i > 30 && i <= 90)
    {
      motorControler.startRijden(-200, 200);
    }
    else
    {
      motorControler.startRijden(200, -200);
    }

    lineSensors.calibrate();
  }
  motorControler.startRijden(0, 0);
}

void autonoom::leesWaarde() {
//leest de linesensors af en geeft aan welke kleur het is (gekoppeld met waardes)
if ((sensorValues[0] > 600 && sensorValues[0] < 1000) && (sensorValues[2] > 600 && sensorValues[2] < 1000)) {
    Serial.println("bruin");
  }

  else if ((sensorValues[0] > 400 && sensorValues[0] < 600) && (sensorValues[2] > 400 && sensorValues[2] < 600)) {
    Serial.println("grijs");
  }

  else if ((sensorValues[1] > 1000)) {
    Serial.println("zwart");
    motorControler.startRijden(200, 200);
    
  }

    else if ((sensorValues[0] > 200 && sensorValues[0] < 300) && (sensorValues[2] > 200 && sensorValues[2] < 300)) {
      Serial.println("groen");
      motorControler.startRijden(100,100);
    }
  }

void autonoom::leesKleurWaarde(){
  uint16_t xWaarde = 0 ;
  lineSensors.read(sensorValues);
  uint16_t linkerSensorWaarde = sensorValues[0];
  uint16_t rechterSensorWaarde = sensorValues[2];

  bool grijsLinksGezien = false; 
  bool grijsRechtsGezien = false;

  if (sensorValues[0] > 400 && sensorValues[0] < 600)
  {
    grijsLinksGezien = true;
  }
  if(grijsLinksGezien && grijsRechtsGezien != true){
    if (sensorValues[0] || sensorValues[2] > 1000){
        motorControler.startRijden(-150, 150);
        delay(500);
        motorControler.startRijden(150, 150);
        grijsLinksGezien = false;
      }
  }

  if (sensorValues[2] > 400 && sensorValues[2] < 600)
  {
    grijsRechtsGezien = true;
  }
  if(grijsRechtsGezien && grijsLinksGezien != true){
    if (sensorValues[0] > 1000 || sensorValues[2] > 1000) {
    motorControler.startRijden(150, -150);
    delay(500);
    motorControler.startRijden(150, 150);
    grijsRechtsGezien = false;
    }
  }
  
  
  if(grijsLinksGezien && grijsLinksGezien){
    if (xWaarde>0) 
      { 
        motorControler.stopRijden();
      }
      else if (xWaarde < 0){
        motorControler.startRijden(150, 150); 
        grijsLinksGezien = false; 
        grijsRechtsGezien = false;
      }
  }else{
    motorControler.startRijden(150,150);
  }
  
}

bool autonoom::bruinBeideGezien(){
  lineSensors.read(lineSensorValues);
  uint16_t linkerSensorWaarde = sensorValues[0];
  uint16_t rechterSensorWaarde = sensorValues[2];

  if (((sensorValues[0] > 600) && (sensorValues[0] < 1000))&&((sensorValues[0] > 600) && (sensorValues[0] < 1000)))
  {
    return true;
  }
  return false;
}

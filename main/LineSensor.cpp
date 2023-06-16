#include "LineSensor.h"
#include "Accelerometer.h"
#include <Wire.h>
#include <Zumo32U4.h> 

//unsigned int lineSensorValues[NUM_SENSORS];//toegevoegd door Alisa, misschien verwijderen

uint16_t sensorValues[5];
uint16_t lineSensorValues[5];
int16_t lastError = 0;          //toegevoegd door Alisa, misschien verwijderen
uint16_t maxSpeed = 400;

Zumo32U4LineSensors lineSensors;

LineSensor::LineSensor() {
/*! Class LineSensor
*initialisatie van de vijf sensoren van de front array van ZUMO32U4 en kalibratie daarvan. Deze methode maakt gebruik van de 
*methodes die beneden worden beschreven
*/
}

void LineSensor::initSensor(){
  /*!initSensor initieert de vijf sensoren van de front array van ZUMO
  */
  lineSensors.initFiveSensors();
  calibrateSensors();
}


void LineSensor::volgLijn() {
/*!
Met deze methode blijft ZUMO32U4 een lijn volgen. Het beste werkt met een zwarte lijn op witte achtergrond. 
* Om lijn te volgen maakt ZUMO32U4 gebruik van methode readLine van Pololu library. 
* ZUMO corrigeert de richting waar hij naartoe rijdt door steeds verschil tussen snelheden van rechter en linker motors aan te passen. 
*/
  int16_t positie = lineSensors.readLine(lineSensorValues);

  int16_t error = positie - 2000;
  int16_t speedDifference = error / 1 + 8 * (error - lastError);

  lastError = error;

  int16_t leftSpeed = (int16_t)maxSpeed + speedDifference;
  int16_t rightSpeed = (int16_t)maxSpeed - speedDifference;

  leftSpeed = constrain(leftSpeed, 0, (int16_t)maxSpeed);
  rightSpeed = constrain(rightSpeed, 0, (int16_t)maxSpeed);

  motorControler.startRijden(leftSpeed, rightSpeed);
}

void LineSensor::calibrateSensors()
{
/*!1 seconde wachten en beginnen met kalibreren
*  "swipen" over de vloer door op zijn as te roteren
*/
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


int LineSensor::leesWaarde() {
/*! Methode leesWaarde is nodig voornamelijk voor kalibreren voor hardcode. Wij hebben op het moment geen betere manier gevonden om kleuren aan waardes 
* te koppelen bij de ZUMO. 
*ZUMO herkent de waardes met zijn kleursensoren en geeft kleur aan via seriele uitvoer.
*Om de waardes te kalibreren moet de gebruiker ZUMO met zijn array van sensoren op strepen van verschillende kleur zetten
* en letten op de waardes die op de seriele uitvoer getoond worden. Er is een range aan waardes die bij een kleur gedetecteerd worden, er moeten de grenswaardes voor genomen worden.
*/
lineSensors.read(sensorValues);
/*!Hiermee leest ZUMO bruin af. 
*/

if ((sensorValues[0] > 500 && sensorValues[0] < 999) && (sensorValues[4] > 500 && sensorValues[4] < 999)) {
    Serial.println("bruin");                
    return 1;
  }
/*!Hiermee leest ZUMO grijs af. 
*/
  else if ((sensorValues[0] > 400 && sensorValues[0] < 499) && (sensorValues[4] > 400 && sensorValues[4] < 499)) {
    Serial.println("grijs");
    return 2;

  }
/*!Hiermee leest ZUMO groen af. 
*/    
    else if ((sensorValues[0] > 300 && sensorValues[0] < 399) && (sensorValues[4] > 300 && sensorValues[4] < 399)) {
      Serial.println("groen");
      return 3;
    }
/*!Hiermee leest ZUMO zwart af. 
*/
  else if ((sensorValues[5] > 1000)) {
    Serial.println("zwart");
    return 5;
  }

}


void LineSensor::leesKleurWaarde(){
/*! Zumo leest kleur waardes door de juiste sensoren van de array te gebruiken. Dan worden de variabelen can status veranderd (false -> true)
*
*
*/

  uint16_t xWaarde = 0 ; //waarde van de helling

  lineSensors.read(sensorValues); //aflezen van de waardes door de lijnsensor
  uint16_t linkerSensorWaarde = sensorValues[0];
  uint16_t rechterSensorWaarde = sensorValues[5];

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

  if (sensorValues[5] > 400 && sensorValues[5] < 600)
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
}

  void LineSensor::Helling(){
    uint16_t xWaarde = 0 ;
  lineSensors.read(sensorValues);
  uint16_t linkerSensorWaarde = sensorValues[0];
  uint16_t rechterSensorWaarde = sensorValues[5];
    bool grijsLinksGezien = false; 
  bool grijsRechtsGezien = false;

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

bool LineSensor::bruinBeideGezien(){
  lineSensors.read(lineSensorValues);
  uint16_t linkerSensorWaarde = sensorValues[0];
  uint16_t rechterSensorWaarde = sensorValues[4];

  if (((linkerSensorWaarde > 500) && (linkerSensorWaarde < 999))&&((rechterSensorWaarde > 500) && (rechterSensorWaarde < 999)))
  {
    return true;
  }
  return false;
}


  
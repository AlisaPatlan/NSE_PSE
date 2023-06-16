#include "MotorsControler.h"
#include "Accelerometer.h"
#include <Zumo32U4.h>


Zumo32U4Motors motors;
Zumo32U4Encoders encoders;

using namespace std;



MotorsControler::MotorsControler(): rechterSnelheid(0), linkerSnelheid(0){
/*! Constructor voor MotorControler: de linker en rechter motors hebben aparte waardes voor snelheid
*/  
}


void MotorsControler::startRijden(int links, int rechts){

/*! Methode start rijden krijgt de integer waardes voor linker en rechter motor mee om te rijden.
*   Daarna worden de snelheden bij de motors toegekend via methode setSpeeds uit libraries van Pololu
*/  
  rechterSnelheid = rechts;
  linkerSnelheid = links;
  motors.setSpeeds(linkerSnelheid, rechterSnelheid);
}

void MotorsControler::stopRijden(){
  /*! stopRijden zorgt ervoor dat ZUMO stopt met rijden: snelheid van beiden motoren wordt op 0 gezet.
  */

  rechterSnelheid = 0;
  linkerSnelheid = 0;
  
  motors.setSpeeds(linkerSnelheid, rechterSnelheid);
}

void MotorsControler::startRijdenCirkel(int links, int rechts){
  /*! startRijden Cirkel wordt geïmplementeerd aan het einde van de parcours als ZUMO een bruine lijn bereikt. 
  *  ZUMO rijdt circa 30 cm vooruit door encoders te laten checken hoeveel toeren de motoren gemaakt hebben.
  *  Als de aantal toeren 3100 bereikt, stopt de ZUMO en gaat naar volgende stap van de code, beschreven in proxSensor.Obstakel
  */

  toerenRechts = 0;
  toerenLinks = 0;
  motors.setSpeeds(links, rechts);
  toerenRechts = encoders.getCountsRight();
  toerenLinks = encoders.getCountsLeft();
  if ((toerenRechts = 3100) && (toerenLinks = 3100)){
    motors.setSpeeds(0,0);
  }

}


  
 
    

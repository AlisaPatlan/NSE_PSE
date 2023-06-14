#include "MotorsControler.h"
#include "Accelerometer.h"
#include <Zumo32U4.h>
#include "LineSensor.h"


Zumo32U4Motors motors;
Zumo32U4Encoders encoders;
LineSensor lineSensors;

using namespace std;

MotorsControler::MotorsControler(): rechterSnelheid(0), linkerSnelheid(0){}

void MotorsControler::startRijden(int links, int rechts){
  rechterSnelheid = rechts;
  linkerSnelheid = links;
  motors.setSpeeds(linkerSnelheid, rechterSnelheid);
}

void MotorsControler::stopRijden(){
  rechterSnelheid = 0;
  linkerSnelheid = 0;
  
  motors.setSpeeds(linkerSnelheid, rechterSnelheid);
}

void MotorsControler::startRijdenCirkel(int links, int rechts){

  toerenRechts = 0;
  toerenLinks = 0;
  motors.setSpeeds(links, rechts);
  toerenRechts = encoders.getCountsRight();
  toerenLinks = encoders.getCountsLeft();
  if ((toerenRechts = 3100) && (toerenLinks = 3100)){
    motors.setSpeeds(0,0);
  }
}
  void MotorsControler::rijdOpGroen(){

  while (lineSensors.leesWaarde()==3){
    motors.setSpeeds(100,100);
  }
}



  
 
    

#include "MotorsControler.h"
#include <Zumo32U4.h>


Zumo32U4Motors motors;

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
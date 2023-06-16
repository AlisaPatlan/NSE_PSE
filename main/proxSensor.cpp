#include "proxSensor.h"

Zumo32U4ProximitySensors proxSensors;



proxSensor::proxSensor(){
/*! Constructor voor proxSensor
*/  
}

void proxSensor::InitSensors(){
/*! Initialisatie van de proximity sensoren
*/
  proxSensors.initThreeSensors();
}

bool proxSensor::Obstakel(){

/*! Methode proxSensor.Obstakel wordt geïmplementeerd aan het einde van de parcours als ZUMO een bruine lijn bereikt heeft
*   en als hij in het midden van de cirkel staat. 
*   ZUMO32U4 draait om zijn as en scant naar een object met proximitySensoren. 
*   Als ZUMO32U4 een obstakel detecteert, rijdt hij naar het object toe
*/
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


}

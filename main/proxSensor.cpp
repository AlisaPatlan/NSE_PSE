#include "proxSensor.h"

Zumo32U4ProximitySensors proxSensors;



proxSensor::proxSensor(){
}

void proxSensor::InitSensors(){
  proxSensors.initThreeSensors();
}
bool proxSensor::Obstakel(){
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

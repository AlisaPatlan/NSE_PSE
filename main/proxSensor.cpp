#include "proxSensor.h"

Zumo32U4ProximitySensors proxSensors;


proxSensor::proxSensor(){
  proxSensors.InitThreeSensors();
}

bool proxSensor::Obstakel(){
  motorcont.StartRijden(150,0);
  proxSensors.read();
  if (proxSensors.countsFrontWithLeftLeds() >= 4  ||
      proxSensors.countsFrontWithRightLeds() >= 4) {
        motorcont.StartRijden(400, 400);
        return true;
}
else {

  return false;
}

}

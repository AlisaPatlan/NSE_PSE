#include "MotorsControler.h"
#include "LijnSensor.h"
#include "accMeter.h"
#include "xBee.h"
#include "proxSensor.h"

using namespace std;
MotorsControler ZumoMotor;
LijnSensor lijnenSensor;
accMeter acceleroMeter;
xBee xBeeConnectie;
proxSensor ProxiSensor;

void setup()
{
  Serial.begin(9000);
}

void loop()
{
  // Vooruit rijden
  ZumoMotor.startRijden(100,100);
  delay(2000);
  
  // Achteruit rijden
  ZumoMotor.startRijden(-100,-100);
  delay(2000);
  
  // Links draaien
  ZumoMotor.startRijden(-100,100);
  delay(1000);
  
  // Rechtsaf draaien
  ZumoMotor.startRijden(100,-100);
  delay(1000);
  
  // Stoppen
  ZumoMotor.stopRijden();
  delay(2000);
}

#include <Wire.h>
#include <Zumo32U4.h>

Zumo32U4LineSensors lineSensors;
uint16_t lineSensorValues[3];
Zumo32U4Motors motors;

void setup()
{
  Serial.begin(9600);
  while (!Serial); // Wait for serial port to connect

  lineSensors.initThreeSensors();
}

void loop()
{
  motors.setSpeeds(100, 100); // rijden

  uint16_t sensorValues[3];
  lineSensors.read(sensorValues);
  
// leest alle linesensors
  Serial.print(sensorValues[0]);
  Serial.print('\t');
  Serial.print(sensorValues[1]);
  Serial.print('\t');
  Serial.println(sensorValues[2]);

//leest de linesensors af en geeft aan welke kleur het is (gekoppeld met waardes)
  if( (sensorValues[0] > 600 && sensorValues[0] < 1000 ) &&   (sensorValues[2] > 600 && sensorValues[2] < 1000 ))  {
    Serial.println("bruin");
  }

  else if( (sensorValues[0] > 400 && sensorValues[0] < 600) &&   (sensorValues[2] > 400 && sensorValues[2] < 600))  {
    Serial.println("grijs");
  }

  else if( (sensorValues[0] > 1000) &&   (sensorValues[2] > 1000 ))  {
    Serial.println("zwart");

  else if( (sensorValues[0] > 200 && sensorValues[0] < 300 ) &&   (sensorValues[2] > 200 && sensorValues[2] < 300 ))  {
    Serial.println("groen");
  }
}

 // delay(1000);

// alle kleuren:
 /* grijs = 400 - 600
    groen = 200 - 220
    rood/wit= 180 ong
    bruin = 600 - 1000
    zwart = boven 1000 */ 

/*! @mainpage voor Project Systems Engineering ZUMO 32U4 groep 2.3*/

/*!
  @file main.ino
  @date 16 juni 2023
  @author Ilayda Alan, Israa Bensaga, Phaedra Hoving, Arjan Laurens Kuiper, Alisa Patlan

  Handmatige en autonome besturing van ZUMO32U4. 
*/


/* PSE NSE groep 2.3
*Aansturing van ZUMO32U4
*Handbediening en autonome modus voor het afleggen van een parcours worden gewisseld door het drukken op knoppen A en B
*Deze code is geschreven door projectleden van groep 2.3 can HBO-ICT NSE van de Haagse Hogeschool
*Auteur: Ilayda Alan, Israa Bensaga, Phaedra Hoving, Arjan Laurens Kuiper en Alisa Patlan
*16 juni 2023
*/

#include "MotorsControler.h"
#include "LineSensor.h"
#include "xBee.h"
#include "proxSensor.h"
#include "Accelerometer.h"
#include <Wire.h>

using namespace std;

MotorsControler ZumoMotor;
LineSensor LineSensors;
Accelerometer accMeter;
ZumoRobot zumo;
proxSensor proxSensor;
Zumo32U4ButtonA buttonA;
Zumo32U4ButtonB buttonB;
/*! ZUMO32U4 werkt in automatische modus als er op knop A fedrukt wordt 
*en kan via xBee aangestuurd worden als er op knop B gedrukt wordt.
*De boolean knopGedrukt wordt daarom aan het begin op false gezet.
*/

String gedrukteKnop = "";
bool knopGedrukt = false;


void setup()
{
/*! In de setup worden de Lijnsensoren LineSensors en seriele output geïnitialiseerd. 
*/

  Serial1.begin(9000); 
  LineSensors.initSensor(); //initiatie van de Linesensors
  
  do{
  if(buttonA.isPressed()){  //if statement voor als er op knop A gedrukt wordt
    gedrukteKnop = "a";
    knopGedrukt = true;
  }
  if(buttonB.isPressed()){
    gedrukteKnop = "b";
    knopGedrukt = true;
  }
  } while (!knopGedrukt);

}

void loop()
{

  if(gedrukteKnop == "a"){    //als de knop A gedrukt wordt moet ZUMO zijn sensoren gebruiken om de lijn te volgen.  
    LineSensors.volgLijn();   //Daarvoor gebruikt hij methodes uit LineSensor class. 
    LineSensors.leesKleurWaarde();
    LineSensors.Helling();


    bool bruineLijn = false;
    
    bruineLijn = LineSensors.bruinBeideGezien();
    if (bruineLijn)
    {
      ZumoMotor.startRijdenCirkel(200, 200);
      proxSensor.Obstakel();
    }
    
  }

  if(gedrukteKnop == "b"){
    zumo.handleCommands();
  }
}


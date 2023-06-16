#include "xBee.h"

ZumoRobot::ZumoRobot() {

  /*! Set-up voor seriële communicatie met xBee
  */
  Serial1.begin(9600);
}

void ZumoRobot::handleCommands() {
/*! In het geval dat er een seriële imput vanuit de grbeuiker komt, volgt ZUMO32U4 verschillende commando's
*   In deze code is er gebruik gemaakt van switch cases: er wordt gekeken naar de input en aan de hand daarvan wordt er gekozen welke actie ZUMO32U4 onderneemt.
*   Het is mogelijk om hetzelfde resultaat te bereiken met if-statements, maar dan moet de programma elke keer door alle if-statements heen, en dat kan een vertraging veroorzaken
*/

  if (Serial1.available()) {
    char command = Serial1.read();
    Serial1.write(command);
    switch (command) {
      case 'W': 
      /* W en "enter": vooruit
      */
        motors.setSpeeds(200, 200); // Snelheid wordt aanhepast
        break;

      case 'S': 
      /* S en "enter": Achteruit
      */
        motors.setSpeeds(-200, -200); // Snelheid wordt aanhepast
        break;

      case 'A': 
      /* A en "enter": draai linksom
      */
        motors.setSpeeds(-200, 200);  // Snelheid wordt aanhepast
        break;

      case 'D':
       /* D en "enter": draai rechtssom
      */
        motors.setSpeeds(200, -200); // Snelheid wordt aanhepast
        break;

      case 'X':
      /* X en "enter": stop
      */ 
        motors.setSpeeds(0, 0); // Snelheid wordt aanhepast
        break;
    }
  }
}

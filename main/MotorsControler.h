#ifndef MOTORSCONTROLER_H
#define MOTORSCONTROLER_H
#include <Zumo32U4.h>
/*! Header-file van de MotorsControler bevat alle attributten en methodes van class MotorControler.
*Dit zijn de functionaliteiten die motor aansturen. 
* De methodes worden in de MotorsControler.cpp file geïmplementeerd. Deze class maakt gebruik van de standart library van Pololu.
*/


class MotorsControler{
  

  public:
    MotorsControler();
    void startRijden(int,int);
    void stopRijden();
    void startRijdenCirkel(int, int);
    

  private:
    int linkerSnelheid;
    int rechterSnelheid;
    int toerenRechts;
    int toerenLinks;
};



#endif
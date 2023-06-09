#ifndef MOTORSCONTROLER_H
#define MOTORSCONTROLER_H
#include <Zumo32U4.h>

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
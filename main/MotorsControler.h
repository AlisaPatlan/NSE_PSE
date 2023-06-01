#include <Zumo32U4.h>

class MotorsControler{

  public:
    MotorsControler::MotorsControler();
    void startRijden(int,int);
    void stopRijden();

  private:
    int linkerSnelheid;
    int rechterSnelheid;
};
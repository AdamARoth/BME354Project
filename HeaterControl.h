/* Header Library for Safety Control of the Heater and LCD display.
Created by KAAT
*/

#ifndef HeaterControl_h;
#define HeaterControl_h

#include "Arduino.h"

class HeaterControl
{
  #define heaterPin 2

  public:
    HeaterControl(double, double, int,int);
    void heaterSafety(double, double, int, int);
    //void displayTemp(double, int);

  private:
};

#endif

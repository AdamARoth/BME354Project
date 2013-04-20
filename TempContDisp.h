/* Header Library to Control the Heater and display it to the LCD screen.
Created by KAAT
*/

#ifndef TempContDisp_h;
#define TempContDisp_h

#include "Arduino.h"

class TempContDisp
{
  public:
    #define warnPoint 146
    #define maxPoint 280
    #define heaterPin 2    
    float curTemp;
    
    TempContDisp(int, int, float);
    void heatControl(int,int);
    void displayTemp(float,int);

  private:
    int _val;
};

#endif

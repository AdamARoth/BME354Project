
/* CPP Library for Safety Control of the Heater and LCD display.
 Crated by Tyler Hobbs, Adam Roth, Kavitha Prasanna, Alexa Choy
*/
#include "Arduino.h"
#include "HeaterControl.h"
#include "LiquidCrystal.h"
extern LiquidCrystal lcd;

HeaterControl::HeaterControl(double currTemp,double setTempPoint,int warnPoint,int maxPoint)
{
}

void HeaterControl::heaterSafety(double currTemp, double setTempPoint,int warnPoint, int maxPoint)
{
  if (currTemp >= warnPoint && currTemp < maxPoint)
  {
    lcd.clear();
    lcd.setCursor(4,0);
    lcd.print("WARNING!");  
    lcd.setCursor(3,1);
    lcd.print("TEMP HIGH!");
    delay(2000);
  }
  else if (currTemp >= maxPoint)
  {
    digitalWrite(heaterPin,LOW);
    lcd.clear();
    lcd.setCursor(2,0);
    lcd.print("HEATER OFF!");
    lcd.setCursor(1,1);
    lcd.print("TEMP TOO HIGH!");
    delay(2000);
  }
}

//void HeaterControl::displayTemp(double curTemp, int setPoint)
//{
//  lcd.clear();
//  lcd.setCursor(0,0);
//  lcd.print("Cur Temp: ");
//  lcd.print(curTemp);
//  lcd.print(" C");
//  lcd.setCursor(0,1);
//  lcd.print("Set Temp: ");
//  lcd.print(setPoint);
//  lcd.print(" C");
//}

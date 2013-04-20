/* Library to Control the Heater and display it to the LCD screen.
 Crated by Tyler Hobbs, Adam Roth, Kavitha Prasanna, Alexa Choy
*/
#include "Arduino.h"
#include "TempContDisp.h"
#include "LiquidCrystal.h"
extern LiquidCrystal lcd;

TempContDisp::TempContDisp(int sensePin,int setPoint,float curTemp)
{
}

void TempContDisp::heatControl(int sensePin,int setPoint)
{
  _val=analogRead(sensePin);
  curTemp = _val * 0.00489 / 0.005;
  if (curTemp >= warnPoint && curTemp < maxPoint)
  {
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("WARNING!");  
    lcd.setCursor(0,1);
    lcd.print("TEMP TOO HIGH!");
  }
  else if (curTemp >= maxPoint)
  {
    digitalWrite(heaterPin,LOW);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("HEATER OFF!");
    lcd.setCursor(0,1);
    lcd.print("TEMP TOO HIGH!");
    delay(2000);
  }
  if (curTemp < setPoint)
  {
    digitalWrite(heaterPin, HIGH);
  }
  else
  {
    digitalWrite(heaterPin, LOW); 
  }
  displayTemp(curTemp,setPoint);
  delay(2000);
}

void TempContDisp::displayTemp(float curTemp, int setPoint)
{
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Cur Temp: ");
  lcd.print(curTemp);
  lcd.print(" C");
  lcd.setCursor(0,1);
  lcd.print("Set Temp: ");
  lcd.print(setPoint);
  lcd.print(" C");
}

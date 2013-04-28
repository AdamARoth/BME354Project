/* Library to Control the PID and turn on/off the heater
 Crated by Tyler Hobbs, Adam Roth, Kavitha Prasanna, Alexa Choy
*/
#include "Arduino.h"
#include "PIDControl.h"
#include "LiquidCrystal.h"
#include "PID_v1.h"
extern LiquidCrystal lcd;
extern PID myPID;

PIDControl::PIDControl(double setTempPoint, double setTimePoint, double currTemp, double Output, int kp, int ki, int kd, unsigned long windowStartTime,int tempPt1,int tempPt2,int tempPt3,int timePt1, int timePt2, int timePt3)
{
}

void PIDControl::optionsPID(int setTimePoint)
{
  //tell the PID to range between 0 and the full window size
  myPID.SetOutputLimits(0, setTimePoint);

  //turn the PID on
  myPID.SetMode(AUTOMATIC); 
}

void PIDControl::reflowPID(double setTempPoint, double setTimePoint, double Output, unsigned long windowStartTime, int kp, int ki, int kd)
{
  _val=analogRead(sensePin);
  currTemp = _val * 0.00489 / 0.005;	//Converting the voltage of sensePin to current temp.
 
  displayTemp(currTemp,setTempPoint);
 
  myPID.Compute();

  _now = millis();
  if(_now - windowStartTime > setTimePoint)
  { //time to shift the Reflow Window
    windowStartTime += setTimePoint;
  }
  if (Output > _now - windowStartTime)
  {
	digitalWrite(heaterPin,HIGH);
  }
  else digitalWrite(heaterPin,LOW);
}

double PIDControl::setReflowCurve(int tempPt1,int tempPt2,int tempPt3,int timePt1, int timePt2, int timePt3, double setTempPoint, double setTimePoint,unsigned long windowStartTime)
{
  if((double) _now < (double) timePt1)
  {
    setTempPoint = (((double) tempPt1-20)/((double) timePt1 - (double) windowStartTime))*((double) _now) + 20;
    setTimePoint = (double) timePt1;
    return setTempPoint;
  }
  else if(((double) _now >= (double) timePt1) && ((double) _now <= (double) timePt2))
  {
    setTempPoint = (((double) tempPt2-(double) tempPt1)/((double) timePt2-(double) timePt1))*((double) _now) + (double) tempPt1;
    setTimePoint = (double) timePt2;
  }
  else if(((double) _now >= (double) timePt2) && ((double) _now <= (double) timePt3))
  {
    setTempPoint = (((double) tempPt3-(double) tempPt2)/((double) timePt3-(double) timePt2))*((double) _now)+ (double) tempPt2;
    setTimePoint = (double) timePt3;
  }
  else
  {
  }
}
void PIDControl::displayTemp(double currTemp, double setTempPoint)
{
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Cur Temp: ");
  lcd.print(currTemp);
  lcd.print(" C");
  lcd.setCursor(0,1);
  lcd.print("Set Temp: ");
  lcd.print(setTempPoint);
  lcd.print(" C");
  delay(2000);
}

/* Library to Control the PID and turn on/off the heater
 Crated by Tyler Hobbs, Adam Roth, Kavitha Prasanna, Alexa Choy
*/
#include "Arduino.h"
#include "PIDControl.h"
#include "LiquidCrystal.h"
#include "PID_v1.h"
extern LiquidCrystal lcd;
extern PID myPID;

PIDControl::PIDControl(double setTempPoint, float setTimePoint, double currTemp, double Output, int kp, int ki, int kd, unsigned long windowStartTime,int tempPt1,int tempPt2,int tempPt3,int timePt1, int timePt2, int timePt3)
{
}

void PIDControl::optionsPID(int setTimePoint)
{
  //tell the PID to range between 0 and the full window size
  myPID.SetOutputLimits(0, setTimePoint);

  //turn the PID on
  myPID.SetMode(AUTOMATIC); 
}

void PIDControl::reflowPID(double setTempPoint, float setTimePoint, double Output, unsigned long windowStartTime, int kp, int ki, int kd)
{
  _val=analogRead(sensePin);
  currTemp = _val * 0.00489 / 0.005;  //Converting the voltage of sensePin to current temp.
 
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

void PIDControl::setReflowCurve(int tempPt1,int tempPt2,int tempPt3,int timePt1, int timePt2, int timePt3, double setTempPoint, double setTimePoint,unsigned long windowStartTime)
{
  if(_now < timePt1)
  {
    setTempPoint = (((double) tempPt1-20)/(timePt1-windowStartTime))*(_now) + 20;
    setTimePoint = (double) timePt1;
  }
  else if((_now >= timePt1) && (_now <= timePt2))
  {
    setTempPoint = ((tempPt2-tempPt1)/(timePt2-timePt1))*(_now) + tempPt1;
    setTimePoint = (double) timePt2;
  }
  else if((_now >= timePt2) && (_now <= timePt3))
  {
    setTempPoint = ((tempPt3-tempPt2)/(timePt3-timePt2))*(_now)+ tempPt2;
    setTimePoint = (double) timePt3;
  }
  else
  {
    return;
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

void optionsPID()  //set the options for the PID
{
  //tell the PID to range between 0 and the full window size
  myPID.SetOutputLimits(0, setTime);
  //turn the PID on
  myPID.SetMode(AUTOMATIC);
}

void runPID()
{
  val=analogRead(sensePin);
  currTemp = val * 0.00489 / 0.005;  //Converting the voltage of sensePin to current temp.
  
  if((int)currTemp > maxPk)             //Set the MaxPeak of the temperature
  {
    maxPk = (int)currTemp;
  }

  //Record run into EEPROM for later loading into computer
  if(elapsedTime > (((memIndex-1)/2 - 3)*5) && memIndex+1 <= 255)
  {
    EEPROM.write(memIndex,(byte) setTemp);
    EEPROM.write(memIndex+1,(byte) currTemp);
    memIndex = memIndex+2;
  }


  double gap = abs(setTemp-currTemp);   //distance away from setpoint
  if(gap<10)
  {  //we're close to setpoint, use conservative tuning parameters
    myPID.SetTunings(consKp, consKi, consKd);
  }
  else
  {  //we're far from setpoint, use aggressive tuning parameters
    myPID.SetTunings(aggKp, aggKi, aggKd);
  }

  myPID.Compute();    //recalculate the PID output

  now = millis();     //redefine the NOW time

  if((now - windowStartTime)/1000 > setTime)    //For a new stage, shift the window time
  { //time to shift the Reflow Window
    windowStartTime = now;
  }

  if (PIDOutput > (now - windowStartTime)/1000)  //Turn the heater ON if the PID output is greater than the stage relative current time.
  {
    digitalWrite(heaterPin,HIGH);
  }
  else digitalWrite(heaterPin,LOW);  //Turn heater off if PID output is low
}

void endREFLOW()  // Begins the End Reflow function sequence
{
  if (elapsedTime > (timePt3 + 20))
  {
    digitalWrite(heaterPin,LOW);    // Turn heater off when ending
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("CurT: ");
    lcd.print((int) currTemp);
    lcd.print("C");
    lcd.setCursor(0,1);
    lcd.print("REFLOW COMPLETE");
    delay(3000);

    exitREFLOW();    // Exit the Reflow Mode
  }
}

void exitREFLOW()    // Begins the EXIT Reflow sequence
{
  digitalWrite(heaterPin,LOW);    // Turn heater off when exiting
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Exiting Reflow");
  delay(3000);
  reflowMode = false;
  elapsedTime = 0;       //Set the Time variables used in PID to 0. 
  startTime = 0;
  windowStartTime = 0;
  now = 0;
  memIndex = 7;
}

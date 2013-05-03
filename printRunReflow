void printRunReflow()      // Display the Reflow data (Current temp, Set temp, Stage, and Timer) to the LCD
{
  lcd.clear();
  lcd.setCursor(0,0);
  String output = "";
  output.concat("CurT: ");
  if(currTemp < 100)
  {
    output.concat(" ");
  }
  output.concat((int) currTemp);      // Display the current Temperature to the LCD
  output.concat("C");
  output.concat(" ");
  output.concat(timerDisplay());      // Display the timer function output to the LCD
  lcd.print(output);                  // Print the first line (Current temperature and timer) to LCD.

  lcd.setCursor(0,1);
  String output2 = "";
  output2.concat("SetT: ");      // Display the set Temperature and reflow stage number 
  if(elapsedTime < (double) timePt1)  // 1st STAGE - RAMP TO SOAK
  {
    output2.concat(tempPt1);
    output2.concat("C");
    output2.concat("   S1");
  }
  else if((elapsedTime >= (double) timePt1) && (elapsedTime <= (double) timePt2))    // 2nd STAGE - SOAK
  {
    output2.concat(tempPt2);
    output2.concat("C");
    output2.concat("   S2");
  }
  else if((elapsedTime >= (double) timePt2) && (elapsedTime <= (double) timePt3))    // 3rd STAGE - RAMP TO PEAK
  {
    output2.concat(tempPt3);
    output2.concat("C");
    if (currTemp < 218)
    {
    output2.concat("   S3");  // 3rd STAGE - RAMP TO PEAK
    }
    else
    {
     output2.concat(" RFLW");  // REFLOW STAGE
    }
  }
  else if((elapsedTime >= (double) timePt3) && (elapsedTime <= (double) timePt3+20)) // COOL DOWN STAGE
  {
    output2.concat("COOL DOWN");
  }
  lcd.print(output2);    // Print the second line (set Temperature to the LCD)
  delay(500);
}


String timerDisplay()  // Create the Reflow Timer
{ 
  String timerOutput = "";
  int time = (timePt3+20)-(int) elapsedTime;
  int timeMin = time/60;
  int timeSec = time%60;
  //Add zero to single digit of min
  if(timeMin < 10)
  {
    timerOutput.concat("0"); 
  }
  timerOutput.concat(timeMin);
  timerOutput.concat(":");
  //Add zero to single digit of sec
  if(timeSec < 10)
  {
    timerOutput.concat("0");
  }
  timerOutput.concat(timeSec);
  return timerOutput;
}

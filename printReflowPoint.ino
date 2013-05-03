void printReflowPoint(int dataSet,int time, int temp, int change)   // Display the Reflow points being set by the user in Set Reflow Mode
{  
  String output = "";
  lcd.setCursor(0,0);
  output.concat("Time Pt ");
  output.concat(dataSet);
  output.concat(" ");
  if(change == 0) //0 refers to time
  {
    output.concat("*"); // Prints * next to the variable being changed (0 if time, 1 if temp )
  }
  int timeMin = time/60; //converts the number of seconds inputted to minutes
  int timeSec = time%60; //takes the remainder of the division and set that equal to seconds
  if(timeMin < 10)  
  {
    output.concat("0");  //Add zero to single digit of min
  }
  output.concat(timeMin);
  output.concat(":");
  if(timeSec < 10)   
  {
    output.concat("0"); //Add zero to single digit of sec
  }
  output.concat(timeSec);
  lcd.print(output);
  lcd.setCursor(0,1);
  String output2 = "";
  output2.concat("Temp Pt ");
  output2.concat(dataSet);
  output2.concat(" ");
  if(change == 1) //1 refers to temperature
  {
    output2.concat("*"); // Prints * next to the variable being changed (0 if time, 1 if temp )
  }
  output2.concat(temp);
  output2.concat(" C ");
  lcd.print(output2);
}

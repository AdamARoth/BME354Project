void setReflowPoints()
{
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Entering");
  lcd.setCursor(0,1);
  lcd.print("Set Mode");
  delay(1000);  // Done to avoid entering select case too quickly (avoid double press)
  lcd.clear();
  boolean select = true;//Variable to keep 
  int index = 0; //Index tracking variable
  // Creates temporary variables for transient time modification
  int tempTime1 = timePt1; 
  int tempTime2 = timePt2;
  int tempTime3 = timePt3;
  int tempTemp1 = tempPt1;
  int tempTemp2 = tempPt2;
  int tempTemp3 = tempPt3;

  while(select)
  {
    int lcd_key = read_LCD_buttons();
    switch (lcd_key)
    {
    case btnLEFT: //switch to previous mode
      {
        index=index-1;
        if(index < 0)
        {
          index= variablesSize - 1;
        }
        lcd.clear();
        break;
      }
    case btnRIGHT: //switch to next mode
      {  
        index=index+1;
        if(index >= variablesSize)
        {
          index=0;
        }
        lcd.clear();
        break;
      }
    case btnUP:     //increment up
      {
        if(index == 0) //When index is at 0 1st temperature point  will be modified
        {
          lcd.clear();
          tempTime1 = tempTime1+1;
          printReflowPoint(1,tempTime1,tempTemp1,0);
        }
        else if(index == 1) //When index is at 1 1st time point will be modified
        {
          lcd.clear();
          tempTemp1 = tempTemp1+1;
          printReflowPoint(1,tempTime1,tempTemp1,1);
        }
        else if(index == 2) //When index is at 2 2nd temperature will be modified
        {
          lcd.clear();
          tempTime2 = tempTime2+1;
          printReflowPoint(2,tempTime2,tempTemp2,0);
        }
        else if(index == 3) //When index is at 3 2nd time point will be modified
        {
          lcd.clear();
          tempTemp2 = tempTemp2+1;
          printReflowPoint(2,tempTime2,tempTemp2,1);
        }
        else if(index == 4) //When index is at 4 3rd temperature will be modified
        {
          lcd.clear();
          tempTime3 = tempTime3+1;
          printReflowPoint(3,tempTime3,tempTemp3,0);            
        }
        else   //When index is at 5 3rd time point will be modified (default case if index out-of-bounds too)
        {
          lcd.clear();
          tempTemp3 = tempTemp3+1;
          printReflowPoint(3,tempTime3,tempTemp3,1);
        }
        break;
      }
    case btnDOWN:    //increment down
      {
        if(index == 0) //When index is at 0 1st temperature point  will be modified
        {
          lcd.clear();
          tempTime1 = tempTime1-1;
          if(tempTime1 < 0)
          {
            tempTime1 = 0;
          }
          printReflowPoint(1,tempTime1,tempTemp1,0);
        }
        else if(index == 1)  //When index is at 1 1st time point will be modified
        {
          lcd.clear();
          tempTemp1 = tempTemp1-1;
          printReflowPoint(1,tempTime1,tempTemp1,1);
        }
        else if(index == 2)  //When index is at 2 2nd temperature will be modified
        {
          lcd.clear();
          tempTime2 = tempTime2-1;
          if(tempTime2 < tempTime1+1)
          {
            tempTime2 = tempTime1+1;
          }
          printReflowPoint(2,tempTime2,tempTemp2,0);
        }
        else if(index == 3) //When index is at 3 2nd time point will be modified
        {
          lcd.clear();
          tempTemp2 = tempTemp2-1;
          printReflowPoint(2,tempTime2,tempTemp2,1);
        }
        else if(index == 4)  //When index is at 4 3rd temperature will be modified
        {
          lcd.clear();
          tempTime3 = tempTime3-1;
          if(tempTime3 < tempTime2+1)
          {
            tempTime3 = tempTime2+1;
          }
          printReflowPoint(3,tempTime3,tempTemp3,0);
        }
        else  //When index is at 5 3rd time point will be modified (default case if index out-of-bounds too)
        { 
          lcd.clear();
          tempTemp3 = tempTemp3-1;
          printReflowPoint(3,tempTime3,tempTemp3,1);
        }
        break;
      }
    case btnSELECT:  //enter new user input points as reflow points
      {
        //Check if temperatures are in reasonable bounds for reflow device
        if(tempCheck(tempTemp1,1) && tempCheck(tempTemp2,2) && tempCheck(tempTemp3,3)) 
        {
          if(verifySelection()) // Verify user wants to change set points
          {
            timePt1 = tempTime1;
            timePt2 = tempTime2;
            timePt3 = tempTime3;
            tempPt1 = tempTemp1;
            tempPt2 = tempTemp2;
            tempPt3 = tempTemp3;
            select = false;
            delay(400);
          }
        } 
        break;
      }

    case btnNONE:    // The location where set points are kept in logic of system
      {
        if(tempTime2 < tempTime1+1) //make sure time points occur after one another
        {
          tempTime2 = tempTime1+1;
        }
        if(tempTime3 < tempTime2+1) //make sure time points occur after one another
        {
          tempTime3 = tempTime2+1; 
        }
        if(tempTemp3 < 218)
        {
          tempTemp3 = 218; //Liquidus Check
        }
        if(tempTemp3 < tempTemp2) // make sure temp points occur at a level greater than or equal to one another
        {
          tempTemp3 = tempTemp2;
        }
        if(tempTemp2 < tempTemp1) // make sure temp points occur at a level greater than or equal to one another
        {
          tempTemp2 = tempTemp1;
        }
        if(index == 0)
        {
          printReflowPoint(1,tempTime1,tempTemp1,0); 
        }
        else if(index == 1)
        {
          printReflowPoint(1,tempTime1,tempTemp1,1);
        }
        else if(index == 2)
        {
          printReflowPoint(2,tempTime2,tempTemp2,0);
        }
        else if(index == 3)
        {
          printReflowPoint(2,tempTime2,tempTemp2,1);
        }
        else if(index == 4)
        {
          printReflowPoint(3,tempTime3,tempTemp3,0);
        }
        else
        {
          printReflowPoint(3,tempTime3,tempTemp3,1);
        }
        break;
      }
    }
  }
}
//Makes sure the temperatures to be assigned have values within the correct range
// dataSet is the number of the set point that the temp is assigned to
// possibleTemp is the temperature value that is being checked
boolean tempCheck(int possibleTemp, int dataSet)
{
  if(possibleTemp > maxSetPoint) // If the temperature is too high this occurs
  {
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Temp ");
    lcd.print(dataSet);
    lcd.setCursor(4,1);
    lcd.print("Too High!");
    delay(1000);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Please Set Below");
    lcd.setCursor(5,1);
    lcd.print(maxSetPoint);
    lcd.print(" C");
    delay(2000);
    lcd.clear();
    return false;
  }
  else if(possibleTemp < minSetPoint) // If the temperature is too low this occurs
  {
    lcd.clear();
    lcd.setCursor(4,0);
    lcd.print("Temp ");
    lcd.print(dataSet);
    lcd.setCursor(4,1);
    lcd.print("Too Low!");
    delay(1000);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Please Set Above");
    lcd.setCursor(5,1);
    lcd.print(minSetPoint);
    lcd.print(" C");
    delay(2000);
    lcd.clear();
    return false;
  }  
  return true;
}

//Makes sure the user wants to change their reflow set points
boolean verifySelection()
{
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Change Set");
  lcd.setCursor(0,1);
  lcd.print("Points?");
  delay(2000);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("SEL: VERIFY");
  lcd.setCursor(0,1);
  lcd.print("ANY BTN: RETURN");
  boolean notVerified = true;
  while(notVerified)
  {
    int check = read_LCD_buttons();
    switch(check)
    {
      case(btnSELECT):
      {
        return true;
        break;
      }
      case(btnNONE):
      {
        break;
      }
    default:
      {
        return false;
      }
    }
  }
}

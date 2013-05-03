void saveNewDefaultData()
{
  //Designed to only accept bytes as acceptable setpoints given range of data
  //This is fine given the system only allows the user to change the temp range 
  //by a given amount
  //Writing to address 0 (Time Pt 1) including size check
  if(timePt1 > 255)
  {
    printEEPROMWarnTime(1);
  }
  EEPROM.write(0,(byte)timePt1);
  //Writing to address 1 (Time Pt 2 - Time Pt 1) including size check
  if(timePt2 - timePt1 > 255)
  {
    printEEPROMWarnTime(2);
  }
  EEPROM.write(1,(byte)(timePt2-timePt1));

  //Writing to address 2 (Time Pt 3 - Time Pt 2)
  if(timePt3 - timePt2 > 255)
  {
    printEEPROMWarnTime(3);
  }
  EEPROM.write(2,(byte)(timePt3-timePt2));
  //Writing to address 3/4/5 (Temp Pt 1/2/3) 
  //No warning necessary because setReflowPoints constraints 
  //improper temperatures
  EEPROM.write(3,(byte)tempPt1); 
  EEPROM.write(4,(byte)tempPt2);
  EEPROM.write(5,(byte)tempPt3);
  //Indicator to tell if defaults ave been changed
  EEPROM.write(6,(byte)1);
}

void checkNewDefault()
{
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("SEL:  Confirm");
  lcd.setCursor(0,1);
  lcd.print("ANY:  Return");
  boolean run = true;
  while(run)
  {
    boolean check = read_LCD_buttons();
    switch(check)
    {
      case(btnSELECT):
      {
        run = false;
        saveNewDefaultData();
        break;
      }
      case(btnNONE):
      {
        break;
      }
    default:
      {
        run = false;
      }
    }
  }
}

void checkRestore()
{
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("SEL:  Confirm");
  lcd.setCursor(0,1);
  lcd.print("ANY:  Return");
  boolean run = true;
  while(run)
  {
    boolean check = read_LCD_buttons();
    switch(check)
    {
      case(btnSELECT):
      {
        run = false;
        restoreDefaultSettings();
        break;
      }
      case(btnNONE):
      {
        break;
      }
    default:
      {
        run = false;
      }
    }
  }
}

void restoreDefaultSettings()
{
  //Restore Default Reflow Points
  timePt1 = 150;
  timePt2 = 240;
  timePt3 = 370;
  tempPt1 = 150;
  tempPt2 = 150;
  tempPt3 = 240;
  saveNewDefaultData();
}

//Warn User Time Points may not save correctly
void printEEPROMWarnTime(int index)
{
  lcd.clear();
  lcd.setCursor(0,0);
  String output = "";
  output.concat("Time Point ");
  output.concat(index);
  lcd.print(output);
  lcd.setCursor(0,1);
  lcd.print("Too High");
  delay(2000);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("New Default");
  lcd.setCursor(0,1);
  lcd.print("Save Unstable");
  delay(2000);
}

void displayStats()
{
  //Displays Stats
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Entering");
  lcd.setCursor(0,1);
  lcd.print("Stats Mode");
  delay(1000);
  if(maxPk == 0)
  {
    lcd.setCursor(0,0);
    lcd.print("Previous Run");
    lcd.setCursor(0,1);
    lcd.print("Not Detected");
    delay(1000);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Stats Cannot");
    lcd.setCursor(0,1);
    lcd.print("Be Generated");
    delay(1000);
  }
  else
  {
    float percentErr= abs((((float)maxPk-(float)tempPt3)/((float)tempPt3))*100);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Desired Pk ");
    lcd.print(tempPt3);
    lcd.print("C");
    
    lcd.setCursor(0,1);
    lcd.print("Pk ");
    lcd.print(maxPk);
    lcd.print("C");
    
    lcd.setCursor(7,1);
    lcd.print(" Err: ");
    lcd.print((int) percentErr); //Rounds error to an int to allow display of percent sign
    lcd.print("%");
    delay(10000);
  }
}

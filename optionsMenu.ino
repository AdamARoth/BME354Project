void optionsMenu()
{ 
  String options[optionsSize] = {
    "Set Reflow Pts",
    "Export Data",
    "Display Stats",
    "Save New Default",
    "Restore Settings"      };
  int lcd_key = read_LCD_buttons();
  switch(lcd_key)
  {
  case btnDOWN:
    {
      index = index + 1;
      if(index >= optionsSize)
      {
        index = 0;
      } 
      lcd.clear();     
      break;
    }
  case btnUP:
    {
      index = index - 1;
      if(index < 0)
      {
        index = optionsSize - 1;
      }
      lcd.clear();
      break;
    }
  case btnSELECT:
    {
      if(index == 0)
      {
        setReflowPoints();
      }
      else if(index == 1)
      {
        exportData();
      }
      else if(index == 2)
      {
        displayStats();
      }
      else if(index == 3)
      {
        checkNewDefault();
      }
      else if(index == 4)
      {
        checkRestore();
      }
      optionsMode = false;
      break;
    }
  case btnNONE:
    {
      lcd.setCursor(0,0);
      lcd.print("Select a Mode");
      lcd.setCursor(0,1);
      lcd.print(options[index]);
      break;
    }
  case btnRIGHT:
    {
      optionsMode = false;
      break; 
    }
  default:
    {
      break;
    }
  }
}

int read_LCD_buttons()   // Debounce of LCD buttons and Deciding which button was pressed
{
  int run1 = read_LCD_buttonsHelp();  // read in voltage of button press
  if(run1 != btnNONE)
  {
    delay(debounceDelay);                // Debounce delay
    int run2 = read_LCD_buttonsHelp();   // read in the voltage AGAIN
    if(run2 > (run1 - 25) && run2 < (run1 + 25))  // Decide if it is within parameters
    {
      return run2;    // output the correct button
    }
  }
  return btnNONE;
}

int read_LCD_buttonsHelp()    // Read in the voltage of the button press
{
  int adc_key_in = analogRead(0);
  if (adc_key_in > VNONE) return btnNONE;
  else if (adc_key_in < V1) return btnRIGHT;
  else if (adc_key_in < V2) return btnUP;
  else if (adc_key_in < V3) return btnDOWN;
  else if (adc_key_in < V4) return btnLEFT;
  else if (adc_key_in < V5) return btnSELECT;
  return btnNONE; 
}

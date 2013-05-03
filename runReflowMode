void runReflowMode()
{
  int reflowcheck = read_LCD_buttons();
  switch(reflowcheck)
  {
    case(btnLEFT):
    {
      exitREFLOW();    // Prematurely EXIT the Reflow Mode by pressing LEFT button
      break;
    }
    case(btnNONE):
    {
      optionsPID();      // Set the options of the PID
      setReflowCurve();  // Set the temperature and time points of the Reflow curve
      runPID();          // Run the main PID function
      exportMATLAB();    // Export the data to Serial port and then to MATLAB
      printRunReflow();  // Display the Reflow data to LCD
      heatcont.heaterSafety(currTemp, setTemp,warnPoint,maxPoint);  // Implement heater safety temperatures
      endREFLOW();      // END and EXIT the Reflow mode function
      break;
    }
  }
}

void exportData()
{
  boolean continueExport = true;
  byte memAccessIndex = 7; //Index that keeps track of where in the memory we are
  //Loops through each five second iteration saved in memory
  while(continueExport)
  { 
    elapsedTime = (((memAccessIndex-1)/2)-3)*5; //Produces elapsed time in seconds
    setTemp =  EEPROM.read(memAccessIndex); //Produces set temp in degrees C
    currTemp = EEPROM.read(memAccessIndex+1); //Produces current Temp in degrees C
    if(memAccessIndex+3 > 255)
    {
      continueExport = false;
    }
    else
    {  
      exportMATLAB();
    }
    memAccessIndex = memAccessIndex + 2; //Update memory index
  }
  elapsedTime = 0;
}

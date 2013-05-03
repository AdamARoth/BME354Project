void setReflowCurve()    // Set the Temperature and Time values of the Reflow curve for the PID oven control to follow
{
  elapsedTime = ((double) now - (double) startTime)/1000;  // Total Elapsed Time in seconds!!!

  if(elapsedTime < (double) timePt1)  // 1st STAGE - RAMP UP to SOAK
  {
    setTemp = (((double) tempPt1-(double) startTemp)/((double) timePt1 - 0))*(elapsedTime) + (double) startTemp;
    setTime = (double) timePt1;
  }
  else if((elapsedTime >= (double) timePt1) && (elapsedTime < (double) timePt2))    // 2nd STAGE - SOAK 
  {
    setTemp = (((double) tempPt2-(double) tempPt1)/((double) timePt2-(double) timePt1))*(elapsedTime) + ((double) tempPt1 - ((double) tempPt2-(double) tempPt1)/((double) timePt2-(double) timePt1)*timePt1);
    setTime = (double) timePt2 - (double) timePt1;
  }
  else if((elapsedTime >= (double) timePt2) && (elapsedTime <= (double) timePt3))      // 3rd STAGE - RAMP TO PEAK and REFLOW
  {
    setTemp = (((double) tempPt3-(double) tempPt2)/((double) timePt3-(double) timePt2))*(elapsedTime) + ((double) tempPt2 - ((double) tempPt3-(double) tempPt2)/((double) timePt3-(double) timePt2)*timePt2);
    setTime = (double) timePt3 - (double) timePt2;
  }
  else if(elapsedTime > (double) timePt3)   // COOL DOWN STAGE
  {
    setTemp = 0;
    setTime = ((double) timePt3 + 20) - (double) timePt3;
  }
  else
  {
    setTemp = 0;
  }
}


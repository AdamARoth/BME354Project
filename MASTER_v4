/*******************************************************************************
 * MASTER CODE TO RUN THE KAAT REFLOW-SOLDER OVEN - Powered by Audrina the Arduino
 * Created by ADAM ROTH, KAVITHA PRASANNA, ALEXA CHOY, TYLER HOBBS
 * KAAT Industries
 ********************************************************************************/

// include the library codes:
#include <LiquidCrystal.h>
#include <HeaterControl.h>
#include <PID_v1.h>
#include <EEPROM.h>

// define variables in code
#define btnRIGHT 0          //Set the different button press values
#define btnUP 1
#define btnDOWN 2
#define btnLEFT 3
#define btnSELECT 4
#define btnNONE 5
#define V1 50              //Define the voltages of the different buttons on pin A0
#define V2 195
#define V3 380
#define V4 555
#define V5 790
#define VNONE 1000
#define optionsSize 5      //Define the number of optionsMenu choices
#define heaterPin 2        //Digital pin that the heater oven connects
#define sensePin 5         //Analog Thermocouple Temp-sensing pin that the temperature/voltage is read from
#define debounceDelay 85   //Set the Debounce Delay Time
#define variablesSize 6    //Variable size of 3 Time and 3 Temperature points in Setting the Reflow Points
#define warnPoint 260      // Warning Temperature point - used by HeaterControl
#define maxPoint 280       // Maximum Temperature point - used by HeaterControl
#define minSetPoint 80     //Define Min User Set Temp
#define maxSetPoint 250    //Define Max User Set Temp

//Define the MODE variables that change whether the mode is accessed.
boolean optionsMode = false;
boolean reflowMode = false;
//Define the PID variables that are used to run the Reflow PID functions.
double currTemp, setTemp, setTime, PIDOutput;   //Current temperature from thermocouple pin, calculated Set Temperature point, calculated set Time point, Output of the PID.
unsigned long windowStartTime, now, startTime;  //Stage Start Time, NOW time, Reflow Start Time.
double elapsedTime;                             //Elapsed time that Reflow function is running.
int startTemp;                                  //Start Temperature of the Reflow function.
int val;                                        //Temporary value storing the thermocouple sense pin Voltage.
int index = 0;                                  //index of options in menu
int maxPk = 0;                                  //Initialize Max Peak as 0 before run occurs
int memIndex = 7;                               //Keeps track of where the EEPROM is being written to in RunPID
//Define Reflow Temperature and Time Points
int timePt1, timePt2, timePt3, tempPt1, tempPt2, tempPt3;
//Define the aggressive and conservative PID Tuning Parameters
double aggKp=130, aggKi=4, aggKd=50;
double consKp=100, consKi=2, consKd=40;

// initialize the libraries and select the pins used on the LCD panel
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);
PID myPID(&currTemp, &PIDOutput, &setTemp,consKp,consKi,consKd, DIRECT);
HeaterControl heatcont(currTemp, setTemp,warnPoint,maxPoint);      //brings in Safety control for heater oven

void setup()
{
  Serial.begin(9600);            // start the Serial port
  lcd.begin(16, 2);              // start the LCD library
  pinMode(heaterPin,OUTPUT);     // set heaterPin to OUTPUT mode
  //Check if defaults are saved in device
  if(EEPROM.read(6) == 1)
  {
    timePt1 = (int) EEPROM.read(0);
    timePt2 = (int) (timePt1 + EEPROM.read(1));
    timePt3 = (int) (timePt2 + EEPROM.read(2));
    tempPt1 = (int) EEPROM.read(3);
    tempPt2 = (int) EEPROM.read(4);
    tempPt3 = (int) EEPROM.read(5);
  }
  startUpMessage();              // begin start up messages
}

void loop()
{
  if (reflowMode)
  {
    runReflowMode();      // switch to running the reflow if reflowMode is true
  }

  else if (optionsMode)
  {
    optionsMenu();        // switch to the Options Menu if optionsMode is true
  }

  else   // Regular case - when NOT in optionsMenu or reflow mode.
  {
    int lcd_key = read_LCD_buttons();
    switch(lcd_key)
    {
    case btnRIGHT:      // begin the Options Menu mode
      {
        optionsMode = true;
        lcd.clear();
        break;
      }
    case btnNONE:        // MAIN MENU Display
      {
        lcd.setCursor(0,0);
        lcd.print("RIGHT: OPT MENU ");
        lcd.setCursor(0,1);
        lcd.print("SEL: RUN REFLOW ");
        break;
      }
    case btnSELECT:      // begin the reflow mode 
      {
        val = analogRead(sensePin);           
        startTemp = val * 0.00489 / 0.005;    //Set the Start Temp
        startTime = millis();                 //Set the Start Time
        windowStartTime = millis();           //Set the start time for the first stage
        now = millis();                       //Set the NOW (current) time
        reflowMode = true;                    //switches into reflow mode
        break;
      }
    default:
      {
        break;
      }
    }
  }
}

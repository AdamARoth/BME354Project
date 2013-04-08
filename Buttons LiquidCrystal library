//Sample using LiquidCrystal library
#include <LiquidCrystal.h>
/*******************************************************
This program will test the LCD panel and the buttons
Mark Bramwell, July 2010
********************************************************/
// select the pins used on the LCD panel
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);
// define some values used by the panel and buttons
int lcd_key = 0;
int adc_key_in = 0;
#define btnRIGHT 0
#define btnUP 1
#define btnDOWN 2
#define btnLEFT 3
#define btnSELECT 4
#define btnNONE 5
#define V1 500
#define V2 500
#define V3 500
#define V4 500
#define V5 500
#define VNONE 500
// read the buttons
int read_LCD_buttons()
{
adc_key_in = analogRead(0); // read the value from the sensor
// my buttons when read are centered at these valies: 0, 144, 329, 504, 741
// we add approx 50 to those values and check to see if we are close
if (adc_key_in > VNONE) return btnNONE; // We make this the 1st option for speed reasons since if (adc_key_in < V1) return btnRIGHT;
if (adc_key_in < V2) return btnUP;
if (adc_key_in < V3) return btnDOWN;
if (adc_key_in < V4) return btnLEFT;
if (adc_key_in < V5) return btnSELECT;
return btnNONE; // when all others fail, return this...
}
void setup()
{
lcd.begin(16, 2); // start the library
}
void loop()
{
lcd_key = read_LCD_buttons(); // read the buttons
switch (lcd_key) // depending on which button was pushed, we perform an action
{
case btnRIGHT:
{
//Instructions for what to do on RIGHT button press
break;
}
case btnLEFT:
{
//Instructions for what to do on LEFT button press
break;
}
case btnUP:
{
//Instructions for what to do on UP button press
break;
}
case btnDOWN:
{
//Instructions for what to do on DOWN button press
break;
}
case btnSELECT:
{
//Instructions for what to do on SELECT button press
break;
}
case btnNONE:
{
//Instructions for what to do if no button is pressed.
break;
}
}
}

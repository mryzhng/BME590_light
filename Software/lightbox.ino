/*********************
Example code for the Adafruit RGB Character LCD Shield and Library
This code displays text on the shield, and also reads the buttons on the keypad.
When a button is pressed, the backlight changes color.
**********************/

// include the library code:
#include <Wire.h>
#include <Adafruit_RGBLCDShield.h>
#include <utility/Adafruit_MCP23017.h>


// The shield uses the I2C SCL and SDA pins. On classic Arduinos
// this is Analog 4 and 5 so you can't use those for analogRead() anymore
// However, you can connect other I2C sensors to the I2C bus and share
// the I2C bus.
Adafruit_RGBLCDShield lcd = Adafruit_RGBLCDShield();

// These #defines make it easy to set the backlight color
#define RED 0x1
#define YELLOW 0x3
#define GREEN 0x2
#define TEAL 0x6
#define BLUE 0x4
#define VIOLET 0x5
#define WHITE 0x7

int sensorPin = A0;
float sensorValue = 0;
float brightVal = 0;
float darkVal = 0;
float ledVal = 0;

void setup() {
  // Debugging output
  Serial.begin(9600);
  // set up the LCD's number of columns and rows: 
  lcd.begin(16, 2);
  lcd.print("Hold in light" );
  lcd.setCursor(0,1);
  lcd.print("& press Select!");
  lcd.setBacklight(WHITE);
  if (buttons & BUTTON_SELECT) {
  brightVal = analogRead(sensorPin);
    }
  else{
    }
  
  lcd.print("Hold in dark");
  lcd.setCursor(0,1);
  lcd.print("& press Right key!");
  if (buttons & BUTTON_RIGHT) {
    darkVal = analogRead(sensorPin);
    }
  else{
    }


}

uint8_t i=0;

void loop() {
  
  
  uint8_t buttons = lcd.readButtons();

}












  lcd.print("Hold in dark" );
  lcd.setCursor(0, 1);
  lcd.print("& press Right!");
  while(darkVal=0){
    if (buttons) {
    if (buttons & BUTTON_RIGHT) {
      darkVal = analogRead(sensorPin);
    }
  }
  }
    lcd.clear();
    lcd.print(darkVal);
    delay(1000);

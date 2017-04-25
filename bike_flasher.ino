//http://wayoda.github.io/LedControl/
//http://playground.arduino.cc/Main/LedControl

#include "LedControl.h"
#include "binary.h"

/*const DIN = 12;
  const CS = 11;
  const CLK = 10; */

LedControl lc = LedControl (12,11,10,1);

//Delay time between updates (mandatory)
unsigned long delaytime = 100;

void setup() {
  lc.shutdown(0, false);
  lc.setIntensity(0, 8);
  lc.clearDisplay(0);
}

void writeArduinoOnMatrix() {
  
  byte left[8]  = {0x0, 0x38, 0x70, 0xff, 0xff, 0x70, 0x38, 0x0};
  byte off[8]   = {0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0};
  byte brake[8] = {0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff};
  
}

void rightArrow() {
  byte right[8] = {0x0, 0x1c, 0xe, 0xff, 0xff, 0xe, 0x1c, 0x0};
  
  lc.setRow(0,0,right[0]);
  lc.setRow(0,1,right[1]);
  lc.setRow(0,2,right[2]);
  lc.setRow(0,3,right[3]);
  lc.setRow(0,4,right[4]);
  lc.setRow(0,5,right[5]);
  lc.setRow(0,6,right[6]);
  lc.setRow(0,7,right[7]);
  delay(600);
  lc.clearDisplay(0);
  delay(600);
}

void loop() {
  //writeArduinoOnMatrix();
  //lc.setLed(0,0,1,true);
  rightArrow();
}

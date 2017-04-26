//http://wayoda.github.io/LedControl/
//http://playground.arduino.cc/Main/LedControl

#include "LedControl.h"
#include "binary.h"

/*const int DIN = 12;
  const int CS = 11;
  const int CLK = 10; */

const int rightButton = 9;
const int leftButton = 8;

LedControl lc = LedControl (12,11,10,1);

//Delay time between updates (mandatory)
unsigned long delaytime = 100;

int rightButtonState = 0;
int leftButtonState = 0;

void setup() {
  lc.shutdown(0, false);
  lc.setIntensity(0, 8);
  lc.clearDisplay(0);

  pinMode(rightButton, INPUT);
  pinMode(leftButton, INPUT);
}

void rightArrow() {
  byte right[8]  = {0x38,0x1c,0xe,0xff,0xff,0xe,0x1c,0x38};

  lc.setIntensity(0, 10);
  
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

void leftArrow() {
  byte left[8]  = {0x1c,0x38,0x70,0xff,0xff,0x70,0x38,0x1c};

  lc.setIntensity(0, 10);
  
  lc.setRow(0,0,left[0]);
  lc.setRow(0,1,left[1]);
  lc.setRow(0,2,left[2]);
  lc.setRow(0,3,left[3]);
  lc.setRow(0,4,left[4]);
  lc.setRow(0,5,left[5]);
  lc.setRow(0,6,left[6]);
  lc.setRow(0,7,left[7]);
  delay(600);
  lc.clearDisplay(0);
  delay(600);
}

void brake() {  
  byte brake[8] = {0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff};
  
  lc.setIntensity(0, 1);

  lc.setRow(0,0,brake[0]);
  lc.setRow(0,1,brake[1]);
  lc.setRow(0,2,brake[2]);
  lc.setRow(0,3,brake[3]);
  lc.setRow(0,4,brake[4]);
  lc.setRow(0,5,brake[5]);
  lc.setRow(0,6,brake[6]);
  lc.setRow(0,7,brake[7]);
}

void loop() {
  rightButtonState = digitalRead(rightButton);
  leftButtonState = digitalRead(leftButton);

  if (rightButtonState == HIGH) {
    brake();
  }
  
  //rightArrow();
  //leftArrow();
}

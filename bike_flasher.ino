//http://wayoda.github.io/LedControl/
//http://playground.arduino.cc/Main/LedControl
//This last revision stands untested


#include "LedControl.h"
#include "binary.h"

/*const int DIN = 12;
  const int CS = 11;
  const int CLK = 10; */

const int leftButton = 7;
const int rightButton = 6;
const int rightLED = 5;
const int leftLED = 4;

LedControl lc = LedControl (12,11,10,0);

void setup() {
    //Initialize pins by declaring their use according to the Arduino standard
    pinMode(leftButton, INPUT);
    pinMode(rightButton, INPUT);
    pinMode(leftLED, OUTPUT);
    pinMode(rightLED, OUTPUT);

    //Initialize the LED matrix according to the LedControl examples
    lc.shutdown(0, false);
    lc.setIntensity(0, 10);
    lc.clearDisplay(0);
}


/*  This function declares a variable representing a right arrow and applies it to the matrix.
    It then clears the matrix.
    */
void rightArrow() {
  //byte right[8]  = {0x38,0x1c,0xe,0xff,0xff,0xe,0x1c,0x38};
  byte right [8] = {0x18,0x0c,0x06,0xff,0xff,0x06,0x0c,0x18};
  
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


/*  This function declares a variable representing a left arrow and applies it to the matrix.
    It then clears it.
    */
void leftArrow() {
  //byte left[8]  = {0x1c,0x38,0x70,0xff,0xff,0x70,0x38,0x1c};
  byte left[8] = {0x18,0x30,0x60,0xff,0xff,0x60,0x30,0x18};
  
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


void loop() {
    //Check for switch status
    leftButtonState = digitalRead(leftButton);
    rightButtonState = digitalRead(rightButton);
    

    //Display an arrow according to the state of the buttons.
    if(leftButtonState == HIGH) { leftArrow(); }
    if (rightButtonState == HIGH) { rightArrow(); }
}

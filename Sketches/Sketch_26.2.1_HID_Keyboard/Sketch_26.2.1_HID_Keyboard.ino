/**********************************************************************
  Filename    : Sketch_42.2.1_HID_Keyboard
  
  Description : This code is designed to provide copy and paste functionality using two buttons with an Arduino Uno R4.
  When the button connected to pin 4 is pressed, a "copy" command (Ctrl + C) is sent to the computer.
  When the button connected to pin 5 is pressed, a "paste" command (Ctrl + V) is sent to the computer.
  
  Auther      : www.freenove.com
  Modification: 2024/08/05
**********************************************************************/
#include <Keyboard.h>  // Include the Keyboard library to enable keyboard functionalities

const int copyButtonPin = 4;  // Pin number for the copy button
const int pasteButtonPin = 5; // Pin number for the paste button

void setup() {
  Keyboard.begin();  // Initialize the Keyboard library
  pinMode(copyButtonPin, INPUT_PULLUP);  // Set the copy button pin as input
  pinMode(pasteButtonPin, INPUT_PULLUP); // Set the paste button pin as input
  delay(1000);       // Wait for 1 second to allow hardware initialization
}

void loop() {
  // Check if the copy button is pressed
  if (digitalRead(copyButtonPin) == LOW) {
    Keyboard.press(KEY_LEFT_CTRL);  // Press the Ctrl key
    Keyboard.press('c');            // Press the 'c' key
    Keyboard.releaseAll();          // Release all keys
    delay(150);                     // Wait for 200 milliseconds
  } 
  // Check if the paste button is pressed
  else if (digitalRead(pasteButtonPin) == LOW) {
    Keyboard.press(KEY_LEFT_CTRL);  // Press the Ctrl key
    Keyboard.press('v');            // Press the 'v' key
    Keyboard.releaseAll();          // Release all keys
    delay(150);                     // Wait for 200 milliseconds
  }
}
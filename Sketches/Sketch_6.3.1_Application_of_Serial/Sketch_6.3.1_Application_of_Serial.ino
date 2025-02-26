/**********************************************************************
  Filename    : Sketch_6.3.1_Application_of_Serial
  Description : Application of Serial
  Auther      : www.freenove.com
  Modification: 2024/08/05
**********************************************************************/

int inInt;        // define a variable to store the data received from serial
int counter = 0;  // define a variable as the data sending to serial
int ledPin = 11;  // the number of the LED pin

void setup() {
  pinMode(ledPin, OUTPUT);              // initialize the LED pin as an output
  Serial.begin(9600);                  // initialize serial port, set baud rate to 9600
  Serial.println("UNO is ready!");     // print the string "UNO is ready!"
}

void loop() {
  if (Serial.available()) {         // judge whether the data has been received
    inInt = Serial.parseInt();      // read an integer
    Serial.print("UNO received:");  // print the string "UNO received:"
    Serial.println(inInt);          // print the received character
    // convert the received integer into PWM duty cycle of ledPin port
    analogWrite(ledPin, constrain(inInt, 0, 255));
  }
}


/**********************************************************************
  Filename    : Sketch_15.1.1_Detect_the_temperature
  Description : Detect the Temperature
  Auther      : www.freenove.com
  Modification: 2024/08/05
**********************************************************************/

#define Voltage_Offset -0.48 // Measuring the offset voltage of the 5V power pin can improve the accuracy of temperature measurement results.

void setup() {
  Serial.begin(9600);                 // Initialize the serial port, set the baud rate into 9600
  Serial.println("UNO is ready!");    // Print the string "UNO is ready!"
}

void loop() {
  // Convert analog value of A0 port into digital value
  int adcVal = analogRead(A0);
  // Calculate voltage
  float v = adcVal * (5.0 + Voltage_Offset) / 1024;
  // Calculate resistance value of thermistor
  float Rt = 10 * v / ((5.0 + Voltage_Offset) - v);
  // Calculate temperature (Kelvin)
  float tempK = 1 / (log(Rt / 10) / 3950 + 1 / (273.15 + 25));
  // Calculate temperature (Celsius)
  float tempC = tempK - 273.15;
  
  // Send the result to computer through serial port
  Serial.print("Current temperature is: ");
  Serial.print(tempK);
  Serial.print(" K, ");
  Serial.print(tempC);
  Serial.println(" C");
  delay(500);
}


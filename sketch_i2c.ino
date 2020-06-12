// Include the Wire library for I2C
#include <Wire.h>

const int lightPin = A0;

void setup() {
  Serial. begin(9600);
  // Join I2C bus as slave with address 8
  Wire.begin(0x8);
  Wire.onRequest(sendEvent);
  
  // Setup pin 8 as output and turn LED off
  pinMode(lightPin, INPUT);
  Serial.println("Starting");
}

void loop() {
  delay(1000);
}
 
// Function that executes whenever data is received from master
void sendEvent() {
  float lightValue = analogRead(lightPin);
  Serial.println(lightValue);
  // Arduino returns 10bit data but we need to convert it to 8bit 
  lightValue = map(lightValue, 0, 1023, 0, 255);
  byte response[2];
  response[0] = (byte)lightValue;
  Wire.write(response,2); // send data to PI
}

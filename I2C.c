////1st board code 
#include <Wire.h>

char receivedData[20];
bool received = false;

void setup() {
  Wire.begin(8); // Start I2C communication with address 8
  Wire.onReceive(receiveEvent);
  Serial.begin(9600);
}

void loop() {
  // Send message to Device 2
  Wire.beginTransmission(9); // Address of Device 2
  Wire.write("Hello from 1");
  Wire.endTransmission();
  
  if (received) {
    Serial.print("Device 1 received: ");
    Serial.println(receivedData);
    received = false;
  }
  
  delay(1000);
}

void receiveEvent(int bytes) {
  int i = 0;
  while (Wire.available()) {
    receivedData[i++] = Wire.read();
  }
  receivedData[i] = '\0';
  received = true;
}
////////////2nd board code
#include <Wire.h>

char receivedData[20];
bool received = false;

void setup() {
  Wire.begin(9); // Start I2C communication with address 9
  Wire.onReceive(receiveEvent);
  Serial.begin(9600);
}

void loop() {
  // Send message to Device 1
  Wire.beginTransmission(8); // Address of Device 1
  Wire.write("Hello from 2");
  Wire.endTransmission();
  
  if (received) {
    Serial.print("Device 2 received: ");
    Serial.println(receivedData);
    received = false;
  }
  
  delay(1000);
}

void receiveEvent(int bytes) {
  int i = 0;
  while (Wire.available()) {
    receivedData[i++] = Wire.read();
  }
  receivedData[i] = '\0';
  received = true;
}

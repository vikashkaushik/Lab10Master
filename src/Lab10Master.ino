/*
 * Project Lab10
 * Description: Master
 * Author: Vikash Kaushik
 * Date: 7/7/21
 */
SYSTEM_MODE(MANUAL);
SYSTEM_THREAD(ENABLED);
#include <Wire.h>
// setup() runs once, when the device is first turned on.
void setup() {
  
  // Put initialization like pinMode and begin functions here.
  

  Wire.begin();  // Initialize as a master
  
  
  Serial.begin(9600);
}

// loop() runs over and over again, as quickly as it can execute.
void loop() {
  // The core of your code will likely live here.
  //connects to serial
  if(Serial.available()){ // Will be true if there is serial data to read
    char value = Serial.read();


    while (!Serial.isConnected());
    // if 0 or 1 it sends to slave
    if(value == '0'){
      Wire.beginTransmission(0x2A);
      Wire.write('0');
  
      Wire.endTransmission();
    }
    if(value == '1'){
      Wire.beginTransmission(0x2A);
      Wire.write('1');
      
      Wire.endTransmission();
    }
    // ? requests information from the slave about button
    if(value == '?'){
      Wire.requestFrom(0x2A, 1);
      while (Wire.available() == 0);
      char value2 = Wire.read();
      Serial.println(value2);
      
    }
      
    
  } 
 
}

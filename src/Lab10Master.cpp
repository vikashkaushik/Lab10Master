/******************************************************/
//       THIS IS A GENERATED FILE - DO NOT EDIT       //
/******************************************************/

#include "Particle.h"
#line 1 "c:/Users/Vikash/Downloads/Lab10Master/src/Lab10Master.ino"
/*
 * Project Lab10
 * Description:
 * Author:
 * Date:
 */
void setup();
void loop();
#line 7 "c:/Users/Vikash/Downloads/Lab10Master/src/Lab10Master.ino"
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
  if(Serial.available()){ // Will be true if there is serial data to read
    char value = Serial.read();


    while (!Serial.isConnected());

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
    if(value == '?'){
      Wire.requestFrom(0x2A, 1);
      while (Wire.available() == 0);
      char value2 = Wire.read();
      Serial.println(value2);
      
    }
      
    
  } 
 
}
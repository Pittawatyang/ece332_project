#include <Arduino.h>
#include "servo.h"

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200); // Init serial communication
  servo_init(); 
}


void loop() {
  // put your main code here, to run repeatedly:

}



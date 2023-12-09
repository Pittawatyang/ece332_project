#include <Arduino.h>
#include "touch_display.h"

// Global constants and variables
int rawX, rawY;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);

}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println();
  delay(1000);
  Serial.print("X: ");
  Serial.println(readX());
  Serial.print("Y: "); 
  Serial.println(readY());
}

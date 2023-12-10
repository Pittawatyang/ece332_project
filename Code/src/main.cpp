#include <Arduino.h>
#include "PID.h"
#include "touch_display.h"
#include "servo.h"
#include "pot.h"
#include <SimpleFOC.h>

const int buttonPin = 38;     // the number of the pushbutton pin
int buttonState = 0;         // variable for reading the pushbutton status
// Global constants and variables
int rawX, rawY;

double SetpointX, InputX, OutputX;
double SetpointY, InputY, OutputY;

// Turning parameter for PID
float kpX = 0.4;
float kiX = 0.0;
float kdX = 0.05;

float kpY = 0.4;
float kiY = 0.0;
float kdY = 0.04;

// sampling time
int samplingTime = 10; // ms

PID xAxisPID(&InputX, &OutputX, &SetpointX, kpX, kiX, kdX, DIRECT);
PID yAxisPID(&InputY, &OutputY, &SetpointY, kpY, kiY, kdY, DIRECT);

int InputXFiltered, InputYFiltered;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  servo_init(); // Initialize the servo controller
  pot_init(); // Initialize the potentiometer

  // Set the platform to flat position by eyes
  setXYangle(1, 125);
  setXYangle(0, 30);

  xAxisPID.SetMode(AUTOMATIC);
  yAxisPID.SetMode(AUTOMATIC);

  // Set the PID output limits
  xAxisPID.SetOutputLimits(115.0, 140.0);
  yAxisPID.SetOutputLimits(20.0, 40.0);

  xAxisPID.SetSampleTime(samplingTime);
  yAxisPID.SetSampleTime(samplingTime);

  delay(3000);
}

void loop() {

  InputX = readX() - XcenterMM;
  InputY = YcenterMM - readY();

  // // Serial.print("X input: ");
  // // Serial.println(InputX);
  // // Serial.print("Y input: ");
  // // Serial.println(InputY);
  // // Serial.println();

  xAxisPID.Compute();
  yAxisPID.Compute();

  // Serial.print("X output: ");
  // Serial.println(OutputX);
  // Serial.print("Y output: ");
  // Serial.println(OutputY);
  // Serial.println();
  setXYangle(1, OutputX);
  setXYangle(0, OutputY);
}




  // put your main code here, to run repeatedly:
  // Serial.println();
  // delay(1000);
  // Serial.print("X: ");
  // Serial.println(readX());
  // Serial.print("Y: "); 
  // Serial.println(readY());

  //Set the angle of servo motor
  // setXYangle(1, 115);
  // delay(2000);
  // setXYangle(1, 125);
  // delay(2000);
  // setXYangle(1, 135);
  // delay(2000);

  // setXYangle(0, 40);
  // delay(2000);
  // setXYangle(0, 30);
  // delay(2000);
  // setXYangle(0, 20);
  // delay(2000);

  // Test potentialmeter
  // kp = readKp();
  // kd = readKd();
  // Serial.print("Kp: ");
  // Serial.println(kp);
  // Serial.print("Kd: ");
  // Serial.println(kd);
  // delay(2000);
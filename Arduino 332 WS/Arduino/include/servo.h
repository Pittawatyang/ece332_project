#ifndef SERVO_H
#define SERVO_H

#include <Arduino.h>
#include <Servo.h>
#include <Wire.h>

#define XservoPin 5
#define YservoPin 6

extern int servoID;
extern int angleI2C;

/**
 * Set the angle of the X-axis servo motor
 *
 * @param angle The angle to be set
 * @return void
 */
void setXangle(int angle);

/**
 * Set the angle of the Y-axis servo motor
 *
 * @param angle The angle to be set
 * @return void
 */
void setYangle(int angle);

/**
 * Initialize the servo X-axis motor
 *
 * @return void
**/
void servoX_init();

/**
 * Initialize the servo Y-axis motor
 *
 * @return void
**/
void servoY_init();

void servo_init();

void receiveEvent(int howMany);

#endif
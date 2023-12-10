#ifndef SERVO_H
#define SERVO_H

#include <Arduino.h>
#include <Servo.h>
#include <Wire.h>

#define XservoPin D5
#define YservoPin D6

/**
 * Send message to another arduino via I2C to control the servo motor
 * Message format: [servoID, angle]
 *
 * @param angle The angle to be set
 * @return void
 */
void setXYangle(int id, int angle);

/**
 * Initialize the I2C bus for communication with servo controller
 *
 * @return void
**/
void servo_init();

#endif
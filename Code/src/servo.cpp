/*****************************************************************************
 * Author: Pittawat Sawatyanon
 * Date:   2023-12-08
 * Description: Driver for drive 2 servo motor X & Y axis
 *
 * Additional Information:
 * - Project: ece332_project
 * - Version: 1.0
 ****************************************************************************/

// Include necessary libraries and headers here
#include "servo.h"

// Define global constants and variables if needed
TwoWire hI2C(PB9, PB8);

/**
 * Initialize the I2C bus for communication with servo controller
 *
 * @return void
**/
void servo_init() {
    hI2C.begin();
}


/**
 * Send message to another arduino via I2C to control the servo motor
 * Message format: [servoID, angle]
 * ID 1: X-axis
 * ID 2: Y-axis
 *
 * @param angle The angle to be set
 * @return void
 */
void setXYangle(int id, int angle) {
    if (id == 0) {
        hI2C.beginTransmission(4); // transmit to device #8
        hI2C.write(0);              // sends one byte
        hI2C.write(angle);              // sends one byte
        hI2C.endTransmission();    // stop transmitting
    } else if (id == 1) {
        hI2C.beginTransmission(4); // transmit to device #8
        hI2C.write(1);              // sends one byte
        hI2C.write(angle);              // sends one byte
        hI2C.endTransmission();    // stop transmitting
    }
}


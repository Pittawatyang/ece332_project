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
Servo Xservo, Yservo;

/**
 * Initialize the servo X-axis motor
 *
 * @return void
**/
void servoX_init() {
    Xservo.attach(XservoPin); // Attach the motor to pin
}

/**
 * Initialize the servo Y-axis motor
 *
 * @return void
**/
void servoY_init() {
    Yservo.attach(YservoPin); // Attach the motor to pin
}

/**
 * Initialize the servo and I2C communication with master

 * @return void
*/
void servo_init() {
    servoX_init();
    servoY_init();
    setXangle(45);
    setYangle(45);
    Wire.begin(4);                // join i2c bus with address #4
    Wire.onReceive(receiveEvent); // register event
    
}

/**
 * Set the angle of the Y-axis servo motor
 *
 * @param angle The angle to be set
 * @return void
 */
void setYangle(int angle) {
    int setAngle = angle;
    if (angle >= 40)
        setAngle = 40; // The angle is saturated at 90
    else if (angle <= 20)
        setAngle = 20; // The angle is saturated at 0
    Yservo.write(setAngle); // Set the angle
}

/**
 * Set the angle of the X-axis servo motor
 *
 * @param angle The angle to be set
 * @return void
 */
void setXangle(int angle) {
    int setAngle = angle;
    if (angle >= 140)
        setAngle = 140; // The angle is saturated at 90
    else if (angle <=115)
        setAngle = 115; // The angle is saturated at 0
    Xservo.write(setAngle); // Set the angle
}

/**
 * Read the I2C communication from master and set the servo anagle
 * ID 1: X-axis servo
 * ID 2: Y-axis servo
 * @return void
 */
void receiveEvent(int howMany) {
    while (Wire.available()) {
        int servoID = Wire.read();   // Read servo ID
        int angle = Wire.read();     // Read desired angle

        // Adjust the servo angle based on the received instruction
        if (servoID == 1) {
            setXangle(angle);
            Serial.println("Servo 1 angle adjusted to: " + String(angle) + " degrees");
            delay(1000);
        } else if (servoID == 0) {
            setYangle(angle);
            Serial.println("Servo 2 angle adjusted to: " + String(angle) + " degrees");
            delay(1000);
        } else {
            Serial.println("Invalid servo ID: " + String(servoID));
        }
    }
    
}

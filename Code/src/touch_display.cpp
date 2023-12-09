/*****************************************************************************
 * Author: Pittawat Sawatyanon
 * Date:   2023-12-08
 * Description: Driver for 4-wire resistive touch screen
 *
 * Additional Information:
 * - Project: ece332_project
 * - Version: 1.0
 ****************************************************************************/

// Include necessary libraries and headers here
#include "touch_display.h"

// Define global constants and variables if needed


/**
 * Read the X-axis analog raw data from the display
 * X+/X1 is connected to A0 configured as output 5V
 * X-/X2 is connected to A1 configured as output GND
 * Y+/Y1 is connected to A2 configured as input Analog
 * Y-/Y2 is connected to A3 configured as open drain
 *
 * @return int ADC value from the display X-axis
 */
int readX() {
    pinMode(Y1, INPUT);
    pinMode(Y2, OUTPUT_OPEN_DRAIN);
    digitalWrite(Y2, HIGH);
    pinMode(X1, OUTPUT); digitalWrite(X1, HIGH);
    pinMode(X2, OUTPUT); digitalWrite(X2, LOW);
    delay(200);

    int rawX = int(float(analogRead(Y1)) / float(AnalogMax / Xresolution));
    return rawX;
}

/**
 * Read the Y-axis analog raw data from the display
 * X+/X1 is connected to A0 configured as input Analog
 * X-/X2 is connected to A1 configured as open drain
 * Y+/Y1 is connected to A2 configured as output 5V
 * Y-/Y2 is connected to A3 configured as output GND
 *
 * @return int ADC value from the display Y-axis
 */
int readY() {
    pinMode(X1, INPUT); // Set X1 as Analog Input
    pinMode(X2, OUTPUT_OPEN_DRAIN); // Set X2 as Open Drain
    digitalWrite(X2, HIGH); 
    pinMode(Y1, OUTPUT); digitalWrite(Y1, HIGH); // Set Y1 as 5V
    pinMode(Y2, OUTPUT); digitalWrite(Y2, LOW); // Set Y2 as GND
    delay(200);

    int rawY = int(float(analogRead(X1)) / float(AnalogMax / Yresolution));
    return rawY;
}
#ifndef TOUCH_DISPLAY_H
#define TOUCH_DISPLAY_H

#include <stdio.h>
#include <Arduino.h>

#define X1  A0
#define X2  A1
#define Y1  A2
#define Y2  A3

#define AnalogMax 950.0

extern volatile const double XcenterMM;
extern volatile const double YcenterMM;

// #define Xresolution 600.0
// #define Yresolution 800.0


/**
 * Read the X-axis analog raw data from the display
 * X+/X1 is connected to A0 configured as output 5V
 * X-/X2 is connected to A1 configured as output GND
 * Y+/Y1 is connected to A2 configured as input Analog
 * Y-/Y2 is connected to A3 configured as open drain
 *
 * @return double in millimeter value on the display X-axis
 */
double readX();
/**
 * Read the Y-axis analog raw data from the display
 * X+/X1 is connected to A0 configured as input Analog
 * X-/X2 is connected to A1 configured as open drain
 * Y+/Y1 is connected to A2 configured as output 5V
 * Y-/Y2 is connected to A3 configured as output GND
 *
 * @return double in millimeter value on the display Y-axis
 */
double readY();

#endif
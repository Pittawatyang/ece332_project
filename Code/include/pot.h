#ifndef POT_H
#define POT_H

#include <Arduino.h>

#define POT1 A4
#define POT1_AnalogMax 1023
#define KpMax 10

#define POT2 A5
#define POT2_AnalogMax 1023
#define KdMax 10

int readKp();
int readKd();
void pot_init();

#endif
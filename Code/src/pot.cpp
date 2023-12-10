/*****************************************************************************
 * Author: Pittawat Sawatyanon
 * Date:   2023-12-08
 * Description: Driver for reading potentiometer
 *
 * Additional Information:
 * - Project: ece332_project
 * - Version: 1.0
 ****************************************************************************/

// Include necessary libraries and headers here
#include "pot.h"

/**
 * Initialize analog pin for reading potentio meter
 * 
 * @return void
*/
void pot_init() {
    pinMode(POT1, INPUT);
    pinMode(POT2, INPUT);
}

/**
 * Read the analog raw data from the POT1
 * Convert to Kp value based on calculated range
 *
 * @return kp value
 */
int readKp() {
    int rawKp_total = 0;
    for (int i = 0; i < 10; i++) {
        rawKp_total += analogRead(POT1);
        delay(2);
    }
    float rawKpAvg = float(rawKp_total) / 5.0;
    return int(rawKpAvg / float(POT1_AnalogMax / KpMax));
}

/**
 * Read the analog raw data from the POT2
 * Convert to Kd value based on calculated range
 *
 * @return kd value
 */
int readKd() {
    int rawKd_total = 0;
    for (int i = 0; i < 10; i++) {
        rawKd_total += analogRead(POT2);
        delay(5);
    }
    float rawKdAvg = float(rawKd_total) / 5.0;
    return int(rawKdAvg / float(POT2_AnalogMax / KdMax));
}
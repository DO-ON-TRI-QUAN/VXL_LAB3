/*
 * fsm_setting.c
 *
 *
 *
 */

#include "fsm_setting.h"
#include "global.h"
#include "traffic_light.h"
#include "softwareTimer.h"
#include "display_traffic7seg.h"
#include "button.h"
#include "fsm_auto.h"

void fsmSetting() {
	if (previousMode == 4 && mode == 1) {
		status1 = INIT;
		return;
	}

    displayAll7SEG(); // Scanning display for both pairs

    switch (mode) {
        case 2: // Mode 2 - Modify Red LED duration
            RedBlinky();  // Blink all single red LEDs as required
            if (isButtonPressed(1)) {
                // Button 2 increases value for red duration without saving
                redIncreaseValue = redIncreaseValue + 1000;
                if (redIncreaseValue + redDuration > 99000) redIncreaseValue = 1000 - redDuration;
            }
            if (isButtonPressed(2)) {
                // Button 3 saves the current incremented value
                redDuration += redIncreaseValue;
                if (redDuration > 99000) redDuration = 1000;
                redIncreaseValue = 0; // Reset the increase value after saving
            } else {
            	redIncreaseValue = 0; //
            }
            // Display updated red duration on the 7-segment display
            SEGvalue1 = (redDuration + redIncreaseValue) / 1000;
            SEGvalue2 = (redDuration + redIncreaseValue) % 1000;
            break;

        case 3: // Mode 3 - Modify Yellow LED duration
            YellowBlinky(); // Blink all single amber LEDs
            if (isButtonPressed(1)) {
                yellowIncreaseValue = yellowIncreaseValue + 1000;
                if (yellowIncreaseValue + yellowDuration > 99000) yellowIncreaseValue = 1000 - yellowDuration;
            }
            if (isButtonPressed(2)) {
                yellowDuration = yellowIncreaseValue;
                if (yellowDuration > 99000) yellowDuration = 1000;
                yellowIncreaseValue = 0;
            } else {
            	yellowIncreaseValue = 0; //
            }

            SEGvalue1 = (yellowDuration + yellowIncreaseValue) / 1000;
            SEGvalue2 = (yellowDuration + yellowIncreaseValue) % 1000;
            break;

        case 4: // Mode 4 - Modify Green LED duration
            GreenBlinky(); // Blink all single green LEDs
            if (isButtonPressed(1)) {
                greenIncreaseValue = greenIncreaseValue + 1000;
                if (greenIncreaseValue + greenDuration > 99000) greenIncreaseValue = 1000 - greenDuration;
            }
            if (isButtonPressed(2)) {
                greenDuration += greenIncreaseValue;
                if (greenDuration > 99000) greenDuration = 1000;
                greenIncreaseValue = 0;
            } else {
            	greenIncreaseValue = 0; //
            }

            SEGvalue1 = (greenDuration + greenIncreaseValue) / 1000;
            SEGvalue2 = (greenDuration + greenIncreaseValue) % 1000;
            break;
    }
}

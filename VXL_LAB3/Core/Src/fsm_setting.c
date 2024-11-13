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
	if (mode == 1 && previousMode == 4) {
		return;
	} else {

		displayAll7SEG();
        switch (mode) {
            case 2:
            	RedBlinky();

            	if (isButtonPressed(1)) {
            		redIncreaseValue = redIncreaseValue + 1000;
            		if (redIncreaseValue + redDuration > 99000) {
            			redIncreaseValue = 1000 - redDuration;
            		}

            	}

            	if (isButtonPressed(2)) {
            		redDuration = redDuration + redIncreaseValue;
            		greenDuration = redDuration - yellowDuration; // Increases green when red increases
            		if (redDuration > 99000) {
            			redDuration = 1000;
            		}

            		redIncreaseValue = 0;
            	}

            	// Display updated red duration on the 7-segment display
            	SEGvalue1 = (redDuration + redIncreaseValue) / 1000;
            	SEGvalue2 = mode;

            	break;

            case 3:
            	YellowBlinky();

            	if (isButtonPressed(1)) {
            		yellowIncreaseValue = yellowIncreaseValue + 1000;
            		if (yellowIncreaseValue + yellowDuration > 99000) {
            			yellowIncreaseValue = 1000 - yellowDuration;
            		}
            	}

            	if (isButtonPressed(2)) {
            	    yellowDuration += yellowIncreaseValue;
            	    redDuration = yellowDuration + greenDuration; // Increases red when yellow increases
            		if (yellowDuration > 99000) {
            			yellowDuration = 1000;
            		}

            		yellowIncreaseValue = 0;
            	}

         	  SEGvalue1 = (yellowDuration + yellowIncreaseValue) / 1000;
         	  SEGvalue2 = mode;

         	  break;

            case 4:
            	GreenBlinky();

            	if (isButtonPressed(1)) {
            		greenIncreaseValue = greenIncreaseValue + 1000;
            		if (greenIncreaseValue + greenDuration > 99000) {
            			greenIncreaseValue = 1000 - greenDuration;
            		}
            	}

            	if (isButtonPressed(2)) {
            		greenDuration += greenIncreaseValue;
            	    redDuration = yellowDuration + greenDuration; // Increases red when green increases
            		if (greenDuration > 99000) {
            			greenDuration = 1000;
            		}

            		greenIncreaseValue = 0;
            	}

            	SEGvalue1 = (greenDuration + greenIncreaseValue) / 1000;
            	SEGvalue2 = mode;

            	break;
        }
    }
}



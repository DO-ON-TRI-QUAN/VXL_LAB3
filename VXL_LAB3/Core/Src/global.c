/*
 * global.c
 *
 *
 *
 */

#include "global.h"
#include "button.h"
#include "display_traffic7seg.h"
#include "softwareTimer.h"
#include "traffic_light.h"

int status1 = INIT;
int status2 = INIT;

int mode = 1;
int previousMode = 0;

int redDuration = 5000;      // Default 5 seconds
int yellowDuration = 2000;   // Default 2 seconds
int greenDuration = 3000;    // Default 3 seconds

int current_timer_value1 = 0; // Holds the remaining time for Pair 1
int current_timer_value2 = 0; // Holds the remaining time for Pair 2

void getMode() {
	if (isButtonPressed(0)) { // Assuming Button 1 is index 0
	    mode++;
	    previousMode = mode - 1;

	    if (mode > 4) {
	    	mode = 1; // Loop back to Mode 1
	    }
	}
}



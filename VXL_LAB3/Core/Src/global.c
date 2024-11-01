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

void getMode() {
	if (isButtonPressed(0)) { // Assuming Button 1 is index 0
	    mode++;
	    previousMode = (mode - 1) % 4;
	    if (mode > 4) {
	    	trafficLightINIT();
	    	status1 = INIT;
	    	status2 = INIT;
	    	SEGvalue1 = 0;
	    	SEGvalue2 = 0;
	    	timer_counter[0] = 0;
	    	timer_counter[1] = 0;
            setTimer(3, 500);

	    	mode = 1; // Loop back to Mode 1
	    }
	}
}



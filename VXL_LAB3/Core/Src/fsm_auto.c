/*
 * fsm_auto.c
 *
 *
 *
 */

#include "fsm_auto.h"
#include "global.h"
#include "traffic_light.h"
#include "softwareTimer.h"
#include "display_traffic7seg.h"
#include "button.h"

void updateCurrentTimerValues() {

    // For Pair 1
    switch (status1) {
        case AUTO_RED1:
            current_timer_value1 = getRemainingTime(0); // Timer ID 0 for Pair 1 Red
            break;
        case AUTO_GREEN1:
            current_timer_value1 = getRemainingTime(0); // Timer ID 0 for Pair 1 Green
            break;
        case AUTO_YELLOW1:
            current_timer_value1 = getRemainingTime(0); // Timer ID 0 for Pair 1 Yellow
            break;
    }

    // For Pair 2
    switch (status2) {
        case AUTO_RED2:
            current_timer_value2 = getRemainingTime(1); // Timer ID 1 for Pair 2 Red
            break;
        case AUTO_GREEN2:
            current_timer_value2 = getRemainingTime(1); // Timer ID 1 for Pair 2 Green
            break;
        case AUTO_YELLOW2:
            current_timer_value2 = getRemainingTime(1); // Timer ID 1 for Pair 2 Yellow
            break;
    }
}

void fsmAuto() {

	if (isButtonPressed(0) == 1) {
		trafficLightINIT();
		status1 = SETTING_RED;
		status2 = SETTING_RED;
	}

	LEDdisplayMode();

	// Update the timer values before each FSM cycle
	 updateCurrentTimerValues();

	 // Update SEGvalue1 and SEGvalue2 with remaining times
	 SEGvalue1 = (getRemainingTime(0) / 1000) + 1;  // For Pair 1
	 SEGvalue2 = (getRemainingTime(1) / 1000) + 1;  // For Pair 2

     displayAll7SEG();

    // FSM for Pair 1
    switch (status1) {
    	case INIT:
             status1 = AUTO_RED1;       // Begin with Pair 1 in Red
             setTimer(0, redDuration);        // 5-second timer for Red on Pair 1
             break;

        case AUTO_RED1:
            RED1();
            if (timer_flag[0]) {           // Red timer for Pair 1 expires
                status1 = AUTO_GREEN1;
                setTimer(0, greenDuration);         // 3-second timer for Green on Pair 1
            }
            break;

        case AUTO_GREEN1:
            GREEN1();
            if (timer_flag[0]) {           // Green timer for Pair 1 expires
                status1 = AUTO_YELLOW1;
                setTimer(0, yellowDuration);         // 2-second timer for Yellow on Pair 1
            }
            break;

        case AUTO_YELLOW1:
            YELLOW1();
            if (timer_flag[0]) {           // Yellow timer for Pair 1 expires
                status1 = AUTO_RED1;
                setTimer(0, redDuration);         // 5-second timer for Red on Pair 1
            }
            break;
    }


    // FSM for Pair 2
    switch (status2) {
    	case INIT:
             status2 = AUTO_GREEN2;       // Begin with Pair 1 in Red
             setTimer(1, greenDuration);        // 5-second timer for Red on Pair 1
             break;

    	case AUTO_GREEN2:
    	     GREEN2();                // Turn on Green light for Pair 2
    	     if (timer_flag[1]) {     // Timer for Green expires
    	         status2 = AUTO_YELLOW2;
    	         setTimer(1, yellowDuration);   // 2-second timer for Yellow
    	     }
    	     break;

    	case AUTO_YELLOW2:
    	     YELLOW2();               // Turn on Yellow light for Pair 2
    	     if (timer_flag[1]) {     // Timer for Yellow expires
    	         status2 = AUTO_RED2;
    	         setTimer(1, redDuration);   // 5-second timer for Red
    	     }
    	     break;

    	case AUTO_RED2:
    	     RED2();                  // Turn on Red light for Pair 2
    	     if (timer_flag[1]) {     // Timer for Red expires
    	         status2 = AUTO_GREEN2;  // Loop back to Green
    	         setTimer(1, greenDuration);     // Reset 3-second timer for Green
    	     }
    	    break;
    }

}





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

void fsmAuto() {
	if (mode > 1) {
		return;
	} else {

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
        	//SEGvalue1 = (getRemainingTime(0) / 1000) + 1;
            //displayAll7SEG();
            RED1();
            if (timer_flag[0]) {           // Red timer for Pair 1 expires
                status1 = AUTO_GREEN1;
                setTimer(0, greenDuration);         // 3-second timer for Green on Pair 1
            }
            break;

        case AUTO_GREEN1:
        	//SEGvalue1 = (getRemainingTime(0) / 1000) + 1;
        	//displayAll7SEG();
            GREEN1();
            if (timer_flag[0]) {           // Green timer for Pair 1 expires
                status1 = AUTO_YELLOW1;
                setTimer(0, yellowDuration);         // 2-second timer for Yellow on Pair 1
            }
            break;

        case AUTO_YELLOW1:
        	//SEGvalue1 = (getRemainingTime(0) / 1000) + 1;
            YELLOW1();
            //displayAll7SEG();
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
    	     //SEGvalue2 = (getRemainingTime(1) / 1000) + 1;  // For Pair 2
             //displayAll7SEG();
    	     GREEN2();                // Turn on Green light for Pair 2
    	     if (timer_flag[1]) {     // Timer for Green expires
    	         status2 = AUTO_YELLOW2;
    	         setTimer(1, yellowDuration);   // 2-second timer for Yellow
    	     }
    	     break;

    	case AUTO_YELLOW2:
    		 //SEGvalue2 = (getRemainingTime(1) / 1000) + 1;  // For Pair 2
            // displayAll7SEG();
    	     YELLOW2();               // Turn on Yellow light for Pair 2
    	     if (timer_flag[1]) {     // Timer for Yellow expires
    	         status2 = AUTO_RED2;
    	         setTimer(1, redDuration);   // 5-second timer for Red
    	     }
    	     break;

    	case AUTO_RED2:
    		 //SEGvalue2 = (getRemainingTime(1) / 1000) + 1;  // For Pair 2
            // displayAll7SEG();
    	     RED2();                  // Turn on Red light for Pair 2
    	     if (timer_flag[1]) {     // Timer for Red expires
    	         status2 = AUTO_GREEN2;  // Loop back to Green
    	         setTimer(1, greenDuration);     // Reset 3-second timer for Green
    	     }
    	    break;
    }
	}
}





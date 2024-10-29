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

void fsmAuto1() {
    switch (status) {
        case INIT:
        	trafficLightINIT();
            status = AUTO_RED1;   // Start in Red state
            setTimer(0, 5000);    // 5-second timer for Red
            break;

        case AUTO_RED1:
            RED1();               // Turn on Red light for Pair 1
            if (timer_flag[0] == 1) {  // Timer for Red expires
                status = AUTO_GREEN1;
                setTimer(0, 3000);  // 3-second timer for Green
            }
            break;

        case AUTO_GREEN1:
            GREEN1();             // Turn on Green light for Pair 1
            if (timer_flag[0] == 1) {  // Timer for Green expires
                status = AUTO_YELLOW1;
                setTimer(0, 2000);  // 2-second timer for Yellow
            }
            break;

        case AUTO_YELLOW1:
            YELLOW1();            // Turn on Yellow light for Pair 1
            if (timer_flag[0] == 1) {  // Timer for Yellow expires
                status = AUTO_RED1;  // Loop back to Red
                setTimer(0, 5000);  // Reset 5-second timer for Red
            }
            break;
    }
}

void fsmAuto2() {
    switch (status) {
        case INIT:
            status = AUTO_GREEN2;    // Start Pair 2 in Green state
            setTimer(1, 3000);       // 3-second timer for Green
            break;

        case AUTO_GREEN2:
            GREEN2();                // Turn on Green light for Pair 2
            if (timer_flag[1] == 1) {     // Timer for Green expires
                status = AUTO_YELLOW2;
                setTimer(1, 2000);   // 2-second timer for Yellow
            }
            break;

        case AUTO_YELLOW2:
            YELLOW2();               // Turn on Yellow light for Pair 2
            if (timer_flag[1] == 1) {     // Timer for Yellow expires
                status = AUTO_RED2;
                setTimer(1, 5000);   // 5-second timer for Red
            }
            break;

        case AUTO_RED2:
            RED2();                  // Turn on Red light for Pair 2
            if (timer_flag[1] == 1) {     // Timer for Red expires
                status = AUTO_GREEN2;  // Loop back to Green
                setTimer(1, 3000);     // Reset 3-second timer for Green
            }
            break;
    }
}

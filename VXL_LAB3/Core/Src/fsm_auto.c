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
				status1 = AUTO_RED1;
				setTimer(0, redDuration);

				break;

			case AUTO_RED1:
				RED1();
				if (timer_flag[0]) {
					status1 = AUTO_GREEN1;
					setTimer(0, greenDuration);
				}

				break;

			case AUTO_GREEN1:
				GREEN1();
				if (timer_flag[0]) {
					status1 = AUTO_YELLOW1;
					setTimer(0, yellowDuration);
				}

				break;

			case AUTO_YELLOW1:
				YELLOW1();
				if (timer_flag[0]) {
					status1 = AUTO_RED1;
					setTimer(0, redDuration);
				}

				break;
		}


		// FSM for Pair 2
		switch (status2) {
			case INIT:
				status2 = AUTO_GREEN2;
				setTimer(1, greenDuration);

				break;

			case AUTO_GREEN2:
				GREEN2();
				if (timer_flag[1]) {
					status2 = AUTO_YELLOW2;
					setTimer(1, yellowDuration);
				}

				break;

			case AUTO_YELLOW2:
				YELLOW2();
				if (timer_flag[1]) {
					status2 = AUTO_RED2;
					setTimer(1, redDuration);
				}

				break;

			case AUTO_RED2:
				RED2();
				if (timer_flag[1]) {
					status2 = AUTO_GREEN2;
					setTimer(1, greenDuration);
				}

				break;
		}
	}
}





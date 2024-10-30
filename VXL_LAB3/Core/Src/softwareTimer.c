/*
 * softwareTimer.c
 *
 *
 *
 */

#include "softwareTimer.h"

void setTimer(int index, int counter) {
	timer_flag[index] = 0;
	timer_counter[index] = counter / TICK;
}

void timer_run() {
	for (int i = 0; i < 10; i++) {
		 if (timer_counter[i] > 0) {
			 timer_counter[i]--;
			 if (timer_counter[i] <= 0) {
				 timer_flag[i] = 1;
			}
		}
	}
}

int getRemainingTime(int index) {
    return timer_counter[index] * TICK; // Convert back to actual time
}

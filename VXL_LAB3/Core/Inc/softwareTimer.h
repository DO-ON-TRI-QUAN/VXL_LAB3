/*
 * softwareTimer.h
 *
 *  :
 *
 */

#include "main.h"
#ifndef INC_SOFTWARETIMER_H_
#define INC_SOFTWARETIMER_H_

#define TICK 10

int timer_flag[10];
int timer_counter[10];

void setTimer(int index, int counter);

void timer_run();





#endif /* INC_SOFTWARETIMER_H_ */

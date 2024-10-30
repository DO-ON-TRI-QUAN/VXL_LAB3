/*
 * display_traffic7seg.h
 *
 *
 *
 */

#include "main.h"

#ifndef INC_DISPLAY_TRAFFIC7SEG_H_
#define INC_DISPLAY_TRAFFIC7SEG_H_

int turn;
int SEGvalue1;
int SEGvalue2;

void display7SEG(int tenInt, int unitInt);
void displayAll7SEG();
void updateAll7SEG();

#endif /* INC_DISPLAY_TRAFFIC7SEG_H_ */

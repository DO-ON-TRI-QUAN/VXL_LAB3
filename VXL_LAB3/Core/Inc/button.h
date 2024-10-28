/*
 * button.h
 *
 *  Created on: Oct 5, 2023
 *      Author: KAI
 */

#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_

#include "main.h"

#define NORMAL_STATE SET
#define PRESSED_STATE RESET

extern int TimeOutForKeyPress[3];
extern int button_flag[3];
extern int button_longPress_flag[3];

void buttonINIT();
void getKeyInput();
int isButtonPressed(int index);
int isButtonLongPressed(int index);

#endif /* INC_BUTTON_H_ */


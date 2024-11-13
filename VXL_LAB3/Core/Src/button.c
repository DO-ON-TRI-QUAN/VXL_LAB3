

#include "button.h"

int KeyReg0[3];
int KeyReg1[3];
int KeyReg2[3];
int KeyReg3[3];

int TimeOutForKeyPress[3];
int button_flag[3];
int button_longPress_flag[3];

void buttonINIT() {
    for (int i = 0; i < 3; i++) {
    	KeyReg0[i] = NORMAL_STATE; // Off
    	KeyReg1[i] = NORMAL_STATE;
    	KeyReg2[i] = NORMAL_STATE;
    	KeyReg3[i] = NORMAL_STATE;
    	TimeOutForKeyPress[i] = 100;
    	button_flag[i] = 0;
    	button_longPress_flag[i] = 0;
    }
}

int isButtonPressed(int index) {
   	if (button_flag[index] == 1) {
		button_flag[index] = 0;
		return 1;
	}

	return 0;
}
int isButtonLongPressed(int index) {
	if (button_longPress_flag[index] == 1) {
	    button_longPress_flag[index] = 0;
	    return 1;
	}

	return 0;
}

// Get key input and debounce buttons
void getKeyInput() {
	for (int i = 0; i < 3; i++) {
		KeyReg2[i] = KeyReg1[i];
		KeyReg1[i] = KeyReg0[i];
	}

    // Get buttons input
    KeyReg0[0] = HAL_GPIO_ReadPin(BUTTON1_GPIO_Port, BUTTON1_Pin);
    KeyReg0[1] = HAL_GPIO_ReadPin(BUTTON2_GPIO_Port, BUTTON2_Pin);
    KeyReg0[2] = HAL_GPIO_ReadPin(BUTTON3_GPIO_Port, BUTTON3_Pin);

    for (int i = 0; i < 3; i++) {
	    if ((KeyReg1[i] == KeyReg0[i]) && (KeyReg1[i] == KeyReg2[i])) { // If no bouncing
	        if (KeyReg2[i] != KeyReg3[i]) {
	            KeyReg3[i] = KeyReg2[i];

	            if (KeyReg3[i] == PRESSED_STATE) {
	    	        button_flag[i] = 1;
	    	        TimeOutForKeyPress[i] = 100;
	            }

	        } else {
	    	    TimeOutForKeyPress[i]--;
	            if (TimeOutForKeyPress[i] == 0) {
	        	    TimeOutForKeyPress[i] = 100;
	        	    KeyReg3[i] = NORMAL_STATE;
	            }
	        }
	    }
    }
}




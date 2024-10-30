/*
 * display_traffic7seg.c
 *
 *
 *
 */

#include "display_traffic7seg.h"
#include "global.h"
#include "softwareTimer.h"

int turn = 0;

void display7SEG(int tenInt, int unitInt)
{
    // Array of segment patterns for numbers 0 - 9
    int segment_patterns[10] = {
    		 0b01000000, // 0: segments a, b, c, d, e, f
    		 0b01111001, // 1: segments b, c
    		 0b00100100, // 2: segments a, b, d, e, g
			 0b00110000, // 3: segments a, b, c, d, g
  	         0b00011001, // 4: segments b, c, e, f
    		 0b00010010, // 5: segments a, c, d, f, g
    	     0b00000010, // 6: segments a, c, d, e, f, g
             0b01111000, // 7: segments a, b, c
    	     0b00000000, // 8: all segments
             0b00010000  // 9: segments a, b, c, d, f, g
    };

    // Get the segment pattern for the given number
    int pattern1 = segment_patterns[tenInt];
    int pattern2 = segment_patterns[unitInt];

    // Set each segment based on the pattern
    HAL_GPIO_WritePin(SEG_0_GPIO_Port, SEG_0_Pin, (pattern1 & 0b00000001) ? GPIO_PIN_SET : GPIO_PIN_RESET); // Segment 0
    HAL_GPIO_WritePin(SEG_1_GPIO_Port, SEG_1_Pin, (pattern1 & 0b00000010) ? GPIO_PIN_SET : GPIO_PIN_RESET); // Segment 1
    HAL_GPIO_WritePin(SEG_2_GPIO_Port, SEG_2_Pin, (pattern1 & 0b00000100) ? GPIO_PIN_SET : GPIO_PIN_RESET); // Segment 2
    HAL_GPIO_WritePin(SEG_3_GPIO_Port, SEG_3_Pin, (pattern1 & 0b00001000) ? GPIO_PIN_SET : GPIO_PIN_RESET); // Segment 3
    HAL_GPIO_WritePin(SEG_4_GPIO_Port, SEG_4_Pin, (pattern1 & 0b00010000) ? GPIO_PIN_SET : GPIO_PIN_RESET); // Segment 4
    HAL_GPIO_WritePin(SEG_5_GPIO_Port, SEG_5_Pin, (pattern1 & 0b00100000) ? GPIO_PIN_SET : GPIO_PIN_RESET); // Segment 5
    HAL_GPIO_WritePin(SEG_6_GPIO_Port, SEG_6_Pin, (pattern1 & 0b01000000) ? GPIO_PIN_SET : GPIO_PIN_RESET); // Segment 6


    HAL_GPIO_WritePin(SEG_01_GPIO_Port, SEG_01_Pin, (pattern2 & 0b00000001) ? GPIO_PIN_SET : GPIO_PIN_RESET); // Segment 0
    HAL_GPIO_WritePin(SEG_11_GPIO_Port, SEG_11_Pin, (pattern2 & 0b00000010) ? GPIO_PIN_SET : GPIO_PIN_RESET); // Segment 1
    HAL_GPIO_WritePin(SEG_21_GPIO_Port, SEG_21_Pin, (pattern2 & 0b00000100) ? GPIO_PIN_SET : GPIO_PIN_RESET); // Segment 2
    HAL_GPIO_WritePin(SEG_31_GPIO_Port, SEG_31_Pin, (pattern2 & 0b00001000) ? GPIO_PIN_SET : GPIO_PIN_RESET); // Segment 3
    HAL_GPIO_WritePin(SEG_41_GPIO_Port, SEG_41_Pin, (pattern2 & 0b00010000) ? GPIO_PIN_SET : GPIO_PIN_RESET); // Segment 4
    HAL_GPIO_WritePin(SEG_51_GPIO_Port, SEG_51_Pin, (pattern2 & 0b00100000) ? GPIO_PIN_SET : GPIO_PIN_RESET); // Segment 5
    HAL_GPIO_WritePin(SEG_61_GPIO_Port, SEG_61_Pin, (pattern2 & 0b01000000) ? GPIO_PIN_SET : GPIO_PIN_RESET); // Segment 6
}


void displayAll7SEG() {
	if (timer_flag[3] == 1) {
		setTimer(3, 500);
		turn = !turn;
	}

	// Toggle the displayed segment
	if (turn == 0) {
	    HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, SET);
	    HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, RESET);
	    display7SEG(SEGvalue1 / 10, SEGvalue1 % 10);
	} else {
	    HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, RESET);
	    HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, SET);
	    display7SEG(SEGvalue2 / 10, SEGvalue2 % 10);
	}
}



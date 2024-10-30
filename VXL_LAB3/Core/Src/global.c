/*
 * global.c
 *
 *
 *
 */

#include "global.h"

int status1 = INIT;
int status2 = INIT;

int redDuration = 5000;      // Default 5 seconds
int yellowDuration = 2000;   // Default 2 seconds
int greenDuration = 3000;    // Default 3 seconds

int current_timer_value1 = 0; // Holds the remaining time for Pair 1
int current_timer_value2 = 0; // Holds the remaining time for Pair 2

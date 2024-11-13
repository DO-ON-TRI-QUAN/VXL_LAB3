/*
 * global.h
 *
 *
 *
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#define INIT	1

#define AUTO_RED1     2
#define AUTO_RED2     3
#define AUTO_YELLOW1  4
#define AUTO_YELLOW2  5
#define AUTO_GREEN1   6
#define AUTO_GREEN2   7

extern int status1;
extern int status2;

int mode;
int previousMode;

int redDuration;      // Default 5 seconds
int yellowDuration;   // Default 2 seconds
int greenDuration;    // Default 3 seconds

int redIncreaseValue;
int yellowIncreaseValue;
int greenIncreaseValue;

void getMode();

#endif /* INC_GLOBAL_H_ */

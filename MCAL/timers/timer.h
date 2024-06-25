/*
 * timer.h
 *
 * Created: 1/1/2023 1:46:42 AM
 *  Author: DELL
 */ 


#ifndef TIMER_H_
#define TIMER_H_

#include "../../Utilities/bit/bitmanipulation.h"
#include <math.h>

#define PRESCALER 1  // setting prescaler
#define cpu 1000000//1Mhz
#define tick PRESCALER // tick macro
#define MAX_DELAY 256*tick // max delay macro

#define NumberOfOverflow(seconds) (((seconds)/(MAX_DELAY))+(1)) // number of overflow 
#define INITIAL_TIME(seconds) (256)-(((seconds)/(tick))/(NumberOfOverflow(seconds))) // seconds in milliseconds Setting inital time

enum TIMER_MODE {
	NORMAL,PWM,CTC,FAST_PWM
	};


uint32_t no_overflow;

// function prototype 
void SET_MODE(uint8_t mode);
void START_TIME(uint32_t prescaler);// starting time
void DELAY(uint32_t seconds); // delay function in milliseconds
void SET_TIME(); // setting inital time function
void STOP_TIMER();



#endif /* TIMER_H_ */
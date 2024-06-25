/*
 * timer.c
 *
 * Created: 12/29/2022 4:49:20 PM
 *  Author: DELL
 */ 

#include "timer.h"

 

void SET_MODE(uint8_t mode)
{
	switch(mode)// chose mode
	{
		case NORMAL:
		{
			CLEAR_PIN(3,TTCR0);
			CLEAR_PIN(6,TTCR0);
			break;
		}
		case PWM:
		{
			SET_PIN(6,TTCR0);
			CLEAR_PIN(3,TTCR0);
			break;
		}
		case CTC:
		{
			SET_PIN(3,TTCR0);
			CLEAR_PIN(6,TTCR0);
			break;
			
		}
		case FAST_PWM:
		{
			SET_PIN(3,TTCR0);
			SET_PIN(6,TTCR0);
			break;
		}
	}
}



void SET_TIME(uint32_t seconds) // set initial value
{
	*TCNT0=INITIAL_TIME(seconds);// setting counter register
	//*TTCR0=0x00; // starting time timer mode normal 
}
void START_TIME(uint32_t prescaler)
{
	switch(prescaler)// prescaler
	{
		case 0://no prescaler
		{
			*TTCR0=0x00;
			break;
		}
		case 1:// prescaler 1
		{
			SET_PIN(0,TTCR0);
			
			break;
		}
		case 8:// prescaler 8
		{
			SET_PIN(1,TTCR0);	
			break;
		}
		case 64:// prescaler 64
		{
			SET_PIN(0,TTCR0);
			SET_PIN(1,TTCR0);
			break;
		}
		case 256:// prescaler 256
		{
			SET_PIN(0,TTCR0);
			break;
		}
		case 1024:// prescaler 1024
		{
			SET_PIN(0,TTCR0);
			SET_PIN(2,TTCR0);
			break;
		}
		
	}
}
void STOP_TIMER()
{
	*TTCR0=0x00;// stopping  time
}



void DELAY(uint32_t seconds)//in miliseconds
{
	 // overflow counter
	SET_TIME(seconds);// setting time with initial time
	START_TIME(1); // start time
	if(press==PRESS && presscount==1)
	{
		no_overflow=(1000)*(NumberOfOverflow(seconds));// making overflow equal to nmber of flows to break from normal mode
	}
	else
	{
		no_overflow=0;
	}
	while(no_overflow<(1000)*(NumberOfOverflow(seconds))) // macros to get tick and max delay
	{
		
		while((*(TIFR) &(1<<0))==0);//wait for overflow flag
		SET_PIN(0,TIFR);  // clearing flag by software set pin to 1 datasheet
		no_overflow++;//count up
		if(press==PRESS && presscount==1)
		{
			no_overflow=(1000)*(NumberOfOverflow(seconds));// making overflow equal to nmber of flows to break from normal mode
		}
		
	}
	
	//stop time
	STOP_TIMER();
}



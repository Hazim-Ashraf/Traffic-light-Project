/*
 * Interrputs.c
 *
 * Created: 1/2/2023 4:49:18 PM
 *  Author: DELL
 */ 

#include "intre.h"

void ENABLE_INTR(uint8_t PinNumber){	SET_PIN(PinNumber,GICR);// setting pin to 1	sei();// enable serial register interrupt }	void INTRE_SENSE(uint8_t PinNumber,uint8_t control){	switch(PinNumber)// which pin 	{		case 6://INT0		{				switch(control)//which type			{				case 0:				{					CLEAR_PIN(0,MCUCR);//low level					CLEAR_PIN(1,MCUCR);					break;				}				case 1:				{					SET_PIN(0,MCUCR);//logical					CLEAR_PIN(1,MCUCR);					break;				}				case 2:// falling edge 				{					SET_PIN(1,MCUCR);					CLEAR_PIN(0,MCUCR);					break;				}				case 3:// rising edge				{					SET_PIN(1,MCUCR);					SET_PIN(0,MCUCR);					break;			    }			}			break;		}		case 7://INT1		{				switch(control)//whcih type 				{					case 0:					{						CLEAR_PIN(2,MCUCR);//low level						CLEAR_PIN(3,MCUCR);						break;					}					case 1:					{						SET_PIN(2,MCUCR);//logical						CLEAR_PIN(3,MCUCR);						break;					}					case 2:// falling edge 					{						SET_PIN(3,MCUCR);						CLEAR_PIN(2,MCUCR);						break;					}					case 3:// rising edge					{						SET_PIN(3,MCUCR);						SET_PIN(2,MCUCR);						break;					}				}				break;		}	}}
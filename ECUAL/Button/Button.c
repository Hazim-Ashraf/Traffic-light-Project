/*
 * Button.c
 *
 * Created: 12/29/2022 4:47:47 PM
 *  Author: DELL
 */ 

#include "button.h"

void BUTTON_init(uint8_t pinNumber,uint8_t PortNumber,uint8_t Direction)
{
	DIO_init(pinNumber,PortNumber,INPUT);// initialize pin as input
}
void BUTTON_read(uint8_t pinNumber,uint8_t PortNumber,uint8_t* pressed)// store the state in pressed varaible char
{
	switch(PortNumber)// which port
	{
		case 'A':
		{
			READ_PIN(pinNumber,PINA,pressed);// Read state on the pin pressed or not
			break;
		}
		case 'B':
		{
			READ_PIN(pinNumber,PINB,pressed);// Read state on the pin pressed or not
			break;
		}
		case 'C':
		{
			READ_PIN(pinNumber,PINC,pressed);// Read state on the pin pressed or not
			break;
		}
		case 'D':
		{
			READ_PIN(pinNumber,PIND,pressed);// Read state on the pin pressed or not
			break;
		}
	}
	
}

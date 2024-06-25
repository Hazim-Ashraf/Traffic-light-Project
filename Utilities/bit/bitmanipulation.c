/*
 * bitmanipulation.c
 *
 * Created: 12/29/2022 6:00:34 PM
 *  Author: DELL
 */ 

#include "bitmanipulation.h"


void SET_PIN(uint8_t pinNumber,volatile uint8_t* PortNumber)//set pin to 1
{
	*PortNumber |=(1<<pinNumber);// dereferencing the register on a certain pin to 1 
	
}
void CLEAR_PIN(uint8_t pinNumber,volatile uint8_t* PortNumber)//set pin to 0{
	{
			*PortNumber &=~(1<<pinNumber);// dereferencing the register on a certain pin to 0
		
	}
void READ_PIN(uint8_t pinNumber,volatile uint8_t *PortNumber,uint8_t *value) //read pin value
{
		*value= (*PortNumber&(1<<pinNumber))>>pinNumber; //reading the pin dereferencing t
}

void TOGGLE_PIN(uint8_t pinNumber,volatile uint8_t* PortNumber,uint8_t PortName)
{
	uint8_t value;// value to store the reading 
	READ_PIN(pinNumber,PortNumber,&value);//read pin
	
	
	switch(PortName)// which port
	{
		case 'A':
		{
			if(value==HIGH)//if it is set to be high set pin to 1
			{
				
				CLEAR_PIN(pinNumber,PORTA);//clear
			}
			else if(value==LOW)//if it is set to be low set pin to 1
			{
				SET_PIN(pinNumber,PORTA);//set
			}
			break;
		}
		case 'B':
		{
			if(value==HIGH)//if it is set to be high set pin to 1
			{
				CLEAR_PIN(pinNumber,PORTB);//clear
			}
			else if(value==LOW)//if it is set to be low set pin to 1
			{
				SET_PIN(pinNumber,PORTB);//set
			}
			break;
		}
		case 'C':
		{
			if(value==HIGH)//if it is set to be high set pin to 1
			{
				CLEAR_PIN(pinNumber,PORTC);//clear
			}
			else if(value==LOW)//if it is set to be low set pin to 1
			{
				SET_PIN(pinNumber,PORTC);//set
			}
			break;
		}
		case 'D':
		{
			if(value==HIGH)//if it is set to be high set pin to 1
			{
				CLEAR_PIN(pinNumber,PORTD);//clear
			}
			else if(value==LOW)//if it is set to be low set pin to 1
			{
				SET_PIN(pinNumber,PORTD);//set
			}
			break;
		}
	}
}
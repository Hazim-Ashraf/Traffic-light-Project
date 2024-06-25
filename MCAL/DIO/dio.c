/*
 * dio.c
 *
 * Created: 12/29/2022 4:48:24 PM
 *  Author: DELL
 */ 

#include "dio.h"



void DIO_init(uint8_t pinNumber,uint8_t PortNumber,uint8_t Direction) // to initialize the pin
{
	switch(PortNumber)// wich port 
	{
		case 'A':
		{
	if(Direction==OUTPUT)//if it is set to be output set pin to 1
	{
		SET_PIN(pinNumber,DDRA);
	}
	else if(Direction==INPUT)
	{
		CLEAR_PIN(pinNumber,DDRA);//if it is set to be output set pin to 0
	}
	break;
		}
	case 'B':
		{
			if(Direction==OUTPUT)//if it is set to be output set pin to 1
			{
				SET_PIN(pinNumber,DDRB);
			}
			else if(Direction==INPUT)
			{
				CLEAR_PIN(pinNumber,DDRB);//if it is set to be output set pin to 0
			}
			break;
		}
		case 'C':
		{
			if(Direction==OUTPUT)//if it is set to be output set pin to 1
			{
				SET_PIN(pinNumber,DDRC);
			}
			else if(Direction==INPUT)
			{
				CLEAR_PIN(pinNumber,DDRC);//if it is set to be output set pin to 0
			}
			break;
		}
		case 'D':
		{
			if(Direction==OUTPUT)//if it is set to be output set pin to 1
			{
				SET_PIN(pinNumber,DDRD);
			}
			else if(Direction==INPUT)
			{
				CLEAR_PIN(pinNumber,DDRD);//if it is set to be output set pin to 0
			}
			break;
		}
	}
}
void DIO_read(uint8_t pinNumber,uint8_t PortNumber,uint8_t *value)	//to read
{
switch(PortNumber)// which port
{
	case 'A':
	{
		READ_PIN(pinNumber,PINA,value);// read the value on the pin
		break;
	}
	case 'B':
	{
		READ_PIN(pinNumber,PINB,value);// read the value on the pin
		break;
	}
	case 'C':
	{
		READ_PIN(pinNumber,PINC,value);// read the value on the pin
		break;
	}
	case 'D':
	{
		READ_PIN(pinNumber,PIND,value);// read the value on the pin
		break;
	}
}
}
void DIO_write(uint8_t pinNumber,uint8_t PortNumber,uint8_t State) 
{
switch(PortNumber)// which port
	{
	case 'A':
	{
		if(State==HIGH)//if it is set to be output set pin to 1
		{
			
			SET_PIN(pinNumber,PORTA);
		}
		else if(State==LOW)
		{
			CLEAR_PIN(pinNumber,PORTA);//if it is set to be output set pin to 0
		}
	break;
	}
	case 'B':
	{
		if(State==HIGH)//if it is set to be output set pin to 1
		{
			SET_PIN(pinNumber,PORTB);
		}
		else if(State==LOW)
		{
			CLEAR_PIN(pinNumber,PORTB);//if it is set to be output set pin to 0
		}
		break;
	}
	case 'C':
	{
		if(State==HIGH)//if it is set to be output set pin to 1
		{
			SET_PIN(pinNumber,PORTC);
		}
		else if(State==LOW)
		{
			CLEAR_PIN(pinNumber,PORTC);//if it is set to be output set pin to 0
		}
		break;
	}
	case 'D':
	{
		if(State==HIGH)//if it is set to be output set pin to 1
		{
			SET_PIN(pinNumber,PORTD);
		}
		else if(State==LOW)
		{
			CLEAR_PIN(pinNumber,PORTD);//if it is set to be output set pin to 0
		}
		break;
	}
}
}
void DIO_toggle(uint8_t pinNumber,uint8_t PortNumber)	//to toggle if 1 be zero and otherwise
{
switch(PortNumber)// which port
{
	case 'A':
	{
		TOGGLE_PIN(pinNumber,PINA,'A');// toggle pin if 1 be 0 and otherwise
		break;
	}
	case 'B':
	{
		TOGGLE_PIN(pinNumber,PINB,'B');// toggle pin if 1 be 0 and otherwise
		break;
	}
	case 'C':
	{
		TOGGLE_PIN(pinNumber,PINC,'C');// toggle pin if 1 be 0 and otherwise
		break;
	}
	case 'D':
	{
		TOGGLE_PIN(pinNumber,PIND,'D');// toggle pin if 1 be 0 and otherwise
		break;
	}
}
}

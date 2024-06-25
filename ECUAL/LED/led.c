/*
 * led.c
 *
 * Created: 12/29/2022 4:44:59 PM
 *  Author: DELL
 */ 
#include "led.h"

void LED_ON(uint8_t pinNumber,uint8_t PortNumber)
{
	DIO_write(pinNumber, PortNumber, HIGH);////Led initializing pin to be high
}
void LED_OFF(uint8_t pinNumber,uint8_t PortNumber)
{
	DIO_write(pinNumber, PortNumber,LOW);////Led initializing pin to be LOW
}
void LED_TOGGLE(uint8_t pinNumber,uint8_t PortNumber)
{
	DIO_toggle(pinNumber,PortNumber);////Led initializing pin to act as a toggle
}
void LED_INIT(uint8_t pinNumber,uint8_t PortNumber)
{
	DIO_init( pinNumber, PortNumber,OUTPUT);////Led initializing pin to be output
}
void LED_BLINK(uint8_t pinNumber,uint8_t PortNumber,uint32_t times) //times in seconds 
{
	while(times>0)// time loop
	{
		flag_blink=1;
		LED_TOGGLE(pinNumber,PortNumber);// toggle led 
		//no_overflow=0;// reset nomber of overflows
	DELAY(1000);//in milliseconds blink every seconds 5 times means 500 milliseconds
	times--; // times is seconds 
	}
	flag_blink=0;
}
// blink function for two leds same steps as above add  other led
void LED_BLINK2(uint8_t pinNumber,uint8_t PortNumber,uint8_t pinNumber2,uint8_t PortNumber2,uint32_t times)
{
	while(times>0)
	{
		flag_blink=1;
		LED_TOGGLE(pinNumber,PortNumber);// toggling both leds 
		LED_TOGGLE(pinNumber2,PortNumber2);
		DELAY(1000);//in milliseconds blink every seconds 5 times means 500 milliseconds
		times--; // times is seconds
	}
	flag_blink=0;
}
/*
 * led.h
 *
 * Created: 12/29/2022 8:11:25 PM
 *  Author: DELL
 */ 


#ifndef LED_H_
#define LED_H_

#include "../../MCAL/DIO/dio.h"
#include "../../MCAL/timers/timer.h"
#include "../../MCAL/interrupts/intre.h"

void LED_INIT(uint8_t pinNumber,uint8_t PortNumber);// LEd Initializing taking pin number and portnumber
void LED_ON(uint8_t pinNumber,uint8_t PortNumber);// Led on function taking pin number and portnumber
void LED_OFF(uint8_t pinNumber,uint8_t PortNumber);//Led off function taking pin number and portnumber
void LED_TOGGLE(uint8_t pinNumber,uint8_t PortNumber);//Led toggle function taking pin number and portnumber
void LED_BLINK(uint8_t pinNumber,uint8_t PortNumber,uint32_t times);//Led blink functionfor 1 led taking pin number and portnumber and time to blink
void LED_BLINK2(uint8_t pinNumber,uint8_t PortNumber,uint8_t pinNumber2,uint8_t PortNumber2,uint32_t times);//Led blink function for two leds taking pin number and portnumber and time to blink


#endif /* LED_H_ */
/*
 * button.h
 *
 * Created: 12/29/2022 8:43:31 PM
 *  Author: DELL
 */ 


#ifndef BUTTON_H_
#define BUTTON_H_

#include "../../Utilities/bit/bitmanipulation.h"
#include "../../MCAL/DIO/dio.h"
#include "../../MCAL/timers/timer.h"
#include "../../MCAL/interrupts/intre.h"


void BUTTON_init(uint8_t pinNumber,uint8_t PortNumber,uint8_t Direction);// button initializing taking pin number and portnumber and its direction input
void BUTTON_read(uint8_t pinNumber,uint8_t PortNumber,uint8_t* pressed);// Reading button state taking pin number and portnumber store it in varaible pressed



#endif /* BUTTON_H_ */
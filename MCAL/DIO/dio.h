/*
 * dio.h
 *
 * Created: 12/29/2022 5:00:34 PM
 *  Author: DELL
 */ 


//#include <avr/io.h>

#ifndef DIO_H_
#define DIO_H_

#include "../../Utilities/bit/bitmanipulation.h"


void DIO_init(uint8_t pinNumber,uint8_t PortNumber,uint8_t Direction); // to initialize the pin taking pin number and portnumber and its direction in or out
void DIO_read(uint8_t pinNumber,uint8_t PortNumber,uint8_t *value);	//to read taking pin number and portnumber and value to store in it
void DIO_write(uint8_t pinNumber,uint8_t PortNumber,uint8_t State);  // to write on the pin make it high or low taking  pin number and portnumber and their state to be on
void DIO_toggle(uint8_t pinNumber,uint8_t PortNumber);	//to toggle to toggle the pin 






#endif /* DIO_H_ */
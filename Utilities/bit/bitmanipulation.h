/*
 * bitmanipulation.h
 *
 * Created: 12/29/2022 4:52:47 PM
 *  Author: DELL
 */ 


#ifndef BITMANIPULATION_H_
#define BITMANIPULATION_H_
#include "../types.h"


void SET_PIN(uint8_t pinNumber,volatile uint8_t *PortNumber);//set pin to 1 taking pinnumber and register pointer
void CLEAR_PIN(uint8_t pinNumber,volatile uint8_t *PortNumber);//set pin to 0 taking pinnumber and register pointer
void READ_PIN(uint8_t pinNumber,volatile uint8_t* PortNumber,uint8_t *value); //read pin value taking pinnumber and register pointer and variable to store the readings
void TOGGLE_PIN(uint8_t pinNumber,volatile uint8_t* PortNumber,uint8_t PortName);// toggle pin taking pinnumber and register pointer and portname




#endif /* BITMANIPULATION_H_ */
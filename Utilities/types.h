/*
 * types.h
 *
 * Created: 12/29/2022 5:24:07 PM
 *  Author: DELL
 */ 


#ifndef TYPES_H_
#define TYPES_H_

#include "register.h"
 // typedefs 
typedef unsigned int uint32_t;
typedef signed int int32_t;
typedef unsigned char uint8_t;
typedef signed char int8_t;
typedef unsigned short uint16_t;
typedef signed short int16_t;
typedef unsigned long uint64_t;
typedef signed long int64_t;

typedef  float float32_t;
typedef  double double64_t;


//High or low
#define HIGH 1
#define LOW 0

// in or out
#define INPUT 0
#define OUTPUT 1

//Button
#define PRESS 1
#define NOT_PRESSED 0

// portNames
#define PORT_A 'A'
#define PORT_B 'B'
#define PORT_C 'C'
#define PORT_D 'D'

// leds cars portA pins
#define LEDG_C 2
#define LEDY_C 1
#define LEDR_C 0

//leds pedestrians port B pins
#define LEDG_P 2
#define LEDY_P 1
#define LEDR_P 0

//Buttons PortD
#define INT0 6 // interrupt pin 
#define BUTTON 2 // button pin


// read whether the button is pressed or not
uint8_t presscount;
uint8_t press;


// cars led states
uint8_t stateGC;
uint8_t stateYC;
uint8_t stateRC;

uint8_t flag_blink;


// cases macros
#define CaseRED 1
#define Case2 2
#define normal 0

uint8_t state;

enum  CONTROL// type of interrupt{	LOW_LEVEL,LOGICAL,FALLING_EDGE,RISING_EDGE};

#endif /* TYPES_H_ */
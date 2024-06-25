/*
 * intre.h
 *
 * Created: 12/29/2022 4:50:04 PM
 *  Author: DELL
 */ 


#ifndef INTRE_H_
#define INTRE_H_

#include "../../Utilities/bit/bitmanipulation.h"

#define sei()  __asm__ __volatile__ ("sei" ::: "memory") // SREG to enable interrputs

#define cli() __asm__ __volatile__ ("cli" ::: "memory") // SREG disable interrputs 

// macros for external interrputs vectors 
// vector 0 is the reset vector 
#define EXT_INT_0  __vector_1  // request for INT0
#define EXT_INT_1  __vector_2  // request for INT1
#define EXT_INT_2  __vector_3  // request for INT2
#define TIMER_0_OVF __vector_11 // timer overflow 

#define ISR(INT_VECT)void INT_VECT(void) __attribute__ ((signal,used));\
void INT_VECT(void)   // ISR macrovoid ENABLE_INTR(uint8_t PinNumber); // enable function enables Global interrupt and Serial register void INTRE_SENSE(uint8_t PinNumber,uint8_t control); // type of interrupt function


#endif /* INTRE_H_ */
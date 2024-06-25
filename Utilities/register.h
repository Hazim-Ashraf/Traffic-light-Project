/*
 * register.h
 *
 * Created: 12/29/2022 4:52:13 PM
 *  Author: DELL
 */ 


#ifndef REGISTER_H_
#define REGISTER_H_

// port A registers
#define PORTA (volatile uint8_t*)0x3B// register state high or low 
#define DDRA (volatile uint8_t*)0x3A //DIO_init register in or out
#define PINA (volatile uint8_t*)0x39 // reading register
// port b registers

#define PORTB (volatile uint8_t*)0x38// register state high or low 
#define DDRB (volatile uint8_t*)0x37 //DIO_init register in or out
#define PINB (volatile uint8_t*)0x36 // reading register
// port c registers

#define PORTC (volatile uint8_t*)0x35// register state high or low
#define DDRC (volatile uint8_t*)0x34 //DIO_init register in or out
#define PINC (volatile uint8_t*)0x33 // reading register

// port c registers

#define PORTD (volatile uint8_t*)0x32		// register state high or low 
#define DDRD (volatile uint8_t*)0x31 //DIO_init register in or out 
#define PIND (volatile uint8_t*)0x30 // reading register 

// timer registers

#define TIFR (volatile uint8_t*)0x58   //timer flag
#define TTCR0 (volatile uint8_t*)0x53  // timer mode
#define TCNT0 (volatile uint8_t*)0x52  // timer start 

// Interrupts register 

#define MCUCR (volatile uint8_t*)0x55   //interrputs mode 
#define MCUCSR (volatile uint8_t*)0x54  // interrputs mode INT2 start
#define GICR (volatile uint8_t*)0x5B  // interrputs start
#define GIFR (volatile uint8_t*)0x5A  // Interrputs flag 






#endif /* REGISTER_H_ */
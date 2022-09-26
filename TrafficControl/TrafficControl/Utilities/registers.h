/*
 * registers.h
 *
 * Created: 8/31/2022 10:49:39 PM
 *  Author: Mohamed Ahmed Mohamed Ibrahim
 */ 

/************************************************************************/
/* All micro controller registers                                        */
/************************************************************************/
#ifndef REGISTERS_H_
#define REGISTERS_H_

#include "util.h"

// register bits in 8-bit registers
#define BIT0 0
#define BIT1 1
#define BIT2 2
#define BIT3 3
#define BIT4 4
#define BIT5 5
#define BIT6 6
#define BIT7 7

/************************************************************************/
/* DIO registers                                                        */
/************************************************************************/

// PORTA registers
#define PORTA *((volatile uint8_t*)0x3B) // 8-bit register
#define DDRA *((volatile uint8_t*)0x3A) // 8-bit register
#define PINA *((volatile uint8_t*)0x39) // 8-bit register

// PORTB registers
#define PORTB *((volatile uint8_t*)0x38) // 8-bit register
#define DDRB *((volatile uint8_t*)0x37) // 8-bit register
#define PINB *((volatile uint8_t*)0x36) // 8-bit register

// PORTC registers
#define PORTC *((volatile uint8_t*)0x35) // 8-bit register
#define DDRC *((volatile uint8_t*)0x34) // 8-bit register
#define PINC *((volatile uint8_t*)0x33) // 8-bit register

// PORTD registers
#define PORTD *((volatile uint8_t*)0x32) // 8-bit register
#define DDRD *((volatile uint8_t*)0x31) // 8-bit register
#define PIND *((volatile uint8_t*)0x30) // 8-bit register

/************************************************************************/
/* Timer registers                                                      */
/************************************************************************/

// Timer0 registers
#define TCCR0 *((volatile uint8_t*)0x53) // 8-bit register
	// Clock Select
	#define CS00 BIT0
	#define CS01 BIT1
	#define CS02 BIT2
#define TCNT0 *((volatile uint8_t*)0x52) // 8-bit register
#define TIMSK *((volatile uint8_t*)0x59) // 8-bit register
	// Overflow interrupt enable
	#define TOIE0 BIT0
#define TIFR *((volatile uint8_t*)0x58) // 8-bit register
	// TIFR over flow flag
	#define TOV0 BIT0
	
/************************************************************************/
/* External interrupts                                                  */
/************************************************************************/

#define MCUCR *((volatile uint8_t*)0x55) // 8-bit register
	// ISC01 & ISC00 Interrupt sense control 0
	#define ISC00 BIT0
	#define ISC01 BIT1
	// ISC11 & ISC10 Interrupt sense control 1
	#define ISC10 BIT2
	#define ISC11 BIT3
#define MCUCSR *((volatile uint8_t*)0x54) // 8-bit register
	// ISC2
	#define ISC2 BIT6
#define GICR *((volatile uint8_t*)0x5B) // 8-bit register 
	// INT2 external interrupt request
	#define INT2 BIT5
	// INT0 external interrupt request
	#define INT0 BIT6
	// INT1 external interrupt request 
	#define INT1 BIT7
#define GIFR *((volatile uint8_t*)0x5A) // 8-bit register
	// INTF2 external interrupt request
	#define INT2 BIT5
	// INTF0 external interrupt request
	#define INT0 BIT6
	// INTF1 external interrupt request
	#define INT1 BIT7

/************************************************************************/
/* ADC registers                                                        */
/************************************************************************/

#define ADMUX *((volatile uint8_t*)0x27) // 8-bit register
	// REFS1 & REFS0 Reference selection bits
	#define REFS1 BIT7
	#define REFS0 BIT6
	// ADLAR ADC left adjust result bit
	#define ADLAR BIT5
#define ADCSRA *((volatile uint8_t*)0x26) // 8-bit register
	// ADC enable bit
	#define ADEN BIT7
	// ADC start conversion bit
	#define ADSC BIT6
	// ADC interrupt flag
	#define ADIF BIT4
#define ADCH *((volatile uint8_t*)0x25) // 8-bit register
#define ADCL *((volatile uint8_t*)0x24) // 8-bit register

#endif /* REGISTERS_H_ */
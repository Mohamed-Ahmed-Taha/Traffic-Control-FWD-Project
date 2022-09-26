/*
 * intrupts.h
 *
 * Created: 9/3/2022 2:08:49 AM
 *  Author: Mohamed Ahmed Mohamed Ibrahim
 */ 


#ifndef INTERRUPTS_H_
#define INTERRUPTS_H_

#include "../../Utilities/util.h"
#include "../../Utilities/registers.h"
#include "../../Utilities/ports_pins.h"


// error handle
#define INTERRUPT_OK 0
#define INTERRUPT_WRONG_INT_NUM 1
#define INTERRUPT_WRONG_INT_SENSE_CONTROL 2

// external interrupt number
#define EXT_INT_0 0
#define EXT_INT_1 1
#define EXT_INT_2 2

// external interrupt 0
#define EXT_INT_0_PORT PORT_D
#define EXT_INT_0_PIN PIN2

// external interrupt 1
#define EXT_INT_1_PORT PORT_D
#define EXT_INT_1_PIN PIN3

// external interrupt 2
#define EXT_INT_2_PORT PORT_B
#define EXT_INT_2_PIN PIN2

// sense control cases
#define LOW_LEVEL_INT_REQ 0
#define ANY_LOGICAL_CHANGE_INT_REQ 1
#define FALLING_EDGE_INT_REQ 2
#define RISING_EDGE_INT_REQ 3


// set Global Interrupts, Set the I-bit in status register to 1
#define sei() __asm__ __volatile__ ("sei" ::: "memory")

// clear Global Interrupts, Set the I-bit in status register to 0
#define cli() __asm__ __volatile__ ("cli" ::: "memory")

// Interrupt service routine definition
#define ISR(INT_VECT)void INT_VECT(void) __attribute__ ((signal, used));\
void INT_VECT(void)

// Interrupt vector table
#define EXT_INT_0_vect __vector_1
#define EXT_INT_1_vect __vector_2
#define EXT_INT_2_vect __vector_3


// init external interrupt function
uint8_t INTERRUPT_init(uint8_t extIntPin, uint8_t senseControl);


#endif /* INTERRUPTS_H_ */
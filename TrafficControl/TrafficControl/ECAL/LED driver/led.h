/*
 * led.h
 *
 * Created: 9/1/2022 6:12:47 PM
 *  Author: Mohamed Ahmed Mohamed Ibrahim
 */ 


#ifndef LED_H_
#define LED_H_

#include "../../MCAL/DIO driver/dio.h"

// error handle
#define LED_OK 0
#define LED_WRONG_PORT_NUMBER 1
#define LED_WRONG_PIN_NUMBER 2
#define LED_WRONG_TOGGLE 3

// global variable if specialFunCallback is used in led blink
// global pointer to function for led blink

// all driver function prototypes
uint8_t LED_init(uint8_t ledPort, uint8_t ledPin); // initialize led
uint8_t LED_on(uint8_t ledPort, uint8_t ledPin); // led on
uint8_t LED_off(uint8_t ledPort, uint8_t ledPin); // led off
uint8_t LED_toggle(uint8_t ledPort, uint8_t ledPin); // led off


#endif /* LED_H_ */
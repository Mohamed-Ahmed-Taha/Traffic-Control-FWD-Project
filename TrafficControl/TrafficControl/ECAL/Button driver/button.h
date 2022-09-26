/*
 * button.h
 *
 * Created: 9/1/2022 9:13:55 PM
 *  Author: Mohamed Ahmed Mohamed Ibrahim
 */ 


#ifndef BUTTON_H_
#define BUTTON_H_

#include "../../MCAL/DIO driver/dio.h"

// button state
#define LOW		0
#define HIGH	1

// error handle
#define BUTTON_OK 0
#define BUTTON_WRONG_PORT_NUMBER 1
#define BUTTON_WRONG_PIN_NUMBER 2


// button initialization
uint8_t BUTTON_init(uint8_t buttonPort, uint8_t buttonPin); 

// check button
uint8_t BUTTON_read(uint8_t buttonPort, uint8_t buttonPin, uint8_t* value); 



#endif /* BUTTON_H_ */
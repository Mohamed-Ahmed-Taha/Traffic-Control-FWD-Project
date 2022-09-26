/*
 * dio.h
 *
 * Created: 8/31/2022 11:09:23 PM
 *  Author: Mohamed Ahmed Mohamed Ibrahim
 */ 


#ifndef DIO_H_
#define DIO_H_

#include "../../Utilities//util.h"
#include "../../Utilities/registers.h"
#include "../../Utilities/microship_properties.h"
#include "../../Utilities/ports_pins.h"



// error handle
#define DIO_OK 0
#define DIO_WRONG_INIT_DIRECTION 1
#define DIO_WRONG_PORT_NUMBER 2
#define DIO_WRONG_PIN_NUMBER 3
#define DIO_WRONG_WRITE_VALUE 4
#define DIO_WRONG_TOGGLE 5

// Direction defines
#define IN 0
#define OUT 1

// Value defines
#define LOW 0
#define HIGH 1

// all driver function prototypes
uint8_t DIO_init(uint8_t portNumber, uint8_t pinNumber, uint8_t direction); // Initialize DIO direction

uint8_t DIO_write(uint8_t portNumber, uint8_t pinNumber, uint8_t value); // Write data on DIO

uint8_t DIO_toggle(uint8_t portNumber, uint8_t pinNumber); // Toggle date on DIO

uint8_t DIO_read(uint8_t portNumber, uint8_t pinNumber, uint8_t* value); // Read DIO


#endif /* DIO_H_ */
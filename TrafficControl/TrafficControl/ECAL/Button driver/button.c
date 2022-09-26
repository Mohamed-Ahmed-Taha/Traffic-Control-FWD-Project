/*
 * button.c
 *
 * Created: 9/1/2022 9:13:45 PM
 *  Author: Mohamed Ahmed Mohamed Ibrahim
 */ 

#include "button.h"

uint8_t BUTTON_init(uint8_t buttonPort, uint8_t buttonPin)
{
	uint8_t BUTTONState = DIO_init(buttonPort, buttonPin, IN);
	if (BUTTONState == DIO_WRONG_PORT_NUMBER)
	{
		return BUTTON_WRONG_PORT_NUMBER;
	}
	else if (BUTTONState == DIO_WRONG_PIN_NUMBER)
	{
		return BUTTON_WRONG_PIN_NUMBER;
	}
	else if (BUTTONState == DIO_OK)
	{
		return BUTTON_OK;
	}
}
uint8_t BUTTON_read(uint8_t buttonPort, uint8_t buttonPin, uint8_t* value) 
{
	uint8_t BUTTONState = DIO_read(buttonPort, buttonPin, value);
	if (BUTTONState == DIO_WRONG_PORT_NUMBER)
	{
		return BUTTON_WRONG_PORT_NUMBER;
	}
	else if (BUTTONState == DIO_WRONG_PIN_NUMBER)
	{
		return BUTTON_WRONG_PIN_NUMBER;
	}
	else if (BUTTONState == DIO_OK)
	{
		return BUTTON_OK;
	}
}

// driver test
#if 0

int main()
{
	BUTTON_init('A', 3);
	BUTTON_init(5, 3);
	BUTTON_init('A', 8);
	
	uint8_t value;
	BUTTON_read('A', 3, &value);
	BUTTON_read(5, 3, &value);
	BUTTON_read('A', 8, &value);
}

#endif
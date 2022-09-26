/*
 * led.c
 *
 * Created: 9/1/2022 6:12:56 PM
 *  Author: Mohamed Ahmed Mohamed Ibrahim
 */ 

#include "led.h"

uint8_t LED_init(uint8_t ledPort, uint8_t ledPin)
{
	uint8_t LEDState = DIO_init(ledPort, ledPin, OUT);
	if (LEDState == DIO_WRONG_PORT_NUMBER)
	{
		return LED_WRONG_PORT_NUMBER;
	}
	else if (LEDState == DIO_WRONG_PIN_NUMBER)
	{
		return LED_WRONG_PIN_NUMBER;
	}
	else if (LEDState == DIO_OK)
	{
		return LED_OK;
	}
}

uint8_t LED_on(uint8_t ledPort, uint8_t ledPin)
{
	uint8_t LEDState = DIO_write(ledPort, ledPin, HIGH);
	if (LEDState == DIO_WRONG_PORT_NUMBER)
	{
		return LED_WRONG_PORT_NUMBER;
	}
	else if (LEDState == DIO_WRONG_PIN_NUMBER)
	{
		return LED_WRONG_PIN_NUMBER;
	}
	else if (LEDState == DIO_OK)
	{
		return LED_OK;
	}
}

uint8_t LED_off(uint8_t ledPort, uint8_t ledPin)
{
	uint8_t LEDState = DIO_write(ledPort, ledPin, LOW);
	if (LEDState == DIO_WRONG_PORT_NUMBER)
	{
		return LED_WRONG_PORT_NUMBER;
	}
	else if (LEDState == DIO_WRONG_PIN_NUMBER)
	{
		return LED_WRONG_PIN_NUMBER;
	}
	else if (LEDState == DIO_OK)
	{
		return LED_OK;
	}
}
uint8_t LED_toggle(uint8_t ledPort, uint8_t ledPin)
{
	uint8_t LEDState = DIO_toggle(ledPort, ledPin);
	if (LEDState == DIO_WRONG_PORT_NUMBER)
	{
		return LED_WRONG_PORT_NUMBER;
	}
	else if (LEDState == DIO_WRONG_PIN_NUMBER)
	{
		return LED_WRONG_PIN_NUMBER;
	}
	else if (LEDState == DIO_OK)
	{
		return LED_OK;
	}
}



// driver test
#if 0

int main()
{
	LED_init('A', 0);
	LED_init(5, 0);
	LED_init('A', 8);	
	
	LED_on('A', 0);
	LED_on(5, 0);
	LED_on('A', 8);
	
	LED_off('A', 0);
	LED_off(5, 0);
	LED_off('A', 8);
	
	LED_toggle('A', 0);
	LED_toggle(5, 0);
	LED_toggle('A', 8);
}

#endif

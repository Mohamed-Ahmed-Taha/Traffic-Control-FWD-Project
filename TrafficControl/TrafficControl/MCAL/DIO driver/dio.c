/*
 * dio.c
 *
 * Created: 8/31/2022 11:09:13 PM
 *  Author: Mohamed Ahmed Mohamed Ibrahim
 */ 

#include "dio.h"

uint8_t DIO_init(uint8_t portNumber, uint8_t pinNumber, uint8_t direction)
{
	switch (portNumber) 
	{
		case PORT_A:
			if (direction == IN)
			{
				if (pinNumber >= NUMBER_OF_PINS_IN_PORT) // error handle
				{
					return DIO_WRONG_PIN_NUMBER;
				}
				clearBit(DDRA, pinNumber); // input
			}
			else if (direction == OUT) 
			{
				if (pinNumber >= NUMBER_OF_PINS_IN_PORT) // error handle
				{
					return DIO_WRONG_PIN_NUMBER;
				}
				setBit(DDRA, pinNumber); // output
			}
			else 
			{
				return DIO_WRONG_INIT_DIRECTION; // error handle
			}
		break;
		
		case PORT_B:
			if (direction == IN)
			{
				if (pinNumber >= NUMBER_OF_PINS_IN_PORT) // error handle
				{
					return DIO_WRONG_PIN_NUMBER;
				}
				clearBit(DDRB, pinNumber); // input
			}
			else if (direction == OUT)
			{
				if (pinNumber >= NUMBER_OF_PINS_IN_PORT) // error handle
				{
					return DIO_WRONG_PIN_NUMBER;
				}
				setBit(DDRB, pinNumber); // output
			}
			else
			{
				return DIO_WRONG_INIT_DIRECTION; // error handle
			}
		break;
		
		case PORT_C:
			if (direction == IN)
			{
				if (pinNumber >= NUMBER_OF_PINS_IN_PORT) // error handle
				{
					return DIO_WRONG_PIN_NUMBER;
				}
				clearBit(DDRC, pinNumber); // input
			}
			else if (direction == OUT)
			{
				if (pinNumber >= NUMBER_OF_PINS_IN_PORT) // error handle
				{
					return DIO_WRONG_PIN_NUMBER;
				}
				setBit(DDRC, pinNumber); // output
			}
			else
			{
				return DIO_WRONG_INIT_DIRECTION; // error handle
			}
		break;
		
		case PORT_D:
			if (direction == IN)
			{
				if (pinNumber >= NUMBER_OF_PINS_IN_PORT) // error handle
				{
					return DIO_WRONG_PIN_NUMBER;
				}
				clearBit(DDRD, pinNumber); // input
			}
			else if (direction == OUT)
			{
				if (pinNumber >= NUMBER_OF_PINS_IN_PORT) // error handle
				{
					return DIO_WRONG_PIN_NUMBER;
				}
				setBit(DDRD, pinNumber); // output
			}
			else
			{
				return DIO_WRONG_INIT_DIRECTION; // error handle
			}
		break;
		
		default:
			return DIO_WRONG_PORT_NUMBER; // error handle
		break;
		
	}
	
	return DIO_OK;
}

uint8_t DIO_write(uint8_t portNumber, uint8_t pinNumber, uint8_t value)
{
	switch (portNumber)
	{
		case PORT_A:
			if (value == LOW)
			{
				if (pinNumber >= NUMBER_OF_PINS_IN_PORT) // error handle
				{
					return DIO_WRONG_PIN_NUMBER;
				}
				clearBit(PORTA, pinNumber); // write 0
			}
			else if (value == HIGH)
			{
				if (pinNumber >= NUMBER_OF_PINS_IN_PORT) // error handle
				{
					return DIO_WRONG_PIN_NUMBER;
				}
				setBit(PORTA, pinNumber); // write 1
			}
			else
			{
				return DIO_WRONG_WRITE_VALUE; // error handle
			}
		break;
		
		case PORT_B:
			if (value == LOW)
			{
				if (pinNumber >= NUMBER_OF_PINS_IN_PORT) // error handle
				{
					return DIO_WRONG_PIN_NUMBER;
				}
				clearBit(PORTB, pinNumber); // write 0

			}
			else if (value == HIGH)
			{
				if (pinNumber >= NUMBER_OF_PINS_IN_PORT) // error handle
				{
					return DIO_WRONG_PIN_NUMBER;
				}
				setBit(PORTB, pinNumber); // write 1
			}
			else
			{
				return DIO_WRONG_WRITE_VALUE; // error handle
			}
		break;
		
		case PORT_C:
			if (value == LOW)
			{
				if (pinNumber >= NUMBER_OF_PINS_IN_PORT) // error handle
				{
					return DIO_WRONG_PIN_NUMBER;
				}
				clearBit(PORTC, pinNumber); // write 0
			}
			else if (value == HIGH)
			{
				if (pinNumber >= NUMBER_OF_PINS_IN_PORT) // error handle
				{
					return DIO_WRONG_PIN_NUMBER;
				}
				setBit(PORTC, pinNumber); // write 1
			}
			else
			{
				return DIO_WRONG_WRITE_VALUE; // error handle
			}
		break;
		
		case PORT_D:
			if (value == LOW)
			{
				if (pinNumber >= NUMBER_OF_PINS_IN_PORT) // error handle
				{
					return DIO_WRONG_PIN_NUMBER;
				}
				clearBit(PORTD, pinNumber); // write 0
			}
			else if (value == HIGH)
			{
				if (pinNumber >= NUMBER_OF_PINS_IN_PORT) // error handle
				{
					return DIO_WRONG_PIN_NUMBER;
				}
				setBit(PORTD, pinNumber); // write 1
			}
			else
			{
				return DIO_WRONG_WRITE_VALUE; // error handle
			}
		break;
		
		default:
			return DIO_WRONG_PORT_NUMBER; // error handle
		break;
		
	}
	
	return DIO_OK;
}

uint8_t DIO_toggle(uint8_t portNumber, uint8_t pinNumber)
{
	uint8_t pinValue;
	uint8_t DIOState = DIO_read(portNumber, pinNumber, &pinValue);
	if(DIOState != DIO_OK) // error handle
	{
		return DIOState;
	}
	
	if (pinValue == LOW) 
	{
		DIO_write(portNumber, pinNumber, HIGH);
	}
	else if (pinValue == HIGH) 
	{
		DIO_write(portNumber, pinNumber, LOW);
	}
	else
	{
		return DIO_WRONG_TOGGLE; // error handle
	}
	return DIO_OK;
}

uint8_t DIO_read(uint8_t portNumber, uint8_t pinNumber, uint8_t* value)
{
	if (pinNumber >= NUMBER_OF_PINS_IN_PORT) // error handle
	{
		return DIO_WRONG_PIN_NUMBER;
	}
	switch (portNumber)
	{
		case PORT_A:
			*value = readBit(PINA, pinNumber);
		break;
		
		case PORT_B:
			*value = readBit(PINB, pinNumber);
		break;
		
		case PORT_C:
			*value = readBit(PINC, pinNumber);
		break;
		
		case PORT_D:
			*value = readBit(PIND, pinNumber);
		break;
		
		default:
			return DIO_WRONG_PORT_NUMBER; // error handle
		break;
		
	}
	
	return DIO_OK;
}

// driver test
#if 0

int main()
{
	DIO_init('A', 6, 1);
	DIO_init(5, 6, 1);
	DIO_init('A', 8, 1);
	DIO_init('A', 6, 2);
	
	DIO_write('A', 6, 1);
	DIO_write(5, 6, 1);
	DIO_write('A', 8, 1);
	DIO_write('A', 6, 2);
		
	DIO_read('A', 6, 1);
	DIO_read(5, 6, 1);
	DIO_read('A', 8, 1);
	DIO_read('A', 6, 2);
	
	DIO_toggle('A', 6);
	DIO_toggle(5, 6);
	DIO_toggle('A', 8);
}

#endif
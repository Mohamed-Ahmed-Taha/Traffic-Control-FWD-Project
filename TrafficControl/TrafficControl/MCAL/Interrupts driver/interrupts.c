/*
 * interrupts.c
 *
 * Created: 9/9/2022 8:10:19 AM
 *  Author: Mohamed Ahmed Mohamed Ibrahim
 */ 


#include "interrupts.h"

uint8_t INTERRUPT_init(uint8_t extIntNum, uint8_t senseControl)
{
	switch (extIntNum)
	{
		case EXT_INT_0:
			if (senseControl < 0 || senseControl > 3)
			{
				return INTERRUPT_WRONG_INT_SENSE_CONTROL; // error handle
			}
			MCUCR |= senseControl;
			setBit(GICR, INT0);
			break;
			
		case EXT_INT_1:
			if (senseControl < 0 || senseControl > 3)
			{
				return INTERRUPT_WRONG_INT_SENSE_CONTROL; // error handle
			}
			MCUCR |= (senseControl << 2);
			setBit(GICR, INT1);
			break;
			
		case EXT_INT_2:
			if (senseControl == FALLING_EDGE_INT_REQ)
			{
				clearBit(MCUCSR, ISC2);
			}
			else if (senseControl == RISING_EDGE_INT_REQ)
			{
				setBit(MCUCSR, ISC2);
			}
			else
			{
				return INTERRUPT_WRONG_INT_SENSE_CONTROL; // error handle
			}
			setBit(GICR, INT2);
			break;
		
		default:
			return INTERRUPT_WRONG_INT_NUM; // error handle
	}
	
	sei();
	
	return INTERRUPT_OK;
}


// driver test
#if 0

int main()
{
	LED_init('A', 6);
	BUTTON_init(EXT_INT_0_PORT, EXT_INT_0_PIN);
	INTERRUPT_init(EXT_INT_0, RISING_EDGE_INT_REQ);
	LED_on('A', 6);
	
	while (1);
}

ISR(EXT_INT_0_vect)
{
	LED_toggle('A', 6);
}

#endif

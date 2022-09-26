/*
 * timer.c
 *
 * Created: 9/9/2022 7:58:37 AM
 *  Author: Mohamed Ahmed Mohamed Ibrahim
 */ 

#include "timer.h"

uint8_t TIMER_setOvfCallback (void (*callback) (void))
{
	ovfCallback = callback;
	return TIMER_OK;
}
uint8_t TIMER_setOvfCallbackCounterCompare(int32_t ammount)
{
	if (ammount > 0)
	{
		ovfCallbackCounterCompare = (uint32_t) ceil(ammount / 256.0);
	}
	else
	{
		ovfCallbackCounterCompare = -1;
	}
	return TIMER_OK;
}
uint8_t TIMER_init(uint16_t prescaler)
{
	TCCR0 = 0x00;
	
	switch (prescaler)
	{
		case PRESET_1:
			setBit(TCCR0, CS00);
			break;
		case PRESET_8:
			setBit(TCCR0, CS01);
			break;
		case PRESET_64:
			setBit(TCCR0, CS00);
			setBit(TCCR0, CS01);
			break;
		case PRESET_256:
			setBit(TCCR0, CS02);
			break;
		case PRESET_1024:
			setBit(TCCR0, CS00);
			setBit(TCCR0, CS02);
			break;
		default:
			return TIMER_PRESCALER_NOT_FOUND; // error handle
	}	
	
	TIMER_setOvfCallback(0);
	TIMER_setOvfCallbackCounterCompare(-1);
	
	return TIMER_OK;
}	
uint8_t TIMER_start(uint64_t ticks)
{
	overflowCounter = 0;
	uint64_t volatile numberOfOvfNeeded = (uint64_t) ceil(ticks / 256.0);
	
	while (overflowCounter < numberOfOvfNeeded)
	{
		uint8_t startTimerCount = 256 - ticks / numberOfOvfNeeded;
		TCNT0 = startTimerCount;
		while(!readBit(TIFR, TOV0));
		setBit(TIFR, TOV0);
		if(overflowCounter % ovfCallbackCounterCompare == 0 && ovfCallbackCounterCompare >= 0)
		{
			(*ovfCallback)();
		}
		overflowCounter++;
	}
	
	return TIMER_OK;
}


// driver test 
#if 0
void toggleLED2()
{
	LED_toggle('A', 3);
}

int main()
{
	LED_init('A', 3);
	LED_init('A', 6);
	TIMER_init(1024);
	TIMER_setOvfCallbackCounterCompare(488);
	TIMER_setOvfCallback(&toggleLED2);

	while(1)
	{
		 LED_toggle('A', 6);
		 TIMER_start(4883);
	}
}
#endif


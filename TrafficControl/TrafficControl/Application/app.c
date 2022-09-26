/*
 * app.c
 *
 * Created: 9/9/2022 8:25:25 AM
 *  Author: Mohamed Ahmed Mohamed Ibrahim
 */ 

#include "app.h"

void APP_init()
{
	// LED initialization
	LED_init(LED_CAR_GREEN_PORT, LED_CAR_GREEN_PIN);
	LED_init(LED_CAR_RED_PORT, LED_CAR_RED_PIN);
	LED_init(LED_CAR_YELLOW_PORT, LED_CAR_YELLOW_PIN);
	LED_init(LED_PED_GREEN_PORT, LED_PED_GREEN_PIN);
	LED_init(LED_PED_RED_PORT, LED_PED_RED_PIN);
	LED_init(LED_PED_YELLOW_PORT, LED_PED_YELLOW_PIN);
	
	// BUTTON initialization
	BUTTON_init(BUTTON_1_PORT, BUTTON_1_PIN);
	
	// TIMER initialization
	TIMER_init(PRESET_1024);
	TIMER_setOvfCallback(&yellowLEDCoontrol);
	TIMER_setOvfCallbackCounterCompare(DELAY_500_MILLI_SEC);
	
	// EXT interrupts initialization
	INTERRUPT_init(EXT_INT_0, RISING_EDGE_INT_REQ);
	
	// wasButtonPressed initialization
	wasButtonPressed = BUTTON_NOT_PRESSED;
	
	// numOfYellowBlinking initialization
	numOfYellowBlinking = NO_YELLOW_LED_BLINK;
	
	return;
}
uint8_t displayLEDState(uint8_t state)
{
	switch (state)
	{
		case CAR_RED_PED_RED:
			LED_on(LED_CAR_RED_PORT, LED_CAR_RED_PIN);
			LED_on(LED_PED_RED_PORT, LED_PED_RED_PIN);
			LED_off(LED_CAR_GREEN_PORT, LED_CAR_GREEN_PIN);
			LED_off(LED_PED_GREEN_PORT, LED_PED_GREEN_PIN);
		break;
		
		case  CAR_RED_PED_GREEN:
			LED_on(LED_CAR_RED_PORT, LED_CAR_RED_PIN);
			LED_on(LED_PED_GREEN_PORT, LED_PED_GREEN_PIN);
			LED_off(LED_CAR_GREEN_PORT, LED_CAR_GREEN_PIN);
			LED_off(LED_PED_RED_PORT, LED_PED_RED_PIN);
		break;
		
		case CAR_GREEN_PED_RED:
			LED_on(LED_CAR_GREEN_PORT, LED_CAR_GREEN_PIN);
			LED_on(LED_PED_RED_PORT, LED_PED_RED_PIN);
			LED_off(LED_CAR_RED_PORT, LED_CAR_RED_PIN);
			LED_off(LED_PED_GREEN_PORT, LED_PED_GREEN_PIN);
		break;
		
		default:
			return APP_WRONG_STATE;
	}
	
	return APP_OK;
}
void yellowLEDCoontrol()
{
	if (numOfYellowBlinking % 3 == NO_YELLOW_LED_BLINK)
	{
		LED_off(LED_CAR_YELLOW_PORT, LED_CAR_YELLOW_PIN);
		LED_off(LED_PED_YELLOW_PORT, LED_PED_YELLOW_PIN);
	}
	if (numOfYellowBlinking % 3 == CAR_YELLOW_LED_ONLY_BLINK)
	{
		LED_toggle(LED_CAR_YELLOW_PORT, LED_CAR_YELLOW_PIN);
		LED_off(LED_PED_YELLOW_PORT, LED_PED_YELLOW_PIN);
		return;
	}
	else if (numOfYellowBlinking % 3 == BOTH_YELLOW_LED_BLINK)
	{
		LED_toggle(LED_CAR_YELLOW_PORT, LED_CAR_YELLOW_PIN);
		if (wasButtonPressed == BUTTON_PRESSED)
		{
			LED_toggle(LED_PED_YELLOW_PORT, LED_PED_YELLOW_PIN);
		}
		return;
	}
	return;
}
void errorState()
{
	while (1)
	{
		// All LEDS put to on
		LED_on(LED_CAR_GREEN_PORT, LED_CAR_GREEN_PIN);
		LED_on(LED_CAR_RED_PORT, LED_CAR_RED_PIN);
		LED_on(LED_CAR_YELLOW_PORT, LED_CAR_YELLOW_PIN);
		LED_on(LED_PED_GREEN_PORT, LED_PED_GREEN_PIN);
		LED_on(LED_PED_RED_PORT, LED_PED_RED_PIN);
		LED_on(LED_PED_YELLOW_PORT, LED_PED_YELLOW_PIN);
	}
}
void APP_start()
{
	// All LEDS put to off
	LED_off(LED_CAR_GREEN_PORT, LED_CAR_GREEN_PIN);
	LED_off(LED_CAR_RED_PORT, LED_CAR_RED_PIN);
	LED_off(LED_CAR_YELLOW_PORT, LED_CAR_YELLOW_PIN);
	LED_off(LED_PED_GREEN_PORT, LED_PED_GREEN_PIN);
	LED_off(LED_PED_RED_PORT, LED_PED_RED_PIN);
	LED_off(LED_PED_YELLOW_PORT, LED_PED_YELLOW_PIN);
	while (1)
	{
		// carLED: Green   |   pedLED:   Red
		numOfYellowBlinking = NO_YELLOW_LED_BLINK;
		if (displayLEDState(CAR_GREEN_PED_RED) == APP_WRONG_STATE)
		{
			break;
		}
		TIMER_start(DELAY_5_SEC);
		
		// carLED: Green, Yellow   |   pedLED: Red        OR      carLED: Green, Yellow   |   pedLED: Red, Yellow
		numOfYellowBlinking = BOTH_YELLOW_LED_BLINK;
		if (displayLEDState(CAR_GREEN_PED_RED) == APP_WRONG_STATE)
		{
			break;
		}
		TIMER_start(DELAY_5_SEC);
		
		// if button was pressed
		if (wasButtonPressed == BUTTON_PRESSED)
		{
			// carLED: Red   |   pedLED: Green
			numOfYellowBlinking = NO_YELLOW_LED_BLINK;
			if (displayLEDState(CAR_RED_PED_GREEN) == APP_WRONG_STATE)
			{
				break;
			}
			TIMER_start(DELAY_5_SEC);
			
			// carLED: Red, Yellow   |   pedLED: Green, Yellow
			numOfYellowBlinking = BOTH_YELLOW_LED_BLINK;
			if (displayLEDState(CAR_RED_PED_GREEN) == APP_WRONG_STATE)
			{
				break;
			}
			TIMER_start(DELAY_5_SEC);
			
			// make button not pressed
			wasButtonPressed = BUTTON_NOT_PRESSED;
		}
			
		// if button was not pressed
		else if (wasButtonPressed == BUTTON_NOT_PRESSED)
		{
			// carLED: Red   |   pedLED: Red
			numOfYellowBlinking = NO_YELLOW_LED_BLINK;
			if (displayLEDState(CAR_RED_PED_RED) == APP_WRONG_STATE)
			{
				break;
			}
			TIMER_start(DELAY_5_SEC);
			
			// carLED: Red, Yellow   |   pedLED: Red
			numOfYellowBlinking = CAR_YELLOW_LED_ONLY_BLINK;
			if (displayLEDState(CAR_RED_PED_RED) == APP_WRONG_STATE)
			{
				break;
			}
			TIMER_start(DELAY_5_SEC);
		}
		else 
		{
			break; // error handle
		}
	}
	
	errorState();	
}

ISR(EXT_INT_0_vect)
{
	wasButtonPressed = BUTTON_PRESSED;
}
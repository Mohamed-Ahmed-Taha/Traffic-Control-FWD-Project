/*
 * app.h
 *
 * Created: 9/9/2022 8:25:35 AM
 *  Author: Mohamed Ahmed Mohamed Ibrahim
 */ 


#ifndef APP_H_
#define APP_H_

#include "../Utilities/microship_properties.h"
#include "../Utilities/ports_pins.h"
#include "../Utilities/registers.h"
#include "../Utilities/util.h"
#include "../ECAL/Button driver/button.h"
#include "../ECAL/LED driver/led.h"
#include "../MCAL/Timer dirver/timer.h"
#include "../MCAL/Interrupts driver/interrupts.h"

// error handle
#define APP_OK 0
#define APP_WRONG_STATE 1

// LED states
#define CAR_RED_PED_RED 0
#define CAR_GREEN_PED_RED 1
#define CAR_RED_PED_GREEN 2

// time ticks
#define DELAY_5_SEC 4883
#define DELAY_500_MILLI_SEC 488

// button states
#define BUTTON_NOT_PRESSED 0
#define BUTTON_PRESSED 1

// Yellow LEDS blinking states
#define NO_YELLOW_LED_BLINK 0
#define CAR_YELLOW_LED_ONLY_BLINK 1
#define BOTH_YELLOW_LED_BLINK 2

// was button pressed global variable
uint8_t wasButtonPressed;
// global variable to indicate the number of yellow leds that should be blinking
uint8_t numOfYellowBlinking;

// app initialization
void APP_init();
// states of led
uint8_t displayLEDState(uint8_t state);
// yellow blink control fun
void yellowLEDCoontrol();
// error state fun (while 1)
void errorState();
// app main
void APP_start();



#endif /* APP_H_ */
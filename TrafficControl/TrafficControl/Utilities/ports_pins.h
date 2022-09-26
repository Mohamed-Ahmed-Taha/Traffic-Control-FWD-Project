/*
 * ports_pins.h
 *
 * Created: 9/9/2022 7:09:02 AM
 *  Author: Mohamed Ahmed Mohamed Ibrahim
 */ 


#ifndef PORTS_PINS_H_
#define PORTS_PINS_H_

// PORT defines
#define PORT_A 'A'
#define PORT_B 'B'
#define PORT_C 'C'
#define PORT_D 'D'

// Pin defines
#define PIN0 0
#define PIN1 1
#define PIN2 2
#define PIN3 3
#define PIN4 4
#define PIN5 5
#define PIN6 6
#define PIN7 7

// Car LEDS port and pin definitions
#define LED_CAR_GREEN_PORT PORT_A
#define LED_CAR_GREEN_PIN PIN6

#define LED_CAR_RED_PORT PORT_A
#define LED_CAR_RED_PIN PIN0

#define LED_CAR_YELLOW_PORT PORT_A
#define LED_CAR_YELLOW_PIN PIN3

// Pedestrian LEDS port and pin definitions
#define LED_PED_GREEN_PORT PORT_C
#define LED_PED_GREEN_PIN PIN0

#define LED_PED_RED_PORT PORT_C
#define LED_PED_RED_PIN PIN6

#define LED_PED_YELLOW_PORT PORT_C
#define LED_PED_YELLOW_PIN PIN3

// button port and pin definition
#define BUTTON_1_PORT EXT_INT_0_PORT
#define BUTTON_1_PIN EXT_INT_0_PIN



#endif /* PORTS_PINS_H_ */
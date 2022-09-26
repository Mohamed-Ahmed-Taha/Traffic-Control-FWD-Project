/*
 * timer.h
 *
 * Created: 9/9/2022 7:58:26 AM
 *  Author: Mohamed Ahmed Mohamed Ibrahim
 */ 


#ifndef TIMER_H_
#define TIMER_H_

#include <math.h>
#include "../../Utilities/util.h"
#include "../../Utilities/microship_properties.h"
#include "../../Utilities/registers.h"
#include "../../Utilities/ports_pins.h"

// error handle
#define TIMER_OK 0
#define TIMER_PRESCALER_NOT_FOUND 2

// presets
#define PRESET_1 1
#define PRESET_8 8
#define PRESET_64 64
#define PRESET_256 256
#define PRESET_1024 1024



// global pointer to function for overflow callback
void static (*ovfCallback) (void) ;
// global variable to store the number of overflow checks happed
uint32_t volatile static overflowCounter;
// global variable to store the number at which overflow call back function is called
int32_t volatile static ovfCallbackCounterCompare;



// all driver function prototypes
// fun to initialize overflow callback
uint8_t TIMER_setOvfCallback (void (*callback) (void));
// fun to set the number at which overflow call back function is called
uint8_t TIMER_setOvfCallbackCounterCompare(int32_t ammount);
// fun to init timer	
uint8_t TIMER_init(uint16_t prescaler);
// fun to count ticks
uint8_t TIMER_start(uint64_t ticks);


#endif /* TIMER_H_ */
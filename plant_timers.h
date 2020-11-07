#ifndef PLANT_TIMERS_H_
#define PLANT_TIMERS_H_

#include"msp.h"
#include "water.h"

#define TICKS ((uint16_t) 0xB71B) // period of 1s

void config_timer(void);
void start_timer(void);
void config_nvic(void);
void stop_timer(void);

#endif

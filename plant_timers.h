#ifndef PLANT_TIMERS_H_
#define PLANT_TIMERS_H_

#include"msp.h"
#include "water.h"

#define TICKS ((uint16_t)//insert hex here)

void config_timer(void);
void start_timer(void);
void config_nvic(void);

#endif

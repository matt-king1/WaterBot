#ifndef WATER_H_
#define WATER_H_

#include "clock.h"
#include "msp.h"
#include "servo.h"

void config_water(void);
void dispense(uint16_t time);
void start_timer(void);
void stop_timer(void);
void water1(void);
void water2(void);
void water3(void);

#endif //water.h

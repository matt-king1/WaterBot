#ifndef ULTRASONIC_H_
#define ULTRASONIC_H_

#include <stdint.h>

void configUltrasonic(void);    // config registers and set up
void configUltrasonicTimer(void);
void startUltrasonicTimer(void);
uint16_t stopUltrasonicTimer(void);
double readEcho(void);         // pulse the trig pin HIGH for 10us and read the echo pin pulse

#endif

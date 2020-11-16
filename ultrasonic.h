#ifndef ULTRASONIC_H_
#define ULTRASONIC_H_

#include <stdint.h>

void configUltrasonic(void);    // config registers and set up
uint8_t readUltrasonic(void);         // pulse the trig pin HIGH for 10us and read the echo pin pulse

#endif

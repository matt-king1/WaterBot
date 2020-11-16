#include "ultrasonic.h"
#include "msp.h"
#include "clock.h"

// P4.1 - Trig
#define TRIG (1<<1)
// P4.2 - Echo
#define ECHO (1<<2)

uint8_t time;

void configUltrasonic(void)
{
    P4->DIR |= TRIG;    // set P4.1 as an output
    P4->OUT &= ~TRIG;   // set P4.1 output to low
    P4->DIR &= ~ECHO;   // set P4.2 as an input
}

uint8_t readEcho(void)
{
    P4->OUT |= TRIG;    // set P4.1 output to high
    Clock_Delay1us(10); // delay for 10uS
    P4->OUT &= ~TRIG;   // set P4.1 output to low

    while(!(P4->IN & ECHO)); // wait for a HIGH on ECHO pin
    // start timer
    while(P4->IN & ECHO); // wait for a LOW on ECHO pin
    // time = stopTimer;

    return time;
}

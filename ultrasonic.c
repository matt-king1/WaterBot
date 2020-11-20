#include "ultrasonic.h"
#include "msp.h"
#include "clock.h"
#include <stdio.h>

// P4.1 - Trig
#define TRIG (1<<1)
// P4.2 - Echo
#define ECHO (1<<2)

uint16_t time;

void configUltrasonic(void)
{
    P4->DIR |= TRIG;    // set P4.1 as an output
    P4->OUT &= ~TRIG;   // set P4.1 output to low
    P4->DIR &= ~ECHO;   // set P4.2 as an input
}

void configUltrasonicTimer(void)
{
    TIMER_A1->CTL = TIMER_A_CTL_SSEL__SMCLK | TIMER_A_CTL_MC__STOP; // SMCLK, stop mode
    TIMER_A1->CCR[0] = 0xFFFF;
}

void startUltrasonicTimer(void)
{
    TIMER_A1->CTL |= TIMER_A_CTL_CLR;       // reset counter back to 0
    TIMER_A1->CTL |= TIMER_A_CTL_MC__UP | TIMER_A_CTL_SSEL_SMCLK;    // start counter
}

uint16_t stopUltrasonicTimer(void)
{
    TIMER_A1->CTL = TIMER_A_CTL_MC__STOP;  // stop counter
    return TIMER_A1->R;                     // return count
}

double readEcho(void)
{
    P4->OUT |= TRIG;    // set P4.1 output to high
    Clock_Delay1us(10); // delay for 10uS
    P4->OUT &= ~TRIG;   // set P4.1 output to low


    while(!(P4->IN & ECHO)); // wait for a HIGH on ECHO pin
    startUltrasonicTimer();
    while(P4->IN & ECHO); // wait for a LOW on ECHO pin
    time = stopUltrasonicTimer();

    return (((double)time/30.0)*0.034)/2.0; // make sure to use decimals to avoid integer division
                                   //
}                                  // divide time by 3Hz because SMCLK is 3MHz, so that give us a time unit of microsecond then just follow formula


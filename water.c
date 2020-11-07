#include "clock.h"

void config_water(void) {
    P2->SEL0 &= ~0x08;
    P2->SEL1 &= ~0x08; //gpio
    P2->DIR |= 0x08; //output
    P2->DS |= 0x08; //high current
}

void water(uint16_t time) {
    P2->OUT &= ~0x08; //relay on
    delay(time); //delays time/8000 ms
    P2->OUT |= 0x08; //turn off
}

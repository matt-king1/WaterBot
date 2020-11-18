#include "clock.h"
#include "msp.h"
#include "servo.h"
#include "ultrasonic.h"

uint8_t homebase = 0; //home base reflectance

void config_water(void) { //P2.3 for relay
    P2->SEL0 &= ~0x08;
    P2->SEL1 &= ~0x08; //gpio
    P2->DIR |= 0x08; //output
    P2->DS |= 0x08; //high current
}

void dispense(uint16_t time, uint8_t stop_condition) {
    left();
    P2->OUT &= ~0x08; //relay on
    Clock_Delay1ms(time); //delays time ms
    P2->OUT |= 0x08; //turn off
    right(stop_condition);
}

void water1(void) {
    uint8_t p1_reflec = 0; //find value
    uint16_t p1_time = 10; //how much water is dispensed
    forward(p1_reflec);
    left();
    dispense(p1_time, p1_reflec);
    right(p1_reflec);
    backward(homebase);
}

void water2(void) {
    uint8_t p2_reflec = 0; //find value
    uint16_t p2_time = 10; //how much water is dispensed
    forward(p2_reflec);
    left();
    dispense(p2_time, p2_reflec);
    right(p2_reflec);
    backward(homebase);
}

void water3(void) {
    uint8_t p3_reflec = 0; //find value
    uint16_t p3_time = 10; //how much water is dispensed
    forward(p3_reflec);
    left();
    dispense(p3_time, p3_reflec);
    right(p3_reflec);
    backward(homebase);
}

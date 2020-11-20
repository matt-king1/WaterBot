#include "clock.h"
#include "msp.h"
#include "servo.h"
#include "ultrasonic.h"

uint16_t homebase = 800; //home base reflectance

void config_water(void) { //P2.3 for relay
    P2->SEL0 &= ~0x08;
    P2->SEL1 &= ~0x08; //gpio
    P2->OUT |= 0x08; //turn off
    //P2->DIR |= 0x08; //output
    P2->DS |= 0x08; //high current
}

void dispense(uint16_t time) {
    P2->DIR |= 0x08;
    //P2->OUT &= ~0x08; //relay on
    Clock_Delay1ms(time); //delays time ms
    //P2->OUT |= 0x08; //turn off
    P2->DIR &= ~0x08;
}

void water1(void) {
    __disable_irq();
    printf("got here 1\n");
    uint16_t p1_reflec = 1600; //find value
    uint16_t p1_time = 5000; //how much water is dispensed
    forward(p1_reflec);
    printf("got here 2\n");
    left();
    printf("got here 3\n");
    dispense(p1_time);
    printf("got here 4\n");
    right(p1_reflec);
    printf("got here 5\n");
    Clock_Delay1ms(5000);
    backward(homebase);
    printf("done\n");
    __enable_irq();
}

void water2(void) {
    uint16_t p2_reflec = 0; //find value
    uint16_t p2_time = 10; //how much water is dispensed
    forward(p2_reflec);
    left();
    dispense(p2_time);
    right(p2_reflec);
    backward(homebase);
}

void water3(void) {
    uint16_t p3_reflec = 0; //find value
    uint16_t p3_time = 10; //how much water is dispensed
    forward(p3_reflec);
    left();
    dispense(p3_time);
    right(p3_reflec);
    backward(homebase);
}

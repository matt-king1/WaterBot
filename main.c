#include "msp.h"
#include "stdio.h"
#include "reflectanceArray.h"
#include "Clock.h"
#include "servo.h"
#include "pca9685.h"
#include "water.h"
#include "plant_timers.h"
#include "ultrasonic.h"

/**
 * main.c
 */


void Initialize(void);

void main(void)
{
    Initialize();
    P3->DIR |= BIT6; // Pin 3.5 is an output

    //uint16_t* data; // variable to store reflectance values
	while(1)
	{
	    //data = Reflectance_Read();
	    //printf("S1: %d S2: %d S3: %d S4: %d S5: %d S6: %d S7: %d S8: %d\n", data[0], data[1], data[2], data[3], data[4], data[5], data[6], data[7]); // print distance
	    //Clock_Delay1ms(10);
	}
}

void Initialize(void)
{
    WDT_A->CTL = WDT_A_CTL_PW | WDT_A_CTL_HOLD;     // stop watchdog timer
    stop_timer();
    Clock_Init48MHz();
    Reflectance_Init();
    configUltrasonic();
    config_water();
    pca9685_init();
    config_timer();
    configUltrasonicTimer();
    config_nvic();
    start_timer();
}

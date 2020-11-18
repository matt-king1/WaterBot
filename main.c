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

    double data; // variable to store reflectance values
	while(1)
	{
	    data = readEcho();
	    printf("Data: %f \n", data); // print distance
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

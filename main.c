#include "msp.h"
#include "stdio.h"
#include "reflectanceArray.h"
#include "Clock.h"
#include "servo.h"
#include "pca9685.h"
#include "water.h"
#include "plant_timers.h"

/**
 * main.c
 */


void main(void)
{
    Initialize();
    P3->DIR |= BIT5; // Pin 3.5 is an output

    uint8_t data; // variable to store reflectance values
	while(1)
	{
	    data = Reflectance_Read(1000); // read reflectance
	    printf("Data: %d \n", data); // print reflectance
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

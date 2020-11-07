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

	while(1)
	{

	}
}

void Initialize(void)
{
    WDT_A->CTL = WDT_A_CTL_PW | WDT_A_CTL_HOLD;     // stop watchdog timer
    stop_timer();
    Clock_Init48MHz();
    Reflectance_Init();
    config_water();
    pca9685_init();
    config_timer();
    config_nvic();
    start_timer();
}

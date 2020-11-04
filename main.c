#include "msp.h"
#include "stdio.h"
#include "reflectanceArray.h"
#include "Clock.h"

/**
 * main.c
 */

void Initialize();

void main(void)
{
    Initialize();

	uint8_t data, light_data;
	while(1)
	{
	    data = Reflectance_Read(1000);
	    light_data = LIGHT_BAR(data, 0);
	    printf("Data: %i \n LightData: \i", data, light_data);
	}
}

void Initialize()
{
    WDT_A->CTL = WDT_A_CTL_PW | WDT_A_CTL_HOLD;     // stop watchdog timer
    Clock_Init48MHz();

    Reflectance_Init();
}

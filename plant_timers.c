#include "plant_timers.h"
#include "msp.h"
#include "water.h"

uint16_t plant1 = 0;
uint16_t plant2 = 0;
uint16_t plant3 = 0;

uint32_t plant1_fin = 86400; // one day
uint16_t plant2_fin = 43200; // 12 hours
uint32_t plant3_fin = 172800; //2 days

void config_timer(void) { //interrupt every 1 second
    TIMER_A0->CTL |= TIMER_A_CTL_CLR;               // Clear
    TIMER_A0->CTL |= TIMER_A_CTL_SSEL__SMCLK;       // 3MHz Clock
    TIMER_A0->CTL |= TIMER_A_CTL_ID__8;             // Divide by 2^8
    //add more for the settings here
    TIMER_A0->CCR[0]  = TICKS;
}

void start_timer(void) {
    TIMER_A0->CTL |= TIMER_A_CTL_MC__UP;
}
void stop_timer(void) {
    // use the CTL reg's MC mask to clear all bits in the portion of the register
    TIMER_A0->CTL &= ~(TIMER_A_CTL_MC__STOP);
}
void config_nvic(void)
{
    NVIC_SetPriority(TA0_N_IRQn, 3);                // set interrupt priority to 3
    NVIC_EnableIRQ(TA0_N_IRQn);                     // NVIC interrupt enable
    __enable_interrupt();                           // global interrupt enable
}

void TA0_N_IRQHandler(void)
{
    __disable_interrupt();                          // global interrupt disable
    if(TIMER_A0->CCTL[1] & TIMER_A_CCTLN_CCIFG)
    {
        if (plant1 == plant1_fin) {
            plant1 = 0;
            water1();
        }
        else plant1++;
        if (plant2 == plant2_fin) {
            plant2 = 0;
            water2();
        }
        else plant2++;
        if (plant3 == plant3_fin) {
            plant3 = 0;
            water3();
        }
        else plant3++;
        TIMER_A0->CCTL[1] &= ~TIMER_A_CCTLN_CCIFG;  // clear flag
    }
    __enable_interrupt();                           // global interrupt enable
}

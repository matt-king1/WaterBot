#include <stdint.h>
#include "msp432.h"
#include "Clock.h"
#include "reflectanceArray.h"

void Reflectance_Init(void){
  P5->SEL0 &= ~0x08;
  P5->SEL1 &= ~0x08;    // configure P5.3 as GPIO
  P5->DIR |= 0x08;      // make P5.3 out
  P5->OUT &= ~0x08;     // turn off LEDs
  P7->SEL0 = 0x00;
  P7->SEL1 = 0x00;      // configure P7.7-P7.0 as GPIO
  P7->DIR = 0x00;       // make P7.7-P7.0 in
}


uint16_t* Reflectance_Read(void){
    uint16_t* result;
    Reflectance_Start();
    startReflectanceTimer();
    result = Reflectance_End();

    return result;
}


const int32_t Mask[8] = {0x01,0x02,0x04,0x08,0x10,0x20,0x40,0x80};
bool Reflectance_Position(uint16_t* data){
    uint16_t result;
    if (data[3] >= data[4])
        result = data[3] - data[4];
    else result = data[4] - data[3];
    if (result < ) {
        return true;
    }
    return false;
}

void Reflectance_Start(void){
  P5->OUT |= 0x08;      // turn on 8 IR LEDs
  P7->DIR = 0xFF;       // make P7.7-P7.0 out
  P7->OUT = 0xFF;       // prime for measurement
  Clock_Delay1us(10);   // wait 10 us
  P7->DIR = 0x00;       // make P7.7-P7.0 in
}


// ------------Reflectance_End------------
// Finish reading the eight sensors
// Read sensors
// Turn off the 8 IR LEDs
// Input: none
// Output: sensor readings
// Assumes: Reflectance_Init() has been called
// Assumes: Reflectance_Start() was called 1 ms ago

uint16_t* Reflectance_End(void){
  uint8_t result;
  result = P7->IN; // 1 means black, 0 means white
  uint16_t time_array[8] = {0,0,0,0,0,0,0,0};
  while(result) {
      for (i = 0; i<8; i++) {
          if ((result & ~mask[i])&&(time_array[i] == 0)){
              time_array[i] = TIMER_A2->R;
          }
      }
  }
  stopReflectanceTimer();
  P5->OUT &= ~0x08;     // turn off 8 IR LEDs
  return time_array;
}

void configReflectanceTimer(void)
{
    TIMER_A2->CTL = TIMER_A_CTL_SSEL__SMCLK | TIMER_A_CTL_MC__STOP;
    TIMER_A2->CCR[0] = 0xFFFF;
}

void startReflectanceTimer(void)
{
    TIMER_A2->CTL |= TIMER_A_CTL_CLR;
    TIMER_A2->CTL |= TIMER_A_CTL_MC__UP | TIMER_A_CTL_SSEL__SMCLK;
}

void stopReflectanceTimer(void)
{
    TIMER_A2->CTL = TIMER_A_CTL_MC__STOP;
}

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


//const int32_t WeightIn[8] = {1312, 937, 562, 187, -188, -563, -938, -1313};
//const int32_t Weight[8] = {332, 237, 142, 47, -47, -142, -237, -332};
//const int32_t Mask[8] = {0x01,0x02,0x04,0x08,0x10,0x20,0x40,0x80};
//// Perform sensor integration
//// Input: data is 8-bit result from line sensor
//// Output: position in 0.1mm relative to center of line
//int32_t Reflectance_Position(uint8_t data){
//  uint32_t i; int32_t sum,count;
//  if(data){ // calculate only if some active
//    sum = 0; count=0;
//    for(i=0;i<8;i++){
//      if(data&Mask[i]){
//        sum += Weight[i];
//        count++;
//      }
//    }
//    return sum/count;
//  }else{
//   return Weight[0]+1; // guess right
//  }
//}


void Reflectance_Start(void){
  P5->OUT |= 0x08;      // turn on 8 IR LEDs
  P7->DIR = 0xFF;       // make P7.7-P7.0 out
  P7->OUT = 0xFF;       // prime for measurement
  Clock_Delay1us(10);   // wait 10 us
  P7->DIR = 0x00;       // make P7.7-P7.0 in
}

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
    return TIMER_A2->R;
}

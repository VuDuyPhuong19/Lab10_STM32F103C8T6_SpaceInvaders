#ifndef _SYSTICK_H_
#define _SYSTICK_H_
#include <stdint.h>

//extern uint16_t ADCData;
//extern uint8_t ADCstatus;

//#define GPIOB_PIN_6 (1 << 6)

// Initialize SysTick with busy wait ruuning at bus clock
void SysTick_Init(uint32_t);

// Time delay using busy wait
// The delay parameter is in units of the core clock
void SysTick_Wait(uint32_t delay);

// Time delay using busy wait
// This assumes 72MHz system clock
void SysTick_Wait10ms(uint32_t delay);

#endif

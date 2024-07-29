#ifndef _TIMER_H_
#define _TIMER_H_

#define GPIOB_PIN_6 1 << 6

#include "IO.h"
#include "ADC.h"

extern volatile uint16_t ADCData;
extern volatile uint8_t ADCstatus;

void Timer3A_Init(uint32_t period, uint32_t priority);

#endif
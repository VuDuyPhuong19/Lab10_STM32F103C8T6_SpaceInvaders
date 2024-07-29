#include <stdint.h>
#include "stm32f10x.h"
#include "SysTick.h"
#include "ADC.h"
#include "IO.h"

//uint16_t ADCData;
//uint8_t ADCstatus;

void SysTick_Init(uint32_t period){
	SysTick->CTRL = 0;
	SysTick->LOAD = period - 1;
	SysTick->VAL = 0;
	SysTick->CTRL = SysTick_CTRL_ENABLE | SysTick_CTRL_CLKSOURCE | SysTick_CTRL_TICKINT;
}

void SysTick_Wait(uint32_t delay){ // wait 13.8ns
	SysTick->LOAD = delay - 1;
	SysTick->VAL = 0;
	while((SysTick->CTRL & SysTick_CTRL_COUNTFLAG) == 0) {}
}

void SysTick_Wait10ms(uint32_t delay){
	uint32_t i;
	for(i = 0; i < delay; i++){
		SysTick_Wait(720000); // wait 10ms
	}
}

//void SysTick_Handler(){
//	SysTick->CTRL &= ~SysTick_CTRL_TICKINT_Msk; // Vô hi?u hóa ng?t SysTick
//  SysTick->CTRL &= ~SysTick_CTRL_COUNTFLAG_Msk; // Xóa c? ng?t SysTick
//	ADCData = ADC_In();
//	ADCstatus = 1;
//	IO_HeartBeat(GPIOB_PIN_6);
//}	
#include "Timer.h"
#include "stm32f10x.h"

volatile uint16_t ADCData;
volatile uint8_t ADCstatus;

//void Timer2_Init(uint32_t period, uint32_t priority) {
//    // B?t clock cho Timer 2
//    RCC->APB1ENR |= RCC_APB1ENR_TIM2EN;

//    // T?t Timer 2 tru?c khi c?u h�nh
//    TIM2->CR1 &= ~TIM_CR1_CEN;

//    // C?u h�nh Timer 2
////    TIM2->CR1 &= ~TIM_CR1_DIR; // �?t timer ? ch? d? upcounting (d?m l�n)
//		TIM2->CR1 |= TIM_CR1_DIR; // down-count
////    TIM2->PSC = 72 - 1; // Thi?t l?p b? chia t? l? d? c� chu k? 1MHz (72MHz / 72 = 1MHz)
//    TIM2->ARR = period - 1; // Thi?t l?p gi� tr? t? n?p d? t?o chu k?

//    // X�a c? ng?t v� c�i d?t ng?t cho Timer 2
//    TIM2->SR &= ~TIM_SR_UIF; // X�a c? ng?t
//    TIM2->DIER |= TIM_DIER_UIE; // B?t ng?t update
//	
//    // Thi?t l?p uu ti�n ng?t
//    NVIC_SetPriority(TIM2_IRQn, priority);
//    NVIC_EnableIRQ(TIM2_IRQn);

//    // B?t d?u Timer
//    TIM2->CR1 |= TIM_CR1_CEN; // B?t Timer 2
//}

//void Timer2_Init(uint32_t period) {
//    // B?t clock cho Timer2
//    RCC->APB1ENR |= RCC_APB1ENR_TIM2EN;

//    // T?m d?ng Timer2 tru?c khi c?u h�nh
//    TIM2->CR1 &= ~TIM_CR1_CEN;

//    // C?u h�nh Timer2
//    TIM2->CR1 = 0;             // Thi?t l?p c�c c? di?u khi?n Timer2 v? 0
//    TIM2->PSC = 1 - 1;         // Thi?t l?p b? chia t? l?, chia t? l? xu?ng c�n 1
//    TIM2->ARR = period - 1;    // Thi?t l?p gi� tr? t? n?p d? t?o chu k?

//    // K�ch ho?t c? ng?t cho Timer2
//    TIM2->DIER |= TIM_DIER_UIE; 

//    // B?t d?u Timer2
//    TIM2->CR1 |= TIM_CR1_CEN | TIM_CR1_ARPE;

//    // Thi?t l?p m?c uu ti�n cho ng?t Timer2
//    NVIC_SetPriority(TIM2_IRQn, 0); 
//    // B?t ng?t Timer2
//    NVIC_EnableIRQ(TIM2_IRQn); 
//}

void Timer3A_Init(uint32_t period, uint32_t priority) {
    // B?t clock cho Timer 3
    RCC->APB1ENR |= RCC_APB1ENR_TIM3EN;

    // T?t Timer 3 tru?c khi c?u h�nh
    TIM3->CR1 &= ~TIM_CR1_CEN;

    // C?u h�nh Timer 3
    TIM3->CR1 = 0x00000000; // �?t CR1 v? gi� tr? m?c d?nh
    TIM3->CR1 &= ~TIM_CR1_DIR; // Thi?t l?p ch? d? d?m l�n (upcounting)
    TIM3->PSC = 7200 - 1; // Thi?t l?p Prescaler
    TIM3->ARR = period - 1; // Thi?t l?p gi� tr? Period

    // X�a c? ng?t
    TIM3->SR &= ~TIM_SR_UIF;

    // B?t ng?t cho Timer 3
    TIM3->DIER |= TIM_DIER_UIE;

    // Thi?t l?p uu ti�n ng?t
    NVIC_SetPriority(TIM3_IRQn, priority);

    // B?t ng?t Timer 3
    NVIC_EnableIRQ(TIM3_IRQn);

    // B?t Timer 3
    TIM3->CR1 |= TIM_CR1_CEN;
}
void TIM3_IRQHandler(void){
    if (TIM3->SR & TIM_SR_UIF) {
        // Clear update interrupt flag
        TIM3->SR &= ~TIM_SR_UIF;

        // Read ADC value
//        ADCData = ADC_In();
				// Start ADC conversion
			  ADC1->CR2 |= ADC_CR2_SWSTART;
        ADCstatus = 1;

        // Toggle PC13 (for testing purposes)
        GPIOC->ODR ^= 1 << 13;
    }
}
#include "IO.h"
#include "stm32f10x.h"
#include "UART.h"
#include "UART2_INIT.h"
// PA0 : switch
// PB6,7 : LED
void IO_Init(void) {
    // Enable GPIO Port A and Port B clock
    RCC->APB2ENR |= RCC_APB2ENR_IOPAEN | RCC_APB2ENR_IOPBEN | RCC_APB2ENR_IOPCEN;

    // Delay to ensure GPIO Port A and Port B clock are enabled
    volatile uint32_t delay = RCC->APB2ENR;

    // Configure PB6 and PB7 as outputs for blinking LEDs
    GPIOB->CRL &= ~(GPIO_CRL_MODE6 | GPIO_CRL_CNF6 | GPIO_CRL_MODE7 | GPIO_CRL_CNF7);
    GPIOB->CRL |= GPIO_CRL_MODE6_0 | GPIO_CRL_MODE7_0; // Output mode, max speed 10 MHz
	
	   // Configure PC13 as outputs for blinking LEDs
    GPIOC->CRH &= ~(GPIO_CRH_MODE13 | GPIO_CRH_CNF13);
    GPIOC->CRH |= GPIO_CRH_MODE13_0; // Output mode, max speed 10 MHz
		GPIOC->ODR &= ~(1 << 13);

    // Configure PA0 as input for the switch
    GPIOA->CRL &= ~(GPIO_CRL_MODE0 | GPIO_CRL_CNF0);
//    GPIOA->CRL |= GPIO_CRL_CNF0_0; // Input mode with floating input

		GPIOA->CRL |= GPIO_CRL_CNF0_1;
    // Enable pull-up resistor for PA0
    GPIOA->ODR |= GPIO_ODR_ODR0;
//		GPIOA->BSRR |= GPIO_BSRR_BS0;

//    // Disable pull-up resistor for PA0
//    GPIOA->ODR &= ~GPIO_ODR_ODR0;

    // Configure EXTI for PA0 (external interrupt)
    EXTI->FTSR |= EXTI_FTSR_TR0; // Set falling trigger for Line0 (button press)
    EXTI->RTSR &= ~EXTI_RTSR_TR0; // Disable rising trigger for Line0 (button release)
    EXTI->IMR |= EXTI_IMR_MR0; // Enable interrupt on EXTI Line0

    // Enable and set EXTI0_IRQn (IRQ for PA0) in NVIC
    NVIC_SetPriority(EXTI0_IRQn, 1); // Set priority
		NVIC_EnableIRQ(EXTI0_IRQn);
}


void EXTI0_IRQHandler(void) {
    if (EXTI->PR & EXTI_PR_PR0) { // Check if EXTI Line0 interrupt occurred
        // Handle the switch press event here
				//UART2_SendChar('E');
			  UART2_SendChar('E');
			UART2_SendChar('A');
        // Clear the pending bit to acknowledge the interrupt
        EXTI->PR |= EXTI_PR_PR0;
    }
}

#include "ADC.h"
#include "stm32f10x.h"

void ADC_Init(void) {
    // Enable GPIOA clock
    RCC->APB2ENR |= RCC_APB2ENR_IOPAEN;

    // Configure PA1 as analog input
    GPIOA->CRL &= ~(GPIO_CRL_MODE1 | GPIO_CRL_CNF1);

    // Enable ADC1 clock
    RCC->APB2ENR |= RCC_APB2ENR_ADC1EN;

    // Disable ADC before configuration
    ADC1->CR2 &= ~ADC_CR2_ADON;

    // Set ADC prescaler to 6 (ADC clock = 72MHz / 6 = 12MHz)
    RCC->CFGR |= RCC_CFGR_ADCPRE_DIV6;

    // Configure ADC: set sampling time for channel 1 (PA1)
    ADC1->SMPR2 |= ADC_SMPR2_SMP1; // Default sampling time is sufficient

    // Set channel 1 as the first conversion in the sequence
    ADC1->SQR3 = 1;

    // Enable ADC1
    ADC1->CR2 |= ADC_CR2_ADON;
}

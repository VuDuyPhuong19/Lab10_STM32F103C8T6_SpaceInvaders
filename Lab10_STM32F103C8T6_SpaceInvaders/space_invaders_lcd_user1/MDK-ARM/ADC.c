#include "ADC.h"
#include "stm32f10x.h"

//void ADC_Init(void){ uint32_t delay;
//	// Enable ADC clock
//	RCC->APB2ENR |= RCC_APB2ENR_ADC1EN;
//	// Configure GPIO Port A 
//	RCC->APB2ENR |= RCC_APB2ENR_IOPAEN;
//	delay = RCC->APB2ENR;
//	// Set A0 is analog input
//	GPIOA->CRL &= ~(GPIO_CRL_MODE0 | GPIO_CRL_CNF0);  // A0
//	
//	// Set ADC prescaler to 6 (ADC clock = 72MHz / 6 = 12 MHz)
//	RCC->CFGR = RCC_CFGR_ADCPRE_DIV6; 
//	ADC1->CR2 &= ~ADC_CR2_ADON;
//	
//	// Configure ADC channel
//	ADC1->SQR1  = 0x0;
//	ADC1->SQR3 = 0x0;
//	
//	ADC1->SMPR2 &= ~ADC_SMPR2_SMP0_2;
//	ADC1->SMPR2 |= ADC_SMPR2_SMP0_2; // Sample time , 41,5 x 1/12M
//	
//	// Starts conversion of the regular channel
//	ADC1->CR2 &= ADC_CR2_SWSTART;
//	ADC1->CR2 |= ADC_CR2_SWSTART;
//	
//	ADC1->CR2 &= ~ADC_CR2_CONT;
//	ADC1->CR2 |= ADC_CR2_CONT; // Enable Continous conversion mode
//	ADC1->CR2 |= ADC_CR2_ADON; // Enable ADC 	
//	
//	while (!(ADC1->CR2 & ADC_CR2_ADON)){} // Wait for the ADC to complete initialization
//		
//	NVIC->ISER[0] = 1 << ADC1_2_IRQn;
//	ADC1->CR1 |= ADC_CR1_EOCIE; // B?t ng?t EOC cho ADC1
//}

//uint32_t ADC_In(void){
//	while(!(ADC1->SR &ADC_SR_EOC)){} // Wait for conversion to complete
//	uint32_t data = ADC1->DR & 0x0FFF;
//	return data;
//}

//void ADC_Init(void) {
//    uint32_t delay;
//    // Enable ADC clock
//    RCC->APB2ENR |= RCC_APB2ENR_ADC1EN;

//    // Configure GPIO Port A 
//    RCC->APB2ENR |= RCC_APB2ENR_IOPAEN;
//    delay = RCC->APB2ENR;

//    // Set PA1 as analog input (Clear bits 4:0, set bits 2:0 for PA1)
//    GPIOA->CRL &= ~(GPIO_CRL_MODE1 | GPIO_CRL_CNF1);
//    GPIOA->CRL |= GPIO_CRL_CNF1_1; // Set input mode for PA1

////    // Set ADC prescaler to 6 (ADC clock = 72MHz / 6 = 12 MHz)
////    RCC->CFGR = RCC_CFGR_ADCPRE_DIV6; 
//    ADC1->CR2 &= ~ADC_CR2_ADON;

//    // Configure ADC channel for PA1
//    ADC1->SQR1  = 0x0;
//    ADC1->SQR3 = 0x0;
//    ADC1->SQR3 |= 1; // Select channel 1 (PA1) as the first conversion in regular sequence

//    ADC1->SMPR2 &= ~ADC_SMPR2_SMP1; // Clear SMP bits for channel 1
//    ADC1->SMPR2 |= ADC_SMPR2_SMP1_2; // Set sample time for channel 1, 41.5 cycles at 12MHz

//    // Start conversion of the regular channel
//    ADC1->CR2 |= ADC_CR2_ADON; // Enable ADC
//    ADC1->CR2 |= ADC_CR2_CAL; // Start calibration

//    while (!(ADC1->CR2 & ADC_CR2_CAL)){} // Wait for calibration to complete

//    ADC1->CR2 &= ~ADC_CR2_CONT; // Disable continuous conversion mode
//    ADC1->CR2 |= ADC_CR2_ADON; // Enable ADC
//}

//uint32_t ADC_In(void){
//	while(!(ADC1->SR &ADC_SR_EOC)){} // Wait for conversion to complete
//	uint32_t data = ADC1->DR & 0x0FFF;
//	return data;
//}
/*void ADC1_2_IRQHandler(void) {
  if ((ADC1->SR & ADC_SR_EOC) != 0) {
    ADC1->SR &= ~ADC_SR_EOC;
  }
}*/

//void ADC_Init(void) {
//	 RCC->APB2ENR |= RCC_APB2ENR_IOPAEN;
//   GPIOA->CRL &= ~(GPIO_CRL_MODE1 | GPIO_CRL_CNF1);

//    // Enable ADC1 clock
//    RCC->APB2ENR |= RCC_APB2ENR_ADC1EN;

//	   // Set ADC prescaler to 6 (ADC clock = 72MHz / 6 = 12MHz)
//	  ADC1->CR2 &= ~ ADC_CR2_ADON; 
//    RCC->CFGR |= RCC_CFGR_ADCPRE_DIV6;
//	  ADC1->SQR3 = 0;                 // Set channel 0 as the first conversion in the sequence
//    ADC1->SMPR2 |= ADC_SMPR2_SMP0_2 ;//| ADC_SMPR2_SMP0_1; // Th?i gian l?y m?u
//   ADC1->CR2 |= ADC_CR2_ADON| ADC_CR2_CONT;  // Enable ADC1 and turn on Continuous conversion mode
//	// C?u hình các thông s? ADC
//  // ADC1->CR1 = 0; // Xóa các cài d?t tru?c dó
//  //ADC1->CR1 |= 0x00; // Ð? phân gi?i 12-bit
//  //ADC1->CR2 = 0; // Xóa các cài d?t tru?c dó
//   ADC1->CR2 |= ADC_CR2_SWSTART;
//	
//}
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

    // Enable ADC1 and set it to continuous conversion mode
//    ADC1->CR2 |= ADC_CR2_ADON | ADC_CR2_CONT;
    // Enable ADC1
    ADC1->CR2 |= ADC_CR2_ADON;

//    // Start ADC conversion
//    ADC1->CR2 |= ADC_CR2_SWSTART;
}
uint32_t ADC_In(void) {
	    // Start ADC conversion
    ADC1->CR2 |= ADC_CR2_SWSTART;
    // Wait for the end of conversion
//    while (!(ADC1->SR & ADC_SR_EOC)) {}

//    // Read and return ADC value
//    return ADC1->DR & 0xFFF;
}
void ADC_Reset(void){
	ADC1->CR2 |= ADC_CR2_ADON;
	ADC1->CR2 |= ADC_CR2_SWSTART;
}

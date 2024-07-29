#include "UART.h"

/*------------------UART1------------------*/

volatile uint8_t tx_buffer[BUFFER_SIZE];
volatile uint8_t tx_read = 0;
volatile uint8_t tx_write = 0;

volatile uint8_t rx_buffer[BUFFER_SIZE];
volatile uint8_t rx_read = 0;
volatile uint8_t rx_write = 0;

volatile uint8_t uart_received = 0;
volatile uint8_t received_data = 0;

/*------------------UART2------------------*/

volatile uint8_t tx_buffer_2[BUFFER_SIZE];
volatile uint8_t tx_read_2 = 0;
volatile uint8_t tx_write_2 = 0;

volatile uint8_t rx_buffer_2[BUFFER_SIZE];
volatile uint8_t rx_read_2 = 0;
volatile uint8_t rx_write_2 = 0;

volatile uint8_t uart_received_2 = 0;
volatile uint8_t received_data_2 = 0;

void UART1_Init_C(void){
	// APB2 : 72MHz
	// Enable the UART clock and GPIO clock
	RCC->APB2ENR |= (1 << 14); // Enable UART1 clock
	
  // Configure UART1 pins (PA9 -> TX, PA10 -> RX)
  RCC->APB2ENR |= RCC_APB2ENR_IOPAEN; // Enable GPIOA clock
	GPIOA->CRH &= ~(GPIO_CRH_MODE9 | GPIO_CRH_CNF9 | GPIO_CRH_MODE10 | GPIO_CRH_CNF10);
  GPIOA->CRH |= GPIO_CRH_MODE9; // Configure PA9 as alternate function push-pull
  GPIOA->CRH |= GPIO_CRH_CNF9_1; // Configure PA9 as alternate function push-pull
	GPIOA->CRH |= GPIO_CRH_CNF10_0; // Configure PA10 as input floating	
	
	// Enable the UART 
	USART1->CR1 = 0x00; // Clear all
	USART1->CR1 |= (1 << 13); // Enable USART
	
	// Define the word length
	USART1->CR1 &= ~(1 << 12); // 1 start bit, 8 data bits
	
	// Program the number of stop bits
	USART1->CR2 = 0x00; // Clear all
	USART1->CR2 &= ~(3 << 12); // 1 stop bit
	
	// Set baud rate
	USART1->BRR = (1 << 0) | (39 << 4); // Baud rate of 115200
	
	// Enable the Transmitter/Receiver
	USART1->CR1 |= (1 << 2); // Enable Receiver
	USART1->CR1 |= (1 << 3); // Enable Transmitter
	
	// Enable receive interrupt
	USART1->CR1 |= (1 << 5); // Enable RXNE Interrupt
	
	// Enable UART1 interrupt 
	NVIC_EnableIRQ(USART1_IRQn);
}

void UART2_Init(void){
	// APB1 : 36MHz
	// Enable the UART clock and GPIO clock
	RCC->APB1ENR |= (1 << 17); // Enable UART2 clock
	
  // Configure UART1 pins (PA2 -> TX, PA3 -> RX)
  RCC->APB2ENR |= RCC_APB2ENR_IOPAEN; // Enable GPIOA clock
	GPIOA->CRL &= ~(GPIO_CRL_MODE2 | GPIO_CRL_CNF2 | GPIO_CRL_MODE3 | GPIO_CRL_CNF3);
  GPIOA->CRL |= GPIO_CRL_MODE2; // Configure PA9 as alternate function push-pull
  GPIOA->CRL |= GPIO_CRL_CNF2_1; // Configure PA9 as alternate function push-pull
	GPIOA->CRL |= GPIO_CRL_CNF3_0; // Configure PA10 as input floating	
	
	// Enable the UART 
	USART2->CR1 = 0x00; // Clear all
	USART2->CR1 |= (1 << 13); // Enable USART
	
	// Define the word length
	USART2->CR1 &= ~(1 << 12); // 1 start bit, 8 data bits
	
	// Program the number of stop bits
	USART2->CR2 = 0x00; // Clear all
	USART2->CR2 &= ~(3 << 12); // 1 stop bit
	
	// Set baud rate
	USART2->BRR = (5 << 0) | (19 << 4); // Baud rate of 115200
	
	// Enable the Transmitter/Receiver
	USART2->CR1 |= (1 << 2); // Enable Receiver
	USART2->CR1 |= (1 << 3); // Enable Transmitter
	
	// Enable receive interrupt
	USART2->CR1 |= (1 << 5); // Enable RXNE Interrupt
	
	// Enable UART1 interrupt 
	NVIC_EnableIRQ(USART2_IRQn);
}

/*---------------------Interrupt--------------------*/

void UART1_SendChar(char c){
	tx_buffer[tx_write] = (uint8_t)c;
	tx_write = (tx_write + 1) % BUFFER_SIZE;
	USART1->CR1 |= USART_CR1_TXEIE; // Enable TXE interrupt
}

void UART2_SendChar(char c){
	tx_buffer_2[tx_write_2] = (uint8_t)c;
	tx_write_2 = (tx_write_2 + 1) % BUFFER_SIZE;
	USART2->CR1 |= USART_CR1_TXEIE; // Enable TXE interrupt
	// Transmit Data Register Empty Interrupt Enable
	// hoat dong nhu 1 cong tat de bat hoac tat khi thanh ghi 
	// thanh ghi UART_DR  trong
	// khi co nay duoc bat thi ngat TXE se xay ra khi moi thanh ghi du lieu trong
	// cho phep truyen du lieu tuc mà khong cam phai kiem tra trang thao thanh ghi du lieu
}

void UART1_SendString(char* str){
	while(*str) 
		UART1_SendChar(*str++);
}

void UART2_SendString(char* str){
	while(*str) 
		UART2_SendChar(*str++);
}

uint8_t UART1_GetChar(void){
    while (rx_read == rx_write){} // Wait until data is available
    uint8_t receive_data = rx_buffer[rx_read];
    rx_read = (rx_read + 1) % BUFFER_SIZE;
    return receive_data;
}

// USART1 interrupt handler
void USART1_IRQHandler (void){
    if (((USART1->SR & USART_SR_TXE) && (USART1->CR1 & USART_CR1_TXEIE))){
			//TXE (Transmit Data Register Empty)
			//1: Thanh ghi duu lieu trong, san sang nhan du lieu moi de gui di.
			//0 thanh ghi DR dang chua du lieu, chua san sang nhan du lieu moi
        if (tx_read != tx_write){
            USART1->DR = tx_buffer[tx_read];
            tx_read = (tx_read + 1) % BUFFER_SIZE;
        }
        else 
            USART1->CR1 &= ~USART_CR1_TXEIE;
    }
    
    if ((USART1->SR & USART_SR_RXNE)){
        uint8_t next_write = (rx_write + 1) % BUFFER_SIZE;
        if(next_write != rx_read) { // Check buffer overflow
            received_data = USART1->DR;
            uart_received = 1;
            rx_buffer[rx_write] = received_data;
            rx_write = next_write;
        }
    }
}

//// USART2 interrupt handler
//void USART2_IRQHandler (void){
//    if (((USART2->SR & USART_SR_TXE) && (USART2->CR1 & USART_CR1_TXEIE))){
//        if (tx_read_2 != tx_write_2){
//            USART2->DR = tx_buffer_2[tx_read_2];
//            tx_read_2 = (tx_read_2 + 1) % BUFFER_SIZE;
//        }
//        else 
//            USART2->CR1 &= ~USART_CR1_TXEIE;
//    }
//    
//    if ((USART2->SR & USART_SR_RXNE)){
//        uint8_t next_write_2 = (rx_write_2 + 1) % BUFFER_SIZE;
//        if(next_write_2 != rx_read_2) { // Check buffer overflow
//            received_data_2 = USART2->DR;
//            uart_received_2 = 1;
//            rx_buffer_2[rx_write_2] = received_data_2;
//            rx_write_2 = next_write_2;
//        }
//    }
//}



#ifndef _UART_H_
#define _UART_H_

#include "stm32f10x.h"
#include <stdint.h>

#define BUFFER_SIZE 100

/*------------------UART1------------------*/

extern volatile uint8_t tx_buffer[BUFFER_SIZE];
extern volatile uint8_t rx_buffer[BUFFER_SIZE];
extern volatile uint8_t rx_write;
extern volatile uint8_t rx_read;
extern volatile uint8_t tx_read;
extern volatile uint8_t tx_write;
extern volatile uint8_t uart_received;
extern volatile uint8_t received_data;

/*------------------UART2------------------*/

extern volatile uint8_t tx_buffer_2[BUFFER_SIZE];
extern volatile uint8_t rx_buffer_2[BUFFER_SIZE];
extern volatile uint8_t rx_write_2;
extern volatile uint8_t rx_read_2;
extern volatile uint8_t tx_read_2;
extern volatile uint8_t tx_write_2;
extern volatile uint8_t uart_received_2;
extern volatile uint8_t received_data_2;

// Configure UART1
void UART1_Init(void);
// Transmit data
void UART1_SendChar(char c);
// Transmit String
void UART1_SendString(char* str);
// Receive Char
uint8_t UART1_GetChar(void);

// Configure UART2
void UART2_Init(void);
// Transmit data
void UART2_SendChar(char c);
// Transmit String
void UART2_SendString(char* str);
// Receive Char
uint8_t UART2_GetChar(void);

#endif 
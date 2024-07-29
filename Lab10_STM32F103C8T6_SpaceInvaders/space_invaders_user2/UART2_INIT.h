#ifndef UART2_INIT_H
#define UART2_INIT_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

extern volatile uint8_t tx_char_2_A;
extern volatile uint8_t uart_received_2_A;
extern volatile uint8_t received_data_2_A;

void UART2_Init_A(void);
void UART2_SendChar_A(char c);
void USART2_IRQHandler(void);

#ifdef __cplusplus
}
#endif

#endif // UART2_INIT_H

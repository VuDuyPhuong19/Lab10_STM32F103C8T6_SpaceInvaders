#include <stdint.h>
#include <stdio.h>
#include "PLL.h"
#include "ADC.h"
#include "UART.h"
#include "IO.h"
#include "Timer.h"
#include <string.h>
#include "UART2_INIT.h"
#include "SysTick.h"
void UART1_Init_C(void);

/*------------------UART2------------------*/
volatile uint8_t tx_char_2_A;
volatile uint8_t uart_received_2_A = 0;
volatile uint8_t received_data_2_A = 0;

char* int2char(uint16_t int_num, char* result) {
    // Ki?m tra n?u s? n?m ngoài ph?m vi 0-4095
    if (int_num > 4095) {
        return NULL;
    }

    // Chuy?n s? sang chu?i
    int i = 3;
    result[4] = '\0'; // Ð?t kí t? null k?t thúc chu?i

    // L?y t?ng ch? s? và gán vào chu?i
    while (int_num > 0) {
        result[i--] = '0' + (int_num % 10);
        int_num /= 10;
    }

    // N?u s? có ít hon 4 ch? s?, thêm '0' vào d?u
    while (i >= 0) {
        result[i--] = '0';
    }

    return result;
}

int main(void){
	
	PLL_Init();
	IO_Init();
	ADC_Init();
	Timer3A_Init(333, 0); // 10000 / 30 (30Hz)
	UART1_Init_C();
	UART2_Init_A();
	SysTick_Init();
	
	char adc_data_buffer[5];
	 UART2_SendChar('9');
	 UART2_SendChar('9');
	while(1){
//		if (ADCstatus == 1){
//			ADCstatus = 0;
//			
//			// Wait for the end of conversion
//			while (!(ADC1->SR & ADC_SR_EOC)) {}
//				
//			// Read and return ADC value
//			ADCData = ADC1->DR & 0xFFF;
//				
//			char* tx_string = int2char(ADCData, adc_data_buffer);
//			UART1_SendString(tx_string);
		 //UART2_SendChar('9');
		UART2_SendChar_A('A');
		UART2_SendChar_A('B');
		//UART2_SendChar_A('\n');
		 //UART2_SendChar('9');
		//UART2_SendChar('\n');
		 if (uart_received_2_A) {
           uart_received_2_A = 0; // Xóa c?
           UART2_SendChar_A('9');
            
        }

		 SysTick_Wait10ms(100);
		 
		}


//		if(uart_received){
//			rx_write = 0;
//			rx_read = 0;
//			tx_read = 0;
//			tx_write = 0;
//				uart_received = 0;
////				UART1_SendChar(received_data);
//			UART1_SendString(rx_buffer);
//		}

//		if(uart_received_2){
//			rx_write_2 = 0;
//			rx_read_2 = 0;
//			tx_read_2 = 0;
//			tx_write_2 = 0;
//			uart_received_2 = 0;
////			UART2_SendString(rx_buffer_2);
//			if (strcmp(rx_buffer_2, "E") == 0) {
//					UART2_SendString("vuduyphuong");
//			}
//		}
		
	
}
	
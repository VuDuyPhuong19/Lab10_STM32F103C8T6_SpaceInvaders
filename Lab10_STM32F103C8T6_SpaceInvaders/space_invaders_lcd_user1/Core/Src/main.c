///* USER CODE BEGIN Header */
///**
//  ******************************************************************************
//  * @file           : main.c
//  * @brief          : Main program body
//  ******************************************************************************
//  * @attention
//  *
//  * Copyright (c) 2023 STMicroelectronics.
//  * All rights reserved.
//  *
//  * This software is licensed under terms that can be found in the LICENSE file
//  * in the root directory of this software component.
//  * If no LICENSE file comes with this software, it is provided AS-IS.
//  *
//  ******************************************************************************
//  */
///* USER CODE END Header */
///* Includes ------------------------------------------------------------------*/
//#include "main.h"

///* Private includes ----------------------------------------------------------*/
///* USER CODE BEGIN Includes */
//#include "st7735.h"
//#include "fonts.h"
//#include "image.h"
//#include "PLL.h"
//#include "Timer.h"
//#include "ADC.h"
//#include "IO.h"
//#include "SysTick.h"
//#include "UART.h"
//#include "Random.h"
//#include "SpaceInvaders.h"
//#include <string.h>


///* USER CODE END Includes */

///* Private typedef -----------------------------------------------------------*/
///* USER CODE BEGIN PTD */

///* USER CODE END PTD */

///* Private define ------------------------------------------------------------*/
///* USER CODE BEGIN PD */
//#define GPIOB_PIN_7 (1 << 7)
///* USER CODE END PD */

///* Private macro -------------------------------------------------------------*/
///* USER CODE BEGIN PM */

///* USER CODE END PM */

///* Private variables ---------------------------------------------------------*/
//SPI_HandleTypeDef hspi1;

///* USER CODE BEGIN PV */

///* USER CODE END PV */

///* Private function prototypes -----------------------------------------------*/
//void SystemClock_Config(void);
//static void MX_GPIO_Init(void);
//static void MX_SPI1_Init(void);
///* USER CODE BEGIN PFP */

///* USER CODE END PFP */

///* Private user code ---------------------------------------------------------*/
///* USER CODE BEGIN 0 */

///* USER CODE END 0 */

///**
//  * @brief  The application entry point.
//  * @retval int
//  */
//	
//void Dec2String(uint32_t num, char* str) {
//    uint32_t count = 0;
//    uint32_t tmp = num;
//    do {
//        tmp /= 10;
//        count++;
//    } while (tmp);
//  
//    str[count] = '\0';
//    while (count > 0) {
//        count--;
//        str[count] = num % 10 + '0';
//        num /= 10;
//    }
//}

//char* int2char(uint16_t int_num, char* result) {
//    // Ki?m tra n?u s? n?m ngoài ph?m vi 0-4095
//    if (int_num > 4095) {
//        return NULL;
//    }

//    // Chuy?n s? sang chu?i
//    int i = 3;
//    result[4] = '\0'; // Ð?t kí t? null k?t thúc chu?i

//    // L?y t?ng ch? s? và gán vào chu?i
//    while (int_num > 0) {
//        result[i--] = '0' + (int_num % 10);
//        int_num /= 10;
//    }

//    // N?u s? có ít hon 4 ch? s?, thêm '0' vào d?u
//    while (i >= 0) {
//        result[i--] = '0';
//    }

//    return result;
//}
////uint16_t char2int(char* str) {
////    uint16_t result = 0;

////    // Duy?t t?ng ký t? trong chu?i
////    for (int i = 0; str[i] != '\0'; i++) {
////        // Ki?m tra n?u ký t? không ph?i s?
////        if (str[i] < '0' || str[i] > '9') {
////            return 0; // Tr? v? 0 n?u chu?i không h?p l?
////        }

////        // Tính giá tr? s? t? ký t?
////        result = result * 10 + (str[i] - '0');

////        // Ki?m tra n?u k?t qu? vu?t quá gi?i h?n 0-4095
////        if (result > 4095) {
////            return 0;
////        }
////    }

////    return result;
////}

//uint16_t char2int(char* str) {
//    uint16_t result = 0;
//    uint16_t temp;

//    // Duy?t t?ng ký t? trong chu?i
//    for (int i = 0; str[i] != '\0'; i++) {
//        // Ki?m tra n?u ký t? không ph?i s?
//        if (str[i] < '0' || str[i] > '9') {
//            return UINT16_MAX; // Tr? v? m?t giá tr? d?c bi?t cho tru?ng h?p l?i
//        }

//        temp = result * 10 + (str[i] - '0');

//        // Ki?m tra n?u k?t qu? vu?t quá gi?i h?n 0-4095
//        if (temp > 4095) {
//            return UINT16_MAX; // Tr? v? m?t giá tr? d?c bi?t cho tru?ng h?p l?i
//        }

//        result = temp;
//    }

//    return result;
//}

//Battleship battleship_1;
//Battleship battleship_2;

//bool fill_flag=true;
//bool fill_flag_1=true;
//void fill_src(){
//	if(fill_flag){
//	ST7735_FillScreen(ST7735_PURPOSE);
//		background();
//	}
//}
//void fill_src_1(){
//	if(fill_flag_1){
//	ST7735_FillScreen(ST7735_PURPOSE);
//		background();
//	}
//}
//bool menu_start;
//bool game_start;
//bool menu_end;
//bool init_ship;
//int main(void)
//{
//  /* USER CODE BEGIN 1 */
////	__disable_irq();
//  /* USER CODE END 1 */

//  /* MCU Configuration--------------------------------------------------------*/

//  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
//  HAL_Init();

//  /* USER CODE BEGIN Init */

//  /* USER CODE END Init */

//  /* Configure the system clock */
////  SystemClock_Config();

//  /* USER CODE BEGIN SysInit */

//  /* USER CODE END SysInit */

//  /* Initialize all configured peripherals */
//  MX_GPIO_Init();
//  MX_SPI1_Init();
//  /* USER CODE BEGIN 2 */
//  ST7735_Init();
//  ST7735_Backlight_On();
//	Random_Init(1);
//  /* USER CODE END 2 */

//  /* Infinite loop */
//  /* USER CODE BEGIN WHILE */
//	PLL_Init();
//	IO_Init();
////	Timer2_Init(32767); // 30Hz
//	ADC_Init();
//	Timer3A_Init(333, 0); // 1Hz
//	UART1_Init();
//	UART2_Init();
////	TIM_Base_Start_IT();
////	NVIC_EnableIRQ(TIM2_IRQn);
//	SysTick_Init(72000000);
////	HAL_TIM_Base_Start_IT(&htim2);
////		ADC1->CR2 |= ADC_CR2_ADON; // Enable ADC 	
//	ST7735_FillScreen(ST7735_PURPOSE);
//	//background_init();
//	//background();
////	ST7735_DrawString(5,10,"Phu",Font_7x10,ST7735_YELLOW, ST7735_BLACK);
////	ST7735_DrawImage(83, 128, 45, 32, (uint16_t*) battleship_img);
////	ST7735_DrawImage(20, 0, 16, 10, (uint16_t*) enemy16x10);
//  //
//	char Message[12];
////	__enable_irq();
//	battleshipInit_1(&battleship_1);
//	battleshipInit_2(&battleship_2);
////	spriteInit();
//	
//	char adc_data_buffer[5];
//	spriteInit();
//	
////while(1){
//	while(1){
//   if(init_ship==1){
//		 battleshipBulletInit(&battleship_1);
//		 init_ship=0;
//	 }
////		if(uart_received){
////			rx_write = 0;
////			rx_read = 0;
////			tx_read = 0;
////			tx_write = 0;
////			uart_received = 0;
////			ADCData_2 = char2int(rx_buffer);
////		}
//		if(uart_received){
//			rx_write = 0;
//			rx_read = 0;
//			tx_read = 0;
//			tx_write = 0;
//			uart_received = 0;
//			UART1_SendString(rx_buffer);
//			ADCData_2 = char2int(rx_buffer);
//		}
//		
//		if(uart_received_2){
//				while (rx_read_2 != rx_write_2) {
//            // Check if the received command is 'E'
//            if (rx_buffer_2[rx_read_2] == 'E') {
//                // Clear the buffer since we process one command at a time
//                memset((char*)rx_buffer_2, '\0', BUFFER_SIZE);
//                UART2_SendString("E_rx");
//							battleshipBulletInit(&battleship_2);
//                //battleshipBulletInit_2(&battleship_2);
//                // Reset read and write pointers after processing the command
//                rx_read_2 = 0;
//                rx_write_2 = 0;
//                break; // Exit the while loop after processing the command
//            }
//            // Move to the next character
//            rx_read_2 = (rx_read_2 + 1) % BUFFER_SIZE;
//        }

//        // Reset the flag if no more data to process
//        if (rx_read_2 == rx_write_2) {
//            uart_received_2 = 0; // Reset the flag
//        }
//		}
//		if(ADCstatus == 1){
//			ADCstatus = 0;
//			// Wait for the end of conversion
//			while (!(ADC1->SR & ADC_SR_EOC)) {}
//			// Read and return ADC value
//			ADCData = ADC1->DR & 0xFFF;
//			if(game_start){
//				fill_src_1();
//				fill_flag_1=0;
//				background();
//				spriteMove(&battleship_1);
//			battleshipMove(&battleship_1);
//			battleshipMove_2(&battleship_2);
////			spriteMove();
//		battleshipBulletMove(&battleship_1);
//		battleshipBulletMove_1(&battleship_1);
//		battleshipBulletMove_2(&battleship_1);
//		battleshipBulletMove(&battleship_2);
//		battleshipBulletMove_1(&battleship_2);
//		battleshipBulletMove_2(&battleship_2);
//			//battleshipBulletMove_2(&battleship_2);
////		handleCollision(&battleship_1, &battleship_2);
//			}
//		stars_walk_1();
//		stars_walk_2();
//		stars_walk_3();
//		stars_walk_4();
////			if (endGame == 1) break;

//		}
//		if(current_fill_level<120){
//		menu_loading();
//		}
//		else menu_start=1;
//		if(menu_start && !menu_end){
//			fill_src();
//			menu();
//			fill_flag=0;
//		}
//		
//}
//	SysTick_Wait10ms(100); // Delay 1s
//	ST7735_FillScreen(0x0000);
//	if (battleship_2.life == dead) {
//	ST7735_DrawString(40,70,"Blue Win",Font_7x10,ST7735_YELLOW, ST7735_BLACK);
//	}
//	else ST7735_DrawString(40,70,"Red Win",Font_7x10,ST7735_YELLOW, ST7735_BLACK);
////	endGame = 0;
////	ADCstatus = 0;
////	SysTick_Wait10ms(200); // Delay 1s
////}
//  /* USER CODE END 3 */
//}

//void EXTI0_IRQHandler(void) {
//    if (EXTI->PR & EXTI_PR_PR0) { // Check if EXTI Line0 interrupt occurred
//        // Handle the switch press event here
//				//UART2_SendChar('E');
//				init_ship=1;
//			game_start=1;
//			menu_end=1;
//			//IO_HeartBeat(6);
////				GPIOB->ODR ^= 1 << 6;
//        // Clear the pending bit to acknowledge the interrupt
//        EXTI->PR |= EXTI_PR_PR0;
//    }
//}

///**
//  * @brief System Clock Configuration
//  * @retval None
//  */
//void SystemClock_Config(void)
//{
//  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
//  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

//  /** Initializes the RCC Oscillators according to the specified parameters
//  * in the RCC_OscInitTypeDef structure.
//  */
//  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
//  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
//  RCC_OscInitStruct.HSEPredivValue = RCC_HSE_PREDIV_DIV1;
//  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
//  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
//  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
//  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL9;
//  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
//  {
//    Error_Handler();
//  }

//  /** Initializes the CPU, AHB and APB buses clocks
//  */
//  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
//                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
//  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
//  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
//  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
//  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

//  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
//  {
//    Error_Handler();
//  }
//}

///**
//  * @brief SPI1 Initialization Function
//  * @param None
//  * @retval None
//  */
//static void MX_SPI1_Init(void)
//{

//  /* USER CODE BEGIN SPI1_Init 0 */

//  /* USER CODE END SPI1_Init 0 */

//  /* USER CODE BEGIN SPI1_Init 1 */

//  /* USER CODE END SPI1_Init 1 */
//  /* SPI1 parameter configuration*/
//  hspi1.Instance = SPI1;
//  hspi1.Init.Mode = SPI_MODE_MASTER;
//  hspi1.Init.Direction = SPI_DIRECTION_2LINES;
//  hspi1.Init.DataSize = SPI_DATASIZE_8BIT;
//  hspi1.Init.CLKPolarity = SPI_POLARITY_LOW;
//  hspi1.Init.CLKPhase = SPI_PHASE_1EDGE;
//  hspi1.Init.NSS = SPI_NSS_SOFT;
//  hspi1.Init.BaudRatePrescaler = SPI_BAUDRATEPRESCALER_4;
//  hspi1.Init.FirstBit = SPI_FIRSTBIT_MSB;
//  hspi1.Init.TIMode = SPI_TIMODE_DISABLE;
//  hspi1.Init.CRCCalculation = SPI_CRCCALCULATION_DISABLE;
//  hspi1.Init.CRCPolynomial = 10;
//  if (HAL_SPI_Init(&hspi1) != HAL_OK)
//  {
//    Error_Handler();
//  }
//  /* USER CODE BEGIN SPI1_Init 2 */

//  /* USER CODE END SPI1_Init 2 */

//}

///**
//  * @brief GPIO Initialization Function
//  * @param None
//  * @retval None
//  */
//static void MX_GPIO_Init(void)
//{
//  GPIO_InitTypeDef GPIO_InitStruct = {0};
///* USER CODE BEGIN MX_GPIO_Init_1 */
///* USER CODE END MX_GPIO_Init_1 */

//  /* GPIO Ports Clock Enable */
//  __HAL_RCC_GPIOD_CLK_ENABLE();
//  __HAL_RCC_GPIOA_CLK_ENABLE();
//  __HAL_RCC_GPIOB_CLK_ENABLE();

//  /*Configure GPIO pin Output Level */
//  HAL_GPIO_WritePin(GPIOB, RES_Pin|DC_Pin|CS_Pin|BL_Pin, GPIO_PIN_RESET);

//  /*Configure GPIO pins : RES_Pin DC_Pin CS_Pin BL_Pin */
//  GPIO_InitStruct.Pin = RES_Pin|DC_Pin|CS_Pin|BL_Pin;
//  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
//  GPIO_InitStruct.Pull = GPIO_NOPULL;
//  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
//  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

///* USER CODE BEGIN MX_GPIO_Init_2 */
///* USER CODE END MX_GPIO_Init_2 */
//}

///* USER CODE BEGIN 4 */

///* USER CODE END 4 */

///**
//  * @brief  This function is executed in case of error occurrence.
//  * @retval None
//  */
//void Error_Handler(void)
//{
//  /* USER CODE BEGIN Error_Handler_Debug */
//  /* User can add his own implementation to report the HAL error return state */
//  __disable_irq();
//  while (1)
//  {
//  }
//  /* USER CODE END Error_Handler_Debug */
//}

//#ifdef  USE_FULL_ASSERT
///**
//  * @brief  Reports the name of the source file and the source line number
//  *         where the assert_param error has occurred.
//  * @param  file: pointer to the source file name
//  * @param  line: assert_param error line source number
//  * @retval None
//  */
//void assert_failed(uint8_t *file, uint32_t line)
//{
//  /* USER CODE BEGIN 6 */
//  /* User can add his own implementation to report the file name and line number,
//     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
//  /* USER CODE END 6 */
//}
//#endif /* USE_FULL_ASSERT */











/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "st7735.h"
#include "fonts.h"
#include "image.h"
#include "PLL.h"
#include "Timer.h"
#include "ADC.h"
#include "IO.h"
#include "SysTick.h"
#include "UART.h"
#include "Random.h"
#include "SpaceInvaders.h"
#include <string.h>


/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
#define GPIOB_PIN_7 (1 << 7)
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
SPI_HandleTypeDef hspi1;

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_SPI1_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
	
void Dec2String(uint32_t num, char* str) {
    uint32_t count = 0;
    uint32_t tmp = num;
    do {
        tmp /= 10;
        count++;
    } while (tmp);
  
    str[count] = '\0';
    while (count > 0) {
        count--;
        str[count] = num % 10 + '0';
        num /= 10;
    }
}

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
//uint16_t char2int(char* str) {
//    uint16_t result = 0;

//    // Duy?t t?ng ký t? trong chu?i
//    for (int i = 0; str[i] != '\0'; i++) {
//        // Ki?m tra n?u ký t? không ph?i s?
//        if (str[i] < '0' || str[i] > '9') {
//            return 0; // Tr? v? 0 n?u chu?i không h?p l?
//        }

//        // Tính giá tr? s? t? ký t?
//        result = result * 10 + (str[i] - '0');

//        // Ki?m tra n?u k?t qu? vu?t quá gi?i h?n 0-4095
//        if (result > 4095) {
//            return 0;
//        }
//    }

//    return result;
//}

uint16_t char2int(char* str) {
    uint16_t result = 0;
    uint16_t temp;

    // Duy?t t?ng ký t? trong chu?i
    for (int i = 0; str[i] != '\0'; i++) {
        // Ki?m tra n?u ký t? không ph?i s?
        if (str[i] < '0' || str[i] > '9') {
            return UINT16_MAX; // Tr? v? m?t giá tr? d?c bi?t cho tru?ng h?p l?i
        }

        temp = result * 10 + (str[i] - '0');

        // Ki?m tra n?u k?t qu? vu?t quá gi?i h?n 0-4095
        if (temp > 4095) {
            return UINT16_MAX; // Tr? v? m?t giá tr? d?c bi?t cho tru?ng h?p l?i
        }

        result = temp;
    }

    return result;
}


Battleship battleship_1;
Battleship battleship_2;
bool fill_flag=true;
bool fill_flag_1=true;
void fill_src(){
	if(fill_flag){
	ST7735_FillScreen(ST7735_PURPOSE);
		background();
	}
}
void fill_src_1(){
	if(fill_flag_1){
	ST7735_FillScreen(ST7735_PURPOSE);
		background();
	}
}
bool menu_start;
bool game_start;
bool menu_end;
bool init_ship;
int count1;
volatile uint8_t countGenItem = 0;
volatile uint8_t countGenWaterItem = 0;
int main(void)
{
  /* USER CODE BEGIN 1 */
//	__disable_irq();
  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
//  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_SPI1_Init();
  /* USER CODE BEGIN 2 */
  ST7735_Init();
  ST7735_Backlight_On();
	Random_Init(1);
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
	PLL_Init();
	IO_Init();
//	Timer2_Init(32767); // 30Hz
	ADC_Init();
	Timer3A_Init(333, 0); // 1Hz
	UART1_Init();
	UART2_Init();
//	TIM_Base_Start_IT();
//	NVIC_EnableIRQ(TIM2_IRQn);
	SysTick_Init(72000000);
//	HAL_TIM_Base_Start_IT(&htim2);
//		ADC1->CR2 |= ADC_CR2_ADON; // Enable ADC 	
	ST7735_FillScreen(ST7735_PURPOSE);
//	ST7735_DrawString(5,10,"Phu",Font_7x10,ST7735_YELLOW, ST7735_BLACK);
//	ST7735_DrawImage(83, 128, 45, 32, (uint16_t*) battleship_img);
//	ST7735_DrawImage(20, 0, 16, 10, (uint16_t*) enemy16x10);
	char Message[12];
//	__enable_irq();
	battleshipInit_1(&battleship_1);
	battleshipInit_1(&battleship_2);
	init_fire();
	init_water();
	Initbullet(&battleship_1,&battleship_2);
//	spriteInit();
	spriteInit();
	char adc_data_buffer[5];
	

	while(1){
		  if(init_ship==1){
		 battleshipBulletInit(&battleship_1);
		 init_ship=0;
	 }
//		if(uart_received){
//			rx_write = 0;
//			rx_read = 0;
//			tx_read = 0;
//			tx_write = 0;
//			uart_received = 0;
//			UART1_SendString(rx_buffer);
//			ADCData_2 = char2int(rx_buffer);
//		}
//		
		if(uart_received){
			rx_write = 0;
			rx_read = 0;
			tx_read = 0;
			tx_write = 0;
			uart_received = 0;
			UART1_SendString(rx_buffer);
			ADCData_2 = char2int(rx_buffer);
			memset(rx_buffer,NULL,BUFFER_SIZE);
			//			char* temp;
//			UART1_SendString("aaaaaa");
//			int2char(ADCData_2, temp);
//			UART1_SendString(temp);
		}
		if(uart_received_2){
				while (rx_read_2 != rx_write_2) {
            // Check if the received command is 'E'
            if (rx_buffer_2[rx_read_2] == 'E') {
                // Clear the buffer since we process one command at a time
                memset((char*)rx_buffer_2, '\0', BUFFER_SIZE);
                UART2_SendString("E_rx");
                						battleshipBulletInit(&battleship_2);
							changestate();
                // Reset read and write pointers after processing the command
                rx_read_2 = 0;
                rx_write_2 = 0;
                break; // Exit the while loop after processing the command
            }
            // Move to the next character
            rx_read_2 = (rx_read_2 + 1) % BUFFER_SIZE;
        }

        // Reset the flag if no more data to process
        if (rx_read_2 == rx_write_2) {
            uart_received_2 = 0; // Reset the flag
        }
		}
		
		if(ADCstatus == 1){
			ADCstatus = 0;
			// Wait for the end of conversion
			while (!(ADC1->SR & ADC_SR_EOC)) {}
			// Read and return ADC value
			ADCData = ADC1->DR & 0xFFF;
							if(game_start){
				fill_src_1();
				fill_flag_1=0;
				background();
								countGenItem++;
			if (countGenItem == 150){
			countGenItem = 0;
			// Item Gen
				recover_fire();
				
//			battleshipBulletInit(&battleship_1);
			GPIOC->ODR ^= 1 << 13;
		}
			countGenWaterItem++;
			if (countGenWaterItem == 210){ // 7 seconds
				countGenWaterItem = 0;
				recover_water();
			}
			
			// Water Item Gen 
							
			move_water(&battleship_1,&battleship_2);
			move_fire(&battleship_1,&battleship_2);
				spriteMove(&battleship_1,&battleship_2);
		battleshipMove(&battleship_1);
		battleshipMove_2(&battleship_2);
		battleshipBulletMove(&battleship_1);
		battleshipBulletMove_1(&battleship_1);
		battleshipBulletMove_2(&battleship_1);
		battleshipBulletMove(&battleship_2);
		battleshipBulletMove_1(&battleship_2);
		battleshipBulletMove_2(&battleship_2);
							}
									stars_walk_1();
		stars_walk_2();
		stars_walk_3();
		stars_walk_4();
									if(current_fill_level<120){
		menu_loading();
		}
		else menu_start=1;
		if(menu_start && !menu_end){
			fill_src();
			menu();
			if(!(count1--)){
			background();
			count1=5;
			}
			fill_flag=0;
		}
			}
		if(Endgame()) break;
}
		ST7735_FillScreen(ST7735_PURPOSE);
		ST7735_DrawRoundRect(0,60,128,30,4,ST7735_WHITE);
	  ST7735_FillRoundRect(0,62, 128, 26, 4, ST7735_WHITE);
		ST7735_DrawString(20,70,"Qua dep traiii",Font_7x10,ST7735_PURPOSE,ST7735_WHITE);
//	SysTick_Wait10ms(100); // Delay 1s
//	ST7735_FillScreen(0x0000);
//	if (battleship_2.life == dead) {
//	ST7735_DrawString(40,70,"Blue Win",Font_7x10,ST7735_YELLOW, ST7735_BLACK);
//	}
//	else ST7735_DrawString(40,70,"Red Win",Font_7x10,ST7735_YELLOW, ST7735_BLACK);
  /* USER CODE END 3 */
}

void EXTI0_IRQHandler(void) {
    if (EXTI->PR & EXTI_PR_PR0) { // Check if EXTI Line0 interrupt occurred
        // Handle the switch press event here
//				UART2_SendChar('E');
							init_ship=1;
			game_start=1;
			menu_end=1;
//				GPIOB->ODR ^= 1 << 6;
        // Clear the pending bit to acknowledge the interrupt
        EXTI->PR |= EXTI_PR_PR0;
    }
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.HSEPredivValue = RCC_HSE_PREDIV_DIV1;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL9;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
	RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief SPI1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_SPI1_Init(void)
{

  /* USER CODE BEGIN SPI1_Init 0 */

  /* USER CODE END SPI1_Init 0 */

  /* USER CODE BEGIN SPI1_Init 1 */

  /* USER CODE END SPI1_Init 1 */
  /* SPI1 parameter configuration*/
  hspi1.Instance = SPI1;
  hspi1.Init.Mode = SPI_MODE_MASTER;
  hspi1.Init.Direction = SPI_DIRECTION_2LINES;
  hspi1.Init.DataSize = SPI_DATASIZE_8BIT;
  hspi1.Init.CLKPolarity = SPI_POLARITY_LOW;
  hspi1.Init.CLKPhase = SPI_PHASE_1EDGE;
  hspi1.Init.NSS = SPI_NSS_SOFT;
  hspi1.Init.BaudRatePrescaler = SPI_BAUDRATEPRESCALER_4;
  hspi1.Init.FirstBit = SPI_FIRSTBIT_MSB;
  hspi1.Init.TIMode = SPI_TIMODE_DISABLE;
  hspi1.Init.CRCCalculation = SPI_CRCCALCULATION_DISABLE;
  hspi1.Init.CRCPolynomial = 10;
  if (HAL_SPI_Init(&hspi1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN SPI1_Init 2 */

  /* USER CODE END SPI1_Init 2 */

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};
/* USER CODE BEGIN MX_GPIO_Init_1 */
/* USER CODE END MX_GPIO_Init_1 */

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOD_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, RES_Pin|DC_Pin|CS_Pin|BL_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pins : RES_Pin DC_Pin CS_Pin BL_Pin */
  GPIO_InitStruct.Pin = RES_Pin|DC_Pin|CS_Pin|BL_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

/* USER CODE BEGIN MX_GPIO_Init_2 */
/* USER CODE END MX_GPIO_Init_2 */
}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
/* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

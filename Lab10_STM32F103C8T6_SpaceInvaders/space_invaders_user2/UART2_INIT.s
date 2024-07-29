    AREA |.text|, CODE, READONLY    ; Define the area for the code
    THUMB                           ; Specify that this is THUMB code

    EXPORT UART2_Init_A             ; Make UART2_Init_A available externally

UART2_Init_A
    PUSH {lr}                       ; Save the link register

    ; Enable the UART2 clock and GPIOA clock
	; page 50
	;0x4002 1000 - Reset and clock control RCC
    LDR R1, =0x4002101C             ; RCC->APB1ENR
    LDR R0, [R1]                    ; Load RCC->APB1ENR
    ORRS R0, R0, #(1 << 17)         ; Set bit 17 to enable UART2 clock
    STR R0, [R1]                    ; Store the updated value back to RCC->APB1ENR

    ; Enable GPIOA clock
    LDR R1, =0x40021018             ; RCC->APB2ENR
    LDR R0, [R1]                    ; Load RCC->APB2ENR
    ORRS R0, R0, #(1 << 2)          ; Set bit 2 to enable GPIOA clock
    STR R0, [R1]                    ; Store the updated value back to RCC->APB2ENR

    ; Configure UART2 pins (PA2 -> TX, PA3 -> RX)
    LDR R1, =0x40010800             ; GPIOA->CRL
    LDR R0, [R1]                    ; Load GPIOA->CRL
    BIC R0, R0, #(0xFF << 8)        ; Clear configuration bits for PA2 and PA3
    ORRS R0, R0, #(0xB << 8)        ; Set PA2 as alternate function push-pull
    ORRS R0, R0, #(0x4 << 12)       ; Set PA3 as input floating
    STR R0, [R1]                    ; Store back to GPIOA->CRL
	; page 821 part 27.6
    ; Enable USART2, configure word length and stop bits
    LDR R1, =0x4000440C             ; USART2->CR1
    MOV R0, #0x2000                 ; USART Enable bit (bit 13)
    STR R0, [R1]

    LDR R1, =0x40004410             ; USART2->CR2
    MOV R0, #0                      ; Clear CR2 (1 stop bit is already clear)
    STR R0, [R1]
	;
    ; Set baud rate
    LDR R1, =0x40004408             ; USART2->BRR
    MOV R0, #0x138                  ; Baud rate of 115200 (assuming 36MHz clock)
    STR R0, [R1]

    ; Enable the Transmitter/Receiver
    LDR R1, =0x4000440C             ; USART2->CR1
    LDR R0, [R1]
    ORRS R0, R0, #(1 << 2)          ; Enable Receiver
    ORRS R0, R0, #(1 << 3)          ; Enable Transmitter
    ORRS R0, R0, #(1 << 5)          ; Enable RXNE Interrupt
    STR R0, [R1]

    ; Enable UART2 interrupt
	; page 202
	; page 208 
	; page 120 manual (2)
	; table 33 (2)
    LDR R1, =0xE000E104             ; NVIC ISER1 (UART2_IRQn is 38, ISER1 covers IRQ 32-63)
    MOV R0, #(1 << 6)               ; USART2_IRQn is 38, bit 6 in ISER1
    STR R0, [R1]

    POP {pc}                        ; Restore the link register and return

    END                             ; Mark the end of this file

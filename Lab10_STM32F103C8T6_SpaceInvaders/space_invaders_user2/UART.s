    AREA |.text|, CODE, READONLY    ; Define the area for the code
    THUMB                              ; Specify that this is THUMB code

    EXPORT UART1_Init_A                 ; Make UART1_Init available externally

UART1_Init_A
;    PUSH {r4, lr}          ; Save registers that will be used

;    ; Enable UART1 clock
;    LDR r1, =0x40021018    ; RCC->APB2ENR address
;    LDR r0, [r1]           ; Load current value of RCC->APB2ENR
;    ORR r0, r0, #(1 << 14) ; Set bit 14
;    STR r0, [r1]           ; Store back to RCC->APB2ENR

;    ; Enable GPIOA clock
;    LDR r0, [r1]           ; Load current value of RCC->APB2ENR
;    ORR r0, r0, #(1 << 2)  ; Set bit 2
;    STR r0, [r1]           ; Store back to RCC->APB2ENR

;    ; Configure PA9 and PA10 
;    LDR r1, =0x40010804    ; GPIOA->CRH address
;    LDR r0, [r1]           ; Load current value of GPIOA->CRH
;    BIC r0, r0, #(0xFF << 4) ; Clear configuration bits for PA9 and PA10
;    ORR r0, r0, #(0xB << 4) ; Set PA9 as alternate function push-pull
;    ORR r0, r0, #(0x4 << 8) ; Set PA10 as input floating
;    STR r0, [r1]           ; Store back to GPIOA->CRH

;    ; Enable USART1, configure word length, stop bits and baud rate
;    LDR r1, =0x4001380C    ; USART1->CR1 address
;    MOV r0, #0x200C        ; Enable USART, 8 data bits, enable receiver and transmitter
;    STR r0, [r1]

;    LDR r1, =0x40013810    ; USART1->CR2 address
;    MOV r0, #0             ; 1 stop bit
;    STR r0, [r1]

;    LDR r1, =0x40013808    ; USART1->BRR address
;    MOV r0, #0x0271        ; Baud rate of 115200
;    STR r0, [r1]

;    ; Enable receive interrupt and NVIC
;    LDR r1, =0x4001380C    ; USART1->CR1 address
;    LDR r0, [r1]           ; Load current value of USART1->CR1
;    ORR r0, r0, #(1 << 5)  ; Enable RXNE interrupt
;    STR r0, [r1]           ; Store back to USART1->CR1

;    LDR r0, =0x00000025    ; USART1_IRQn is 37
;    LDR r1, =0xE000E100    ; NVIC Enable Register address
;    MOV r2, #1             ; Value to set
;    LSL r2, r2, r0         ; Shift left by interrupt number
;    STR r2, [r1]           ; Enable interrupt

;    POP {r4, pc}           ; Restore registers and return
;	
;	BX LR ; return
;	
;	END
    PUSH {lr}                        ; Save the link register

    ; Enable the UART1 clock and GPIOA clock
    LDR R1, =0x40021018              ; RCC->APB2ENR
    LDR R0, [R1]                     ; Load RCC->APB2ENR
    ORRS R0, R0, #(1 << 14)          ; Set bit 14 to enable UART1 clock
    ORRS R0, R0, #(1 << 2)           ; Set bit 2 to enable GPIOA clock
    STR R0, [R1]                     ; Store the updated value back to RCC->APB2ENR

    ; Configure UART1 pins (PA9 -> TX, PA10 -> RX)
    LDR R1, =0x40010804              ; GPIOA->CRH
    LDR R0, [R1]                     ; Load GPIOA->CRH
	
;    BIC R0, R0, #(0xFF << 4)         ; Clear configuration bits for PA9 and PA10
	BIC R0, R0, #(0xFFFFFFFF)
	STR R0, [R1]
	LDR R0, [R1]
    ORRS R0, R0, #(0xB << 4)         ; Set PA9 as alternate function push-pull
    ORRS R0, R0, #(0x4 << 8)         ; Set PA10 as input floating
    STR R0, [R1]                     ; Store back to GPIOA->CRH

    ; Enable USART1, configure word length and stop bits
    LDR R1, =0x4001380C              ; USART1->CR1
    MOV R0, #0x2000                  ; USART Enable bit (bit 13)
    STR R0, [R1]

    LDR R1, =0x40013810              ; USART1->CR2
    MOV R0, #0                       ; Clear CR2 (1 stop bit is already clear)
    STR R0, [R1]

    ; Set baud rate
    LDR R1, =0x40013808              ; USART1->BRR
    MOV R0, #0x0271                  ; Baud rate of 115200
    STR R0, [R1]

    ; Enable the Transmitter/Receiver
    LDR R1, =0x4001380C              ; USART1->CR1
    LDR R0, [R1]
    ORRS R0, R0, #(1 << 2)           ; Enable Receiver
    ORRS R0, R0, #(1 << 3)           ; Enable Transmitter
    ORRS R0, R0, #(1 << 5)           ; Enable RXNE Interrupt
    STR R0, [R1]

    ; Enable UART1 interrupt
    LDR R1, =0xE000E100              ; NVIC ISER0
    MOV R0, #(1 << 5)                ; USART1_IRQn is 37, ISER0 covers IRQ 0-31
    STR R0, [R1]

    POP {pc}                         ; Restore the link register and return

    END                              ; Mark the end of this file
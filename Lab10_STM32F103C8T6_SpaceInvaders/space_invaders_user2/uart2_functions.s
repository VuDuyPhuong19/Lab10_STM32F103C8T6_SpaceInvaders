    AREA |.text|, CODE, READONLY
    THUMB
    EXPORT UART2_SendChar_A
    EXPORT USART2_IRQHandler

    ; Bien to�n cuc
    IMPORT received_data_2_A
    IMPORT uart_received_2_A
    IMPORT tx_char_2_A

    ; USART2 address
USART2_SR     EQU 0x40004400
USART2_DR     EQU 0x40004404
USART2_CR1    EQU 0x4000440C

    ; UART2_SendChar_A
UART2_SendChar_A
    PUSH {lr}                       ; Luu li�n k?t

    ; Luu k� tu v�o bien to�n cuc tx_char_2_A
    LDR r1, =tx_char_2_A
    STRB r0, [r1]

    ; Bat ngat TXE
    LDR r1, =USART2_CR1
    LDR r2, [r1]
    ORR r2, r2, #(1 << 7)           ; Bit TXEIE (bit 7) trong USART_CR1
    STR r2, [r1]

    POP {pc}                        ; Kh�i phuc li�n ket v� tro ve

    ; Tr�nh xu ly ngat USART2
USART2_IRQHandler
    PUSH {lr}                       ; Luu li�n ket

    ; Xu l� ngat TXE
    LDR r1, =USART2_SR
    LDR r2, [r1]
    TST r2, #(1 << 7)               ; Kiem tra bit TXE trong USART_SR
    BEQ check_rxne                  ; Neu kh�ng c� ngat TXE, kiem tra RXNE

    ; �oc k� tu tu bien tx_char_2_A
    LDR r1, =tx_char_2_A
    LDRB r3, [r1]

    ; Gui k� tu qua USART2
    LDR r1, =USART2_DR
    STRB r3, [r1]

    ; V� hieu h�a ngat TXE
    LDR r1, =USART2_CR1
    LDR r2, [r1]
    BIC r2, r2, #(1 << 7)           ; Tat bit TXEIE (bit 7) trong USART_CR1
    STR r2, [r1]

check_rxne
    ; Kiem tra RXNE
    LDR r1, =USART2_SR
    LDR r2, [r1]
    TST r2, #(1 << 5)               ; Kiem tra bit RXNE trong USART_SR
    BEQ end_irq                     ; Neu kh�ng c� ngat RXNE, ket th�c ngat

    ; �oc k� tu tu USART2
    LDR r1, =USART2_DR
    LDRB r2, [r1]

    ; Luu k� tu v�o bien to�n cuc
    LDR r1, =received_data_2_A
    STRB r2, [r1]

    ; �at co uart_received_2_A
    LDR r1, =uart_received_2_A
    MOV r2, #1
    STRB r2, [r1]

end_irq
    POP {lr}
    BX lr                           ; Kh�i phuc li�n ket v� tro ve

    END

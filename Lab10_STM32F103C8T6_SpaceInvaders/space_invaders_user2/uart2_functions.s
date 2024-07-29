    AREA |.text|, CODE, READONLY
    THUMB
    EXPORT UART2_SendChar_A
    EXPORT USART2_IRQHandler

    ; Bien toàn cuc
    IMPORT received_data_2_A
    IMPORT uart_received_2_A
    IMPORT tx_char_2_A

    ; USART2 address
USART2_SR     EQU 0x40004400
USART2_DR     EQU 0x40004404
USART2_CR1    EQU 0x4000440C

    ; UART2_SendChar_A
UART2_SendChar_A
    PUSH {lr}                       ; Luu liên k?t

    ; Luu ký tu vào bien toàn cuc tx_char_2_A
    LDR r1, =tx_char_2_A
    STRB r0, [r1]

    ; Bat ngat TXE
    LDR r1, =USART2_CR1
    LDR r2, [r1]
    ORR r2, r2, #(1 << 7)           ; Bit TXEIE (bit 7) trong USART_CR1
    STR r2, [r1]

    POP {pc}                        ; Khôi phuc liên ket và tro ve

    ; Trình xu ly ngat USART2
USART2_IRQHandler
    PUSH {lr}                       ; Luu liên ket

    ; Xu lý ngat TXE
    LDR r1, =USART2_SR
    LDR r2, [r1]
    TST r2, #(1 << 7)               ; Kiem tra bit TXE trong USART_SR
    BEQ check_rxne                  ; Neu không có ngat TXE, kiem tra RXNE

    ; Ðoc ký tu tu bien tx_char_2_A
    LDR r1, =tx_char_2_A
    LDRB r3, [r1]

    ; Gui ký tu qua USART2
    LDR r1, =USART2_DR
    STRB r3, [r1]

    ; Vô hieu hóa ngat TXE
    LDR r1, =USART2_CR1
    LDR r2, [r1]
    BIC r2, r2, #(1 << 7)           ; Tat bit TXEIE (bit 7) trong USART_CR1
    STR r2, [r1]

check_rxne
    ; Kiem tra RXNE
    LDR r1, =USART2_SR
    LDR r2, [r1]
    TST r2, #(1 << 5)               ; Kiem tra bit RXNE trong USART_SR
    BEQ end_irq                     ; Neu không có ngat RXNE, ket thúc ngat

    ; Ðoc ký tu tu USART2
    LDR r1, =USART2_DR
    LDRB r2, [r1]

    ; Luu ký tu vào bien toàn cuc
    LDR r1, =received_data_2_A
    STRB r2, [r1]

    ; Ðat co uart_received_2_A
    LDR r1, =uart_received_2_A
    MOV r2, #1
    STRB r2, [r1]

end_irq
    POP {lr}
    BX lr                           ; Khôi phuc liên ket và tro ve

    END

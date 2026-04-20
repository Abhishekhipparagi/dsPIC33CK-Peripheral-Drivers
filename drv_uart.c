/**
 * @file    drv_uart.c
 * @brief   UART1 driver ? async 8N1, polled TX, interrupt RX
 * @author  Abhishek Hipparagi
 *
 * Baud calculation (standard speed, BRGH = 0):
 *   U1BRG = FCY / (16 * baud) - 1 = 75 000 000 / 153 600 - 1 = 488
 */

#include "main.h"

/* ------------------------------------------------------------------ */
void DRV_UART_Init(void) {
    
    // U1BRG = FCY / (16 * baud) - 1 = 75 000 000 / 153 600 - 1 = 488
    U1BRG = 488; /* 9600 baud @ 75 MHz FCY          */

    U1MODEbits.MOD = 0; /* Async 8-bit, no parity          */
    U1MODEbits.ABAUD = 0; /* No auto-baud                    */
    U1MODEbits.BRGH = 0; /* Standard speed (16x clock)      */

    U1MODEbits.UARTEN = 1; /* Enable UART module              */
    U1MODEbits.UTXEN = 1; /* Enable transmitter              */
    U1MODEbits.URXEN = 1; /* Enable receiver                 */

    U1STA = 0x0000; /* Clear status                    */

    /* RX interrupt */
    IFS0bits.U1RXIF = 0;
    IEC0bits.U1RXIE = 1;
    IPC2bits.U1RXIP = 2;
}

/* ------------------------------------------------------------------ */
void DRV_UART_WriteChar(char c) {
    while (IFS0bits.U1TXIF == 0); /* Wait for TX buffer space */
    U1TXREG = c;
    MSDelay(1);
}

/* ------------------------------------------------------------------ */
void DRV_UART_WriteString(const char *str) {
    while (*str)
        DRV_UART_WriteChar(*str++);
}

/* ------------------------------------------------------------------ */
void DRV_UART_RxHandler(void) {
    if (U1STAbits.OERR) /* Clear overrun if set */
        U1STAbits.OERR = 0;

    char rx = U1RXREG;
    DRV_UART_WriteChar(rx); /* Echo back */
}
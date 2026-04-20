/**
 * @file    drv_uart.h
 * @brief   UART1 driver ? 9600 baud, 8N1, interrupt-driven RX
 * @author  Abhishek Hipparagi
 */

#ifndef DRV_UART_H
#define DRV_UART_H

/** @brief  Initialise UART1: 9600 baud, 8N1, RX interrupt enabled (priority 2). */
void DRV_UART_Init(void);

/** @brief  Transmit a single character (blocking). */
void DRV_UART_WriteChar(char c);

/** @brief  Transmit a null-terminated string. */
void DRV_UART_WriteString(const char *str);

/** @brief  RX handler ? call from _U1RXInterrupt ISR. Echoes received byte. */
void DRV_UART_RxHandler(void);

#endif /* DRV_UART_H */
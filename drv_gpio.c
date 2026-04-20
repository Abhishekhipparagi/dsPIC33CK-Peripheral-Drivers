/**
 * @file    drv_gpio.c
 * @brief   GPIO direction setup and PPS remapping for UART1
 * @author  Abhishek Hipparagi
 */

#include "main.h"

void DRV_GPIO_Init(void)
{
    /* Digital I/O */
    TRISEbits.TRISE6 = 0;          /* RE6 output ? status LED  */
    TRISEbits.TRISE5 = 0;          /* RE5 output ? timer LED   */
    TRISEbits.TRISE7 = 1;          /* RE7 input  ? user button */

    /* PPS remap for UART1 */
    __builtin_write_RPCON(0x0000);  /* Unlock PPS                       */
    RPINR18bits.U1RXR = 67;        /* RD3 (RP67) -> UART1 RX           */
    RPOR18bits.RP68R  = 1;         /* UART1 TX   -> RD4 (RP68), fn = 1 */
    __builtin_write_RPCON(0x0800);  /* Lock PPS                         */
}
/**
 * @file    drv_clock.c
 * @brief   PLL clock initialisation ? 8 MHz XT crystal to 75 MIPS
 * @author  Abhishek Hipparagi
 */

#include "main.h"

void DRV_Clock_Init(void)
{
    /* PLL dividers: FVCO = (FIN / N1) * M = (8 / 2) * 150 = 600 MHz */
    CLKDIVbits.PLLPRE   = 1;       /* N1 = PLLPRE + 1 = 2             */
    PLLFBDbits.PLLFBDIV = 150;     /* M  = 150                        */
    PLLDIVbits.POST1DIV = 4;       /* N2 = 4  -> FOSC = 600/4 = 150   */
    PLLDIVbits.POST2DIV = 1;       /* N3 = 1  -> FCY  = 150/2 = 75    */

    /* Request switch: FRC -> Primary Oscillator + PLL (NOSC = 0x03) */
    __builtin_write_OSCCONH(0x03);
    __builtin_write_OSCCONL(OSCCON | 0x01);

    while (OSCCONbits.OSWEN);      /* Wait for oscillator switch */
    while (!OSCCONbits.LOCK);       /* Wait for PLL lock          */
}
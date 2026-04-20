/**
 * @file    drv_capture.c
 * @brief   CCP2 input capture ? rising-edge frequency measurement
 * @author  Abhishek Hipparagi
 *
 * On each rising edge the hardware latches the timer count with zero
 * software jitter. The ISR computes:
 *   frequency = FCY / (prescaler × captured_count)
 */

#include "main.h"

void DRV_Capture_Init(void)
{
    TRISDbits.TRISD2 = 1;          /* CCP2 input pin                  */

    /* PPS: map RP66 (RD2) -> ICM2 input */
    __builtin_write_RPCON(0x0000);
    RPINR4bits.ICM2R = 66;
    __builtin_write_RPCON(0x0800);

    CCP2CON1Lbits.CCPON  = 0;      /* Disable during config           */
    CCP2CON1Lbits.CCSEL  = 1;      /* Input capture mode              */
    CCP2CON1Lbits.MOD    = 1;      /* Capture every rising edge       */
    CCP2CON1Lbits.CLKSEL = 0;      /* Timer clock = FCY               */
    CCP2CON1Lbits.TMRPS  = 3;      /* Prescaler 1:64                  */

    CCP2CON2Hbits.ICSEL  = 0;      /* Source = ICx pin (via PPS)      */
    CCP2CON1Hbits.OPS3   = 0;      /* Interrupt on every capture      */

    /* Interrupt */
    IFS1bits.CCP2IF = 0;
    IEC1bits.CCP2IE = 1;
    IPC5bits.CCP2IP = 6;

    CCP2CON1Lbits.CCPON = 1;       /* Start capture                   */
}
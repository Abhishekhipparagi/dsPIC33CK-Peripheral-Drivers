/**
 * @file    drv_timer.c
 * @brief   CCP1 periodic timer ? 2.5 ms tick using SCCP in timer mode
 * @author  Abhishek Hipparagi
 *
 * PRL = target_period / tick_period
 *     = 2.5 ms / (64 / 75 MHz)
 *     = 2.5e-3 / 853.3e-9 ? 2929
 */

#include "main.h"

void DRV_Timer1_Init(void)
{
    CCP1CON1Lbits.CCPON  = 0;      /* Disable during config           */

    CCP1CON1Lbits.CCSEL  = 0;      /* Output compare / timer mode     */
    CCP1CON1Lbits.MOD    = 0;      /* Plain timer (no output)         */
    CCP1CON1Lbits.CLKSEL = 0;      /* Clock = FCY (75 MHz)            */
    CCP1CON1Lbits.T32    = 0;      /* 16-bit time base                */
    CCP1CON1Lbits.TMRPS  = 3;      /* Prescaler 1:64                  */

    CCP1PRL  = 2929;               /* Period ? 2.5 ms                 */
    CCP1TMRL = 0;                   /* Clear counter                   */

    /* Interrupt */
    IFS0bits.CCT1IF = 0;
    IEC0bits.CCT1IE = 1;
    IPC1bits.CCT1IP = 5;

    CCP1CON1Lbits.CCPON = 1;       /* Start timer                     */
}
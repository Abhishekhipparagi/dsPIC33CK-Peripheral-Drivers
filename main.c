/**
 * @file    main.c
 * @brief   Application entry point and interrupt service routines
 * @author  Abhishek Hipparagi
 * @date    2026
 *
 * Target: dsPIC33CK256MP508 @ 75 MIPS
 *
 * Peripherals used:
 *   PG1  ? Independent edge-aligned PWM, 20 kHz
 *   PG8  ? Center-aligned complementary PWM, 20 kHz (dead-time enabled)
 *   CCP1 ? 2.5 ms periodic timer
 *   CCP2 ? Input capture for frequency measurement
 *   ADC  ? AN0 (dedicated core) + AN23 (shared core), polled 12-bit
 *   UART1 ? 9600 baud debug console
 */

#include "bsp_config.h"
#include "main.h"

/* ---- Shared state (ISR ? main) ---- */
volatile uint32_t g_frequency = 0;

/* ==================================================================
 *  MAIN
 * ================================================================== */
int main(void)
{
    /* --- Initialise in dependency order --- */
    DRV_Clock_Init();
    DRV_GPIO_Init();
    DRV_UART_Init(); // 9600 baudrate

    DRV_PWM1_Init();
    DRV_PWM8_Init();
    DRV_Timer1_Init();
    DRV_Capture_Init();
    DRV_ADC_Init();

    DRV_UART_WriteString("System ready\r\n");

    /* --- Super-loop --- */
    char buf[16];

    while (1) {
        ClrWdt();

        /* Button test (active-low on RE7) */
        if (PORTEbits.RE7 == 0) {
            LATEbits.LATE6 = 1;
        }else
        {
            LATEbits.LATE6 = 0;
        }

        /* Print captured frequency */
        itoa_decimal(g_frequency, buf);
        DRV_UART_WriteString("FREQ: ");
        DRV_UART_WriteString(buf);
        DRV_UART_WriteString("\r\n");
        MSDelay(250);

        /* ADC readings */
        ClrWdt();
        uint16_t an0  = DRV_ADC_ReadAN0();
        uint16_t an23 = DRV_ADC_ReadAN23();

        itoa_decimal(an0, buf);
        DRV_UART_WriteString("AN0 : ");
        DRV_UART_WriteString(buf);
        DRV_UART_WriteString("\r\n");
        MSDelay(250);

        itoa_decimal(an23, buf);
        DRV_UART_WriteString("AN23: ");
        DRV_UART_WriteString(buf);
        DRV_UART_WriteString("\r\n");
        MSDelay(250);
    }
}

/* ==================================================================
 *  INTERRUPT SERVICE ROUTINES
 * ================================================================== */

/* UART1 RX */
void __attribute__((interrupt, auto_psv)) _U1RXInterrupt(void)
{
    IFS0bits.U1RXIF = 0;
    DRV_UART_RxHandler();
}

/* PWM1 ? independent edge-aligned */
void __attribute__((interrupt, no_auto_psv)) _PWM1Interrupt(void)
{
    IFS4bits.PWM1IF = 0;
    /* Update PG1DC here for closed-loop control */
}

/* PWM8 ? center-aligned complementary */
void __attribute__((interrupt, no_auto_psv)) _PWM8Interrupt(void)
{
    IFS4bits.PWM8IF = 0;
    /* Update PG8DC here for sine modulation */
}

/* CCP1 ? 2.5 ms periodic timer */
void __attribute__((interrupt, no_auto_psv)) _CCT1Interrupt(void)
{
    IFS0bits.CCT1IF = 0;
    /* Periodic task: control loop, soft-timers, etc. */
}

/* CCP2 ? input capture (frequency measurement) */
void __attribute__((interrupt, no_auto_psv)) _CCP2Interrupt(void)
{
    IFS1bits.CCP2IF = 0;
    LATEbits.LATE5 ^= 1;           /* Toggle LED as capture indicator */

    uint16_t ticks = CCP2TMRL;     /* Read hardware-captured count    */
    CCP2BUFL = 0;
    CCP2TMRL = 0;                   /* Reset for next period           */

    if (ticks)
        g_frequency = FCY / (64UL * ticks);
}
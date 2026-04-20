/**
 * @file    drv_pwm.c
 * @brief   PWM driver ? PG1 (independent) + PG8 (center-aligned complementary)
 * @author  Abhishek Hipparagi
 *
 * Period calculations (FPWM = 75 MHz):
 *
 *   PG1 (edge-aligned):
 *     PER = (FP × 2) / Fpwm = 150 000 000 / 20 000 = 7500
 *
 *   PG8 (center-aligned, triangle count ? effective frequency halved):
 *     PER = (FP × 2) / (Fpwm × 2) = 150 000 000 / 40 000 = 3750
 *
 * Dead-time budget (PG8):
 *   MOSFET fall ? 40 ns + gate driver delay ? 80 ns + PCB skew ? 10 ns + margin ? 100 ns
 *   Total ? 230 ns ? DTH/DTL = 230 / 13.3 ? 17 counts
 */

#include "main.h"

/* ---- Shared global PWM clock (called once, idempotent) ---- */
static void pwm_clock_init(void)
{
    PTGCONbits.PTGCLK = 0;         /* Source = FP (75 MHz)            */
    PTGCONbits.PTGDIV = 0;         /* ÷1 ? no prescaler              */
    PTGCONbits.PTGPWD = 0;         /* Trigger pulse width = 1 clock   */
}

/* ================================================================== */
/*  PG1 ? Independent Edge-Aligned PWM (20 kHz, PWM1H only)          */
/* ================================================================== */
void DRV_PWM1_Init(void)
{
    pwm_clock_init();
    TRISBbits.TRISB14 = 0;         /* PWM1H pin as output             */

    PG1CONLbits.ON     = 0;        /* Disable during config           */
    PG1CONLbits.CLKSEL = 1;        /* FPWM direct (75 MHz)            */
    PG1CONLbits.MODSEL = 0;        /* Independent edge-aligned        */

    PG1IOCONHbits.PMOD = 1;        /* Independent output mode         */
    PG1IOCONHbits.PENH = 1;        /* Enable PWM1H                    */
    PG1IOCONHbits.PENL = 0;        /* PWM1L unused                    */

    PG1PER = 7500;                  /* 20 kHz                          */
    PG1DC  = 3750;                  /* 50 % initial duty               */

    PG1EVTLbits.UPDTRG = 1;        /* Auto-update on PGxDC write      */

    /* Interrupt */
    IFS4bits.PWM1IF = 0;
    IEC4bits.PWM1IE = 1;
    IPC16bits.PWM1IP = 6;

    PG1CONLbits.ON = 1;            /* Start                           */
}

/* ================================================================== */
/*  PG8 ? Center-Aligned Complementary PWM (20 kHz, dead-time)       */
/* ================================================================== */
void DRV_PWM8_Init(void)
{
    pwm_clock_init();
    TRISCbits.TRISC12 = 0;         /* PWM8H pin                       */
    TRISCbits.TRISC13 = 0;         /* PWM8L pin                       */

    PG8CONLbits.ON     = 0;        /* Disable during config           */
    PG8CONLbits.CLKSEL = 1;        /* FPWM direct (75 MHz)            */
    PG8CONLbits.MODSEL = 4;        /* Center-aligned PWM              */

    /* Complementary output ? hardware enforces dead-time */
    PG8IOCONHbits.PMOD = 0;        /* Complementary mode              */
    PG8IOCONL = 0;
    PG8IOCONHbits.PENH = 1;        /* Enable PWM8H                    */
    PG8IOCONHbits.PENL = 1;        /* Enable PWM8L                    */
    PG8IOCONHbits.POLH = 0;        /* Active-high (no inversion)      */
    PG8IOCONHbits.POLL = 0;

    /* Dead-time: ~230 ns each edge */
    PG8DTH = 17;
    PG8DTL = 17;

    PG8PER = 3750;                  /* 20 kHz (triangle counter)       */
    PG8DC  = 1875;                  /* 50 % initial duty               */

    PG8EVTLbits.UPDTRG = 1;        /* Auto-update on PGxDC write      */

    /* Interrupt */
    IFS4bits.PWM8IF = 0;
    IEC4bits.PWM8IE = 1;
    IPC18bits.PWM8IP = 6;

    PG8CONLbits.ON = 1;            /* Start                           */
}
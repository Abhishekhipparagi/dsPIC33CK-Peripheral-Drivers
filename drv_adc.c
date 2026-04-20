/**
 * @file    drv_adc.c
 * @brief   12-bit ADC driver ? shared core (AN23) + dedicated core 0 (AN0)
 * @author  Abhishek Hipparagi
 *
 * Clock chain (both cores):
 *   TSRC      = FP = 75 MHz
 *   TCORESRC  = 75 / 4 = 18.75 MHz   (CLKDIV = 3 -> ÷4)
 *   TADCORE   = 18.75 / 4 = 4.6875 MHz  -> period ? 213 ns  (safe; min is 16 ns)
 *
 * Conversion time per sample:
 *   Shared:    10 TAD sample + 13 TAD convert = 23 × 213 ns ? 4.9 µs
 *   Dedicated: 8 TAD sample  + 13 TAD convert = 21 × 213 ns ? 4.5 µs
 */

#include "main.h"

/* ================================================================== */
void DRV_ADC_Init(void)
{
    ADCON1Lbits.ADON = 0;           /* Disable ADC during setup         */

    /* --- Pin config --- */
    TRISEbits.TRISE3   = 1;        /* RE3 input (shared core)          */
    ANSELEbits.ANSELE3 = 1;        /* RE3 analog                      */
    TRISAbits.TRISA0   = 1;        /* RA0 input (dedicated core 0)    */
    ANSELAbits.ANSELA0 = 1;        /* RA0 analog                      */

    /* --- Resolution & format --- */
    ADCON1Hbits.SHRRES = 3;        /* Shared core  : 12-bit           */
    ADCORE0Hbits.RES   = 3;        /* Dedicated 0  : 12-bit           */
    ADCON1Hbits.FORM   = 0;        /* Unsigned integer (0?4095)       */

    /* --- Clock source --- */
    ADCON3Hbits.CLKSEL = 0;        /* Source = FP (75 MHz)            */
    ADCON3Hbits.CLKDIV = 3;        /* ÷4 -> TCORESRC = 18.75 MHz     */

    /* --- Shared core timing --- */
    ADCON2Lbits.SHRADCS = 2;       /* ÷4 -> TADCORE ? 213 ns         */
    ADCON2Hbits.SHRSAMC = 10;      /* 10 TAD sample window            */

    /* --- Dedicated core 0 timing --- */
    ADCORE0Hbits.ADCS  = 2;        /* ÷4 -> same TADCORE              */
    ADCORE0Lbits.SAMC  = 8;        /* 8 TAD sample window             */
    ADCON4Lbits.SAMC0EN = 1;       /* Enable SAMC delay for core 0    */

    /* --- Channel assignment --- */
    ADCON4Hbits.C0CHS = 0;         /* Core 0 -> AN0                   */

    /* --- Trigger: software for both channels --- */
    ADTRIG0Lbits.TRGSRC0  = 0;     /* AN0  ? software trigger         */
    ADTRIG5Hbits.TRGSRC23 = 0;     /* AN23 ? software trigger         */

    /* --- Reference: AVDD / AVSS --- */
    ADCON3L = 0x0000;

    /* --- Power-up sequence --- */
    ADCON5Hbits.WARMTIME = 10;     /* 1024 TCORESRC warm-up           */
    ADCON5Lbits.C0PWR    = 1;      /* Power on dedicated core 0       */
    ADCON5Lbits.SHRPWR   = 1;      /* Power on shared core            */

    ADCON1Lbits.ADON = 1;          /* Enable ADC module               */

    while (!ADCON5Lbits.C0RDY);    /* Wait ? dedicated core ready     */
    while (!ADCON5Lbits.SHRRDY);   /* Wait ? shared core ready        */

    /* --- Enable digital logic --- */
    ADCON3Hbits.C0EN  = 1;         /* Dedicated core 0                */
    ADCON3Hbits.SHREN = 1;         /* Shared core                     */

    __delay_us(200);               /* Stabilisation guard              */
}

/* ================================================================== */
uint16_t DRV_ADC_ReadAN0(void)
{
    ADCON3Lbits.CNVCHSEL = 0;      /* Select AN0              */
    ADCON3Lbits.CNVRTCH  = 1;      /* Trigger conversion      */
    while (!ADSTATLbits.AN0RDY);   /* Poll for result         */
    ADCON3Lbits.CNVRTCH  = 0;      /* Clear trigger           */
    return ADCBUF0;
}

/* ================================================================== */
uint16_t DRV_ADC_ReadAN23(void)
{
    ADCON3Lbits.CNVCHSEL = 23;     /* Select AN23 (RE3)       */
    ADCON3Lbits.CNVRTCH  = 1;      /* Trigger conversion      */
    while (!ADSTATHbits.AN23RDY);  /* Poll for result         */
    ADCON3Lbits.CNVRTCH  = 0;      /* Clear trigger           */
    return ADCBUF23;
}
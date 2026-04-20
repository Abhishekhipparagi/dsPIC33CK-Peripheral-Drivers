/**
 * @file    bsp_config.h
 * @brief   Device configuration bits for dsPIC33CK256MP508
 * @author  Abhishek Hipparagi
 *
 * Crystal : 8 MHz external (XT)
 * FOSC    : 150 MHz
 * FCY     : 75 MHz (75 MIPS)
 */

#ifndef BSP_CONFIG_H
#define BSP_CONFIG_H

#include <xc.h>

/*--- Code Protection (all disabled) ---*/
#pragma config BWRP   = OFF
#pragma config BSS    = DISABLED
#pragma config BSEN   = OFF
#pragma config GWRP   = OFF
#pragma config GSS    = DISABLED
#pragma config CWRP   = OFF
#pragma config CSS    = DISABLED
#pragma config AIVTDIS = OFF
#pragma config BSLIM  = 0x1FFF

/*--- Oscillator ---*/
#pragma config FNOSC   = FRC        /* Start on internal FRC, switch to PLL in software */
#pragma config IESO    = OFF
#pragma config POSCMD  = XT         /* 8 MHz crystal                                    */
#pragma config OSCIOFNC = OFF
#pragma config FCKSM   = CSECMD     /* Clock switching enabled, fail-safe monitor off    */
#pragma config PLLKEN  = ON         /* Auto-fallback to FRC if PLL loses lock            */

/*--- Watchdog (normal mode, ~528 ms timeout) ---*/
#pragma config RWDTPS  = PS16384    /* Run-mode timeout: ~528 ms (LPRC @ 31 kHz)  */
#pragma config RCLKSEL = LPRC       /* WDT clocked from LPRC (independent of PLL) */
#pragma config WINDIS  = ON         /* Standard (non-windowed) WDT                */
#pragma config WDTWIN  = WIN25      /* Ignored when WINDIS = ON                   */
#pragma config SWDTPS  = PS1        /* Sleep WDT (unused ? no sleep in this app)  */
#pragma config FWDTEN  = ON         /* WDT always on ? ClrWdt() is mandatory      */

/*--- Debug ---*/
#pragma config BISTDIS = DISABLED   /* No factory BIST at boot   */
#pragma config ICS     = PGD3       /* Debugger on PGC3/PGD3     */
#pragma config JTAGEN  = OFF        /* JTAG off ? free up pins   */
#pragma config NOBTSWP = DISABLED   /* Boot swap allowed         */

/*--- Dead Man Timer (disabled) ---*/
#pragma config DMTIVTL = 0x0
#pragma config DMTIVTH = 0x0
#pragma config DMTCNTL = 0x0
#pragma config DMTCNTH = 0x0
#pragma config DMTDIS  = OFF

/*--- Peripherals ---*/
#pragma config ALTI2C1 = OFF
#pragma config ALTI2C2 = OFF
#pragma config ALTI2C3 = OFF
#pragma config SMBEN   = SMBUS
#pragma config SPI2PIN = PPS

/*--- Alternate Working Registers (unused) ---*/
#pragma config CTXT1 = OFF
#pragma config CTXT2 = OFF
#pragma config CTXT3 = OFF
#pragma config CTXT4 = OFF

/*--- Flash Partition (single-image, no dual boot) ---*/
#pragma config BSEQ  = 0xFFF
#pragma config IBSEQ = 0xFFF

#endif /* BSP_CONFIG_H */
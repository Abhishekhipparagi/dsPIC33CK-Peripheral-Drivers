/**
 * @file    drv_clock.h
 * @brief   PLL clock driver for dsPIC33CK256MP508
 * @author  Abhishek Hipparagi
 *
 * Configures the PLL to produce:
 *   FOSC = 150 MHz,  FCY = 75 MHz  (75 MIPS)
 *
 * PLL path:  FIN(8 MHz) -> /N1(2) -> x M(150) -> FVCO(600 MHz) -> /N2(4) /N3(1) -> FOSC
 */

#ifndef DRV_CLOCK_H
#define DRV_CLOCK_H

/**
 * @brief  Initialise PLL and switch from FRC to XT+PLL.
 *         Blocks until the PLL is locked and stable.
 */
void DRV_Clock_Init(void);

#endif /* DRV_CLOCK_H */
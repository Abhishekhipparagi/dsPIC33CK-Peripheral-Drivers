/**
 * @file    drv_adc.h
 * @brief   ADC driver ? shared core (AN23/RE3) + dedicated core 0 (AN0/RA0)
 * @author  Abhishek Hipparagi
 *
 * Both cores run at TADCORE ? 213 ns (well above the 16 ns minimum).
 * Resolution: 12-bit unsigned (0?4095).
 */

#ifndef DRV_ADC_H
#define DRV_ADC_H

#include <stdint.h>

/**
 * @brief  Initialise ADC module with shared core on AN23 and dedicated
 *         core 0 on AN0. Software-triggered, polled conversion.
 */
void DRV_ADC_Init(void);

/** @brief  Read AN0 via dedicated core 0. Blocks until conversion complete. */
uint16_t DRV_ADC_ReadAN0(void);

/** @brief  Read AN23 (RE3) via shared core. Blocks until conversion complete. */
uint16_t DRV_ADC_ReadAN23(void);

#endif /* DRV_ADC_H */
/**
 * @file    drv_timer.h
 * @brief   CCP1 periodic timer driver ? 2.5 ms tick
 * @author  Abhishek Hipparagi
 *
 * Uses SCCP1 in 16-bit timer mode.
 * Clock: FCY / 64 = 75 MHz / 64 ? tick ? 853 ns
 * Period: 2929 × 853 ns ? 2.5 ms
 */

#ifndef DRV_TIMER_H
#define DRV_TIMER_H

/** @brief  Initialise CCP1 as a 2.5 ms periodic timer. Interrupt priority 5. */
void DRV_Timer1_Init(void);

#endif /* DRV_TIMER_H */
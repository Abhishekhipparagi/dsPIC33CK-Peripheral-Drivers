/**
 * @file    drv_pwm.h
 * @brief   PWM driver ? PG1 independent edge + PG8 center-aligned complementary
 * @author  Abhishek Hipparagi
 *
 * PWM clock: FPWM = FP = 75 MHz (no prescaler)
 *
 * PG1 ? Independent edge-aligned, 20 kHz, PWM1H only
 *        Use case: buck converter, LED dimming
 *
 * PG8 ? Center-aligned complementary, 20 kHz, PWM8H + PWM8L with dead-time
 *        Use case: half-bridge inverter leg
 */

#ifndef DRV_PWM_H
#define DRV_PWM_H

#include <stdint.h>

/** @brief  Initialise PG1 in independent edge-aligned mode, 20 kHz, 50% duty.
 *          Interrupt enabled (priority 6). */
void DRV_PWM1_Init(void);

/** @brief  Initialise PG8 in center-aligned complementary mode, 20 kHz, 50% duty.
 *          Dead-time ? 230 ns. Interrupt enabled (priority 6). */
void DRV_PWM8_Init(void);

/**
 * @brief  Update PG1 duty cycle. Auto-committed at next PWM boundary.
 * @param  duty  Raw compare value (0 to PG1PER)
 */
static inline void DRV_PWM1_SetDuty(uint16_t duty) { PG1DC = duty; }

/**
 * @brief  Update PG8 duty cycle. Auto-committed at next PWM boundary.
 * @param  duty  Raw compare value (0 to PG8PER)
 */
static inline void DRV_PWM8_SetDuty(uint16_t duty) { PG8DC = duty; }

#endif /* DRV_PWM_H */
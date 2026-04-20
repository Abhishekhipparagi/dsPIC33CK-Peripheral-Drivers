/**
 * @file    drv_capture.h
 * @brief   CCP2 input capture driver ? frequency measurement on rising edges
 * @author  Abhishek Hipparagi
 *
 * Uses SCCP2 in input capture mode to timestamp rising edges.
 * Frequency = FCY / (prescaler × captured_ticks)
 *
 * Input pin: RD2 (remapped via PPS to ICM2, RP66)
 */

#ifndef DRV_CAPTURE_H
#define DRV_CAPTURE_H

#include <stdint.h>

/** @brief  Initialise CCP2 input capture ? rising edge, 1:64 prescaler, interrupt priority 6. */
void DRV_Capture_Init(void);

#endif /* DRV_CAPTURE_H */
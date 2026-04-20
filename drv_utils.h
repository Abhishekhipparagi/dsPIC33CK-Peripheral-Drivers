/**
 * @file    drv_utils.h
 * @brief   Lightweight conversion utilities (no stdlib dependency)
 * @author  Abhishek Hipparagi
 */

#ifndef DRV_UTILS_H
#define DRV_UTILS_H

/**
 * @brief  Convert a signed integer to a decimal ASCII string.
 * @param  num  Value to convert
 * @param  buf  Output buffer (must be ? 7 bytes for int16_t range)
 */
void itoa_decimal(int num, char *buf);

#endif /* DRV_UTILS_H */
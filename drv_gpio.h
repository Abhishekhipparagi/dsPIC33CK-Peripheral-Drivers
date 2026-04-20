/**
 * @file    drv_gpio.h
 * @brief   GPIO and PPS pin-mux driver
 * @author  Abhishek Hipparagi
 */

#ifndef DRV_GPIO_H
#define DRV_GPIO_H

/**
 * @brief  Configure GPIO directions and remap UART1 TX/RX via PPS.
 *
 * Pin assignments:
 *   RE6 ? output (status LED)
 *   RE5 ? output (timer LED)
 *   RE7 ? input  (user button)
 *   RD3 ? UART1 RX  (PPS RP67)
 *   RD4 ? UART1 TX  (PPS RP68)
 */
void DRV_GPIO_Init(void);

#endif /* DRV_GPIO_H */
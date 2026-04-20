/**
 * @file    main.h
 * @brief   Top-level application header ? system defines & driver includes
 * @author  Abhishek Hipparagi
 */

#ifndef MAIN_H
#define MAIN_H

/*--- System Clock ---*/
#define FOSC        150000000UL
#define FCY         (FOSC / 2)      /* 75 MHz instruction clock */

/*--- Standard headers (order matters: xc.h needs FCY for __delay) ---*/
#include <xc.h>
#include <libpic30.h>
#include <stdint.h>
#include <stdbool.h>

/*--- Convenience macros ---*/
#define MSDelay(ms)  __delay_ms(ms)
#define USDelay(us)  __delay_us(us)

/*--- Driver headers ---*/
#include "drv_clock.h"
#include "drv_gpio.h"
#include "drv_uart.h"
#include "drv_adc.h"
#include "drv_pwm.h"
#include "drv_timer.h"
#include "drv_capture.h"
#include "drv_utils.h"

#endif /* MAIN_H */
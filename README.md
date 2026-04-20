# dsPIC33CK Peripheral Driver Library

Bare-metal peripheral drivers for the **dsPIC33CK256MP508** running at 75 MIPS, written in C with the XC16 compiler. Designed for power electronics applications (SMPS, UPS, inverters).

## Hardware

| Parameter | Value |
|-----------|-------|
| MCU | dsPIC33CK256MP508 |
| Crystal | 8 MHz XT |
| FOSC | 150 MHz |
| FCY | 75 MHz (75 MIPS) |
| Compiler | Microchip XC16 |
| IDE | MPLAB X |

## Drivers

### Clock (`drv_clock`)
PLL configuration from 8 MHz crystal to 75 MIPS. Handles oscillator switching from FRC to XT+PLL with lock detection.

### UART (`drv_uart`)
Async 8N1 at 9600 baud. Polled TX, interrupt-driven RX with echo. PPS-remapped to RD3/RD4.

### ADC (`drv_adc`)
12-bit software-triggered conversions using both ADC architectures:
- **Dedicated core 0** on AN0 — fixed channel, deterministic timing
- **Shared core** on AN23 — multiplexed, flexible channel selection

Both cores run at TADCORE ≈ 213 ns with proper warm-up sequencing.

### PWM (`drv_pwm`)
Two PWM topologies from a single driver:

**PG1 — Independent Edge-Aligned (20 kHz)**
- Single output (PWM1H), sawtooth carrier
- Use case: buck/boost converter, LED driver

**PG8 — Center-Aligned Complementary (20 kHz)**
- Dual output (PWM8H + PWM8L), triangle carrier
- Hardware dead-time insertion (~230 ns per edge)
- Use case: half-bridge inverter leg, motor drive

### Timer (`drv_timer`)
SCCP1 configured as a 2.5 ms periodic timer using 16-bit mode with 1:64 prescaler. Suitable for control loop scheduling.

### Input Capture (`drv_capture`)
SCCP2 in input capture mode — timestamps rising edges with zero software jitter. Computes frequency from captured timer counts. PPS-remapped to RD2.

## Project Structure

```
├── bsp_config.h        Board config bits (WDT, oscillator, debug, safety)
├── main.h              System defines, FCY, driver includes
├── main.c              Init sequence, super-loop, ISR handlers
├── drv_clock.h/.c      PLL and oscillator switching
├── drv_gpio.h/.c       Pin direction and PPS remapping
├── drv_uart.h/.c       UART1 — 9600 8N1
├── drv_adc.h/.c        12-bit ADC (shared + dedicated core)
├── drv_pwm.h/.c        PWM1 independent + PWM8 complementary
├── drv_timer.h/.c      CCP1 periodic timer (2.5 ms)
├── drv_capture.h/.c    CCP2 input capture (frequency measurement)
└── drv_utils.h/.c      itoa conversion (no stdlib)
```

## Architecture Decisions

- **No HAL / MCC dependency** — all registers configured directly for full control and transparency
- **Driver-layer separation** — `main.c` never touches peripheral registers; all access goes through `DRV_*` APIs
- **ISR discipline** — flag clearing and minimal work inside ISRs; heavy processing stays in the super-loop
- **Watchdog always on** — `ClrWdt()` in the main loop; if firmware hangs, the MCU resets in ~528 ms
- **Dead-time budgeted from component specs** — not guessed: MOSFET fall time + gate driver propagation + PCB skew + safety margin

## Build

Open in MPLAB X with XC16 compiler. Select dsPIC33CK256MP508 as the target device. Connect debugger to PGC3/PGD3.

## Author

**Abhishek Hipparagi**
Embedded Systems Engineer — Bangalore, India
[GitHub](https://github.com/Abhishekhipparagi) · [LinkedIn](https://www.linkedin.com/in/abhishek-hipparagi)

/**
 * @file    drv_utils.c
 * @brief   Integer-to-ASCII conversion (no heap, no printf)
 * @author  Abhishek Hipparagi
 */

#include "main.h"

/* In-place buffer reverse */
static void reverse(char *str, int len)
{
    int i = 0, j = len - 1;
    while (i < j) {
        char tmp = str[i];
        str[i]   = str[j];
        str[j]   = tmp;
        i++; j--;
    }
}

void itoa_decimal(int num, char *buf)
{
    int i = 0;
    bool neg = false;

    if (num == 0) {
        buf[0] = '0';
        buf[1] = '\0';
        return;
    }

    if (num < 0) {
        neg = true;
        num = -num;
    }

    while (num) {
        buf[i++] = '0' + (num % 10);
        num /= 10;
    }

    if (neg)
        buf[i++] = '-';

    buf[i] = '\0';
    reverse(buf, i);
}
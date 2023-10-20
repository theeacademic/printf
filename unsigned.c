#include <stdarg.h>
#include <stdio.h>
#include "main.h"

/**
 * printf_unsigned - Print an unsigned integer from variable arguments
 * @args: va_list containing the unsigned integer to print
 * Return: The number of characters printed
 */
int printf_unsigned(va_list args)
{
    unsigned int num = va_arg(args, unsigned int);
    int count = 0;
    if (num == 0) {
        putchar('0');
        count++;
    } else {
        while (num > 0) {
            unsigned int digit = num % 10;
            num /= 10;
            putchar('0' + digit);
            count++;
        }
    }

    return count;
}

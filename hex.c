#include <stdarg.h>
#include <stdio.h>
#include "main.h"

/**
 * printf_hex - Print an integer in hexadecimal format (lowercase) from variable arguments
 * @args: va_list containing the integer to print in hexadecimal
 * Return: The number of characters printed
 */
int printf_hex(va_list args)
{
    unsigned int num = va_arg(args, unsigned int);
    int count = 0;
    void printHexadecimal(unsigned int n) {
        if (n >= 16) {
            printHexadecimal(n / 16);
        }

        int remainder = n % 16;
        if (remainder < 10) {
            putchar('0' + remainder);
        } else {
            putchar('a' + remainder - 10);
        }
        count++;
    }

    printHexadecimal(num);

    return count;
}

#include <stdarg.h>
#include <stdio.h>
#include "main.h"
/**
 * printf_HEX - Print an integer in hexadecimal format (uppercase) from variable arguments
 * @args: va_list containing the integer to print in hexadecimal
 * Return: The number of characters printed
 */
int printf_HEX(va_list args)
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
            putchar('A' + remainder - 10);
        }
        count++;
    }

    printHexadecimal(num);

    return count;
}

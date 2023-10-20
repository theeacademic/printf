#include <stdarg.h>
#include <stdio.h>
#include "main.h"
/**
 * printf_bin - Print an integer in binary format from variable arguments
 * @args: va_list containing the integer to print in binary
 * Return: The number of characters printed
 */
int printf_bin(va_list args)
{
    unsigned int num = va_arg(args, unsigned int);
    int count = 0;
    void printBinary(unsigned int n, int bits) {
        if (bits > 1) {
            printBinary(n >> 1, bits - 1);
        }
        putchar((n & 1) ? '1' : '0');
        count++;
    }

    printBinary(num, sizeof(unsigned int) * 8);

    return count;
}

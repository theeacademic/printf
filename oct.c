#include <stdarg.h>
#include <stdio.h>
#include "main.h"
/**
 * printf_oct - Print an integer in octal format from variable arguments
 * @args: va_list containing the integer to print in octal
 * Return: The number of characters printed
 */
int printf_oct(va_list args)
{
    unsigned int num = va_arg(args, unsigned int);
    int count = 0;
    void printOctal(unsigned int n) {
        if (n >= 8) {
            printOctal(n / 8);
        }
        putchar('0' + (n % 8));
        count++;
    }

    printOctal(num);

    return count;
}

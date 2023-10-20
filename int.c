#include <stdarg.h>
#include <stdio.h>
#include "main.h"

/**
 * printf_int - Print an integer from variable arguments
 * @args: va_list containing the integer to print
 * Return: The number of characters printed
 */
int printf_int(va_list args)
{
    int num = va_arg(args, int);
    return printf("%d", num);
}

/**
 * printf_dec - Print a decimal (floating-point) number from variable arguments
 * @args: va_list containing the decimal number to print
 * Return: The number of characters printed
 */
int printf_dec(va_list args)
{
    double decimal = va_arg(args, double);
    return printf("%lf", decimal);
}

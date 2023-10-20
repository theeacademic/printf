#include <stdarg.h>
#include <stdio.h>
#include "main.h"
/**
 * printf_char - Print a character from variable arguments
 * @args: va_list containing the character to print
 * Return: The number of characters printed (1)
 */
int printf_char(va_list args)
{
    char character = va_arg(args, int);
    putchar(character);
    return 1;
}

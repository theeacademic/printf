#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include "main.h"
/**
 * printf_srev - Print a string in reverse from variable arguments
 * @args: va_list containing the string to print in reverse
 * Return: The number of characters printed
 */
int printf_srev(va_list args)
{
    char *str = va_arg(args, char *);
    int count = 0;
    int length = strlen(str);

    for (int i = length - 1; i >= 0; i--) {
        putchar(str[i]);
        count++;
    }

    return count;
}

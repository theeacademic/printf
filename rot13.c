#include <stdarg.h>
#include <stdio.h>
#include "main.h"
/**
 * printf_rot13 - Print a ROT13-encoded string from variable arguments
 * @args: va_list containing the string to print in ROT13
 * Return: The number of characters printed
 */
int printf_rot13(va_list args)
{
    char *str = va_arg(args, char *);
    int count = 0;

    while (*str) {
        char c = *str;
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
            char base = (c >= 'a' && c <= 'z') ? 'a' : 'A';
            c = (c - base + 13) % 26 + base;
        }
        putchar(c);
        count++;
        str++;
    }

    return count;
}

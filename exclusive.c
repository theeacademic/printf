#include <stdarg.h>
#include <stdio.h>
#include "main.h"
/**
 * printf_exclusive_string - Print a string with non-readable characters
 * in hexadecimal (lowercase) from variable arguments
 * @args: va_list containing the string to print
 * Return: The number of characters printed
 */
int printf_exclusive_string(va_list args)
{
    char *str = va_arg(args, char *);
    int count = 0;

    if (str == NULL) {
        printf("(null)");
        count += 6;
    } else {
        while (*str) {
            if (*str < 32 || *str > 126) {
                printf("\\x%02x", (unsigned char)*str);
                count += 4;
            } else {
                putchar(*str);
                count++;
            }
            str++;
        }
    }

    return count;
}

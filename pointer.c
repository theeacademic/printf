#include <stdarg.h>
#include <stdio.h>
#include "main.h"
/**
 * printf_pointer - Print a pointer address from variable arguments
 * @args: va_list containing the pointer to print
 * Return: The number of characters printed
 */
int printf_pointer(va_list args)
{
    void *ptr = va_arg(args, void *);
    int count = 0;
    if (ptr == NULL) {
        printf("(nil)");
        count += 5;
    } else {
    
        printf("0x%lx", (unsigned long)ptr);
        count += 10;
    }

    return count;
}

#include <stdarg.h>
#include <stdio.h>

/**
 * convert_match - Structure to match format specifiers with corresponding functions
 * @id: Format specifier
 * @f: Corresponding function to handle the specifier
 */
typedef struct convert_match
{
    char *id;
    int (*f)(va_list args);
} convert_match;

int printf_string(va_list args);
int printf_char(va_list args);
int printf_37(va_list args);
int printf_int(va_list args);
int printf_dec(va_list args);
int printf_srev(va_list args);
int printf_rot13(va_list args);
int printf_bin(va_list args);
int printf_unsigned(va_list args);
int printf_oct(va_list args);
int printf_hex(va_list args);
int printf_HEX(va_list args);
int printf_exclusive_string(va_list args);
int printf_pointer(va_list args);

int _putchar(char c);

/**
 * _printf - Custom printf function
 * @format: Format string
 * @...: Variable number of arguments
 * Return: Number of characters printed
 */
int _printf(const char *format, ...)
{
    convert_match m[] = {
        {"%s", printf_string}, {"%c", printf_char},
        {"%%", printf_37},
        {"%i", printf_int}, {"%d", printf_dec}, {"%r", printf_srev},
        {"%R", printf_rot13}, {"%b", printf_bin}, {"%u", printf_unsigned},
        {"%o", printf_oct}, {"%x", printf_hex}, {"%X", printf_HEX},
        {"%S", printf_exclusive_string}, {"%p", printf_pointer}
    };

    va_list args;
    int i = 0, j, len = 0;

    va_start(args, format);
    if (format == NULL || (format[0] == '%' && format[1] == '\0'))
        return (-1);

    while (format[i] != '\0')
    {
        j = 13;
        while (j >= 0)
        {
            if (m[j].id[0] == format[i] && m[j].id[1] == format[i + 1])
            {
                len += m[j].f(args);
                i = i + 2;
                goto Here;
            }
            j--;
        }
        _putchar(format[i]);
        len++;
        i++;
    }
Here:
    va_end(args);
    return (len);
}

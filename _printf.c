#include <stdio.h>
#include <stdarg.h>

/**
 * _putchar - Writes a character to the standard output
 * @c: The character to be written
 *
 * Return: On success, 1. On error, -1, and errno is set appropriately.
 */
int _putchar(char c)
{
    return write(1, &c, 1);
}

/**
 * _printf - Produces output according to a format.
 * @format: A format string containing conversion specifiers
 * @...: Additional arguments matching the conversion specifiers
 *
 * Return: The number of characters printed (excluding the null byte)
 */
int _printf(const char *format, ...)
{
    va_list args;
    va_start(args, format);

    int printed_chars = 0;

    while (*format)
    {
        if (*format != '%')
        {
            _putchar(*format);
            printed_chars++;
        }
        else
        {
            format++;
            if (*format == 'c')
            {
                int c = va_arg(args, int);
                _putchar(c);
                printed_chars++;
            }
            else if (*format == 's')
            {
                char *str = va_arg(args, char *);
                while (*str)
                {
                    _putchar(*str);
                    printed_chars++;
                    str++;
                }
            }
            else if (*format == '%')
            {
                _putchar('%');
                printed_chars++;
            }
        }
        format++;
    }

    va_end(args);
    return printed_chars;
}

int main()
{
    _printf("Hello, %s! My favorite number is %d%c\n", "World", 7, '!');
    return 0;
}

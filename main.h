#ifndef MAIN_H
#define MAIN_H
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
int printf_percentage(va_list args);
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
int _printf(const char *format, ...)
int _putchar(char c);


#endif

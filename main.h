#ifndef MAIN_H
#define MAIN_H
void print_buffer(char buffer[], int *buff_ind);
int _putchar(char c);
int _printf(const char *format, ...);
int handle_specifier(const char *format, int *i, va_list list, char buffer[]);
void _strcpy(char *dest, const char *src);
int _strlen(const char *str);


#endif

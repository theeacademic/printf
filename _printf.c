#include "main.h"

/**
 * _printf - Printf function
 * @format: format.
 * Return: Printed chars.
 */
int _printf(const char *format, ...)
{
	int i, printed_chars = 0;
	int buff_ind = 0;
	va_list list;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(list, format);

	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			buffer[buff_ind++] = format[i];
			if (buff_ind == BUFF_SIZE)
				print_buffer(buffer, &buff_ind);
			printed_chars++;
		}
		else
		{
			print_buffer(buffer, &buff_ind);
			++i;
			printed_chars += handle_specifier(format, &i, list, buffer);
		}
	}

	print_buffer(buffer, &buff_ind);
	va_end(list);

	return (printed_chars);
}

/**
 * handle_specifier - Handle conversion specifiers ('c', 's', '%')
 * @format: format string.
 * @i: pointer to the current position in the format string.
 * @list: va_list of arguments.
 * @buffer: output buffer.
 * Return: the number of characters printed for this specifier.
 */
int handle_specifier(const char *format, int *i, va_list list, char buffer[])
{
	int printed = 0;
	char spec = format[*i];

	switch (spec)
	{
		case 'c':
			char c = va_arg(list, int);

			buffer[0] = c;
			printed = 1;
			break;

		case 's':
			char *str = va_arg(list, char *);
			int len = _strlen(str);

			_strcpy(buffer, str);
			printed = len;
			break;

		case '%':
			buffer[0] = '%';
			printed = 1;
			break;
		default:
			break;
	}
	return (printed);
}

/**
 * _strlen - Calculate the length of a string.
 * @str: string pointer
 * Return: integer value
 */
int _strlen(const char *str)
{
	int len = 0;

	while (str[len] != '\0')
	{
		len++;
	}
	return (len);
}

/**
 * _strcpy - Copy a string to a buffer.
 * @dest: destination
 * @src: source
 */
void _strcpy(char *dest, const char *src)
{
	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
}

/**
 * print_buffer - Prints the contents of the buffer if it exists.
 * @buffer: something
 * @buff_ind: something else
 */
void print_buffer(char buffer[], int *buff_ind)
{
	if (*buff_ind > 0)
	{
		write(1, &buffer[0], *buff_ind);
		*buff_ind = 0;
	}
}

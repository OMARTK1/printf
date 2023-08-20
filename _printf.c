#include "main.h"
#include <unistd.h>

/**
 * write_char - writes a character to stdout
 * @c: character to write
 *
 * Return: 1 on success, -1 on failure
*/
int write_char(char c)
{
	return (write(1, &c, 1));
}

/**
 * write_str - writes a string to stdout
 * @str: string to write
 *
 * Return: number of characters written
*/
int write_str(char *str)
{
	int len = 0;

	if (str)
	{
		while (str[len])
			len += write_char(str[len]);
	}

	return (len);
}

/**
 * _printf - printf function, function generates output
 *			based on a specified format
 * @format: format string
 *
 * Return: number of characters printed
*/
int _printf(const char *format, ...)
{
	va_list args;
	int i = 0, printed_chars = 0;

	va_start(args, format);

	while (format && format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == '\0')
				break;
			if (format[i] == '%')
				printed_chars += write_char('%');
			else if (format[i] == 'c')
				printed_chars += print_char(va_arg(args, int));
			else if (format[i] == 's')
				printed_chars += print_string(va_arg(args, char *));
			else
				printed_chars += write_char('%') + write_char(format[i]);
		}
		else
			printed_chars += write_char(format[i]);
		i++;
	}

	va_end(args);
	return (printed_chars);
}

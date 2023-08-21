#include <stdarg.h>
#include <unistd.h>
#include "main.h"

/**
 * _printf - printf function
 * @format: format string
 * @...: additional arguments
 *
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list args;
	int printed_chars = 0;
	unsigned int i = 0;

	va_start(args, format);

	while (format && format[i])
	{
		if (format[i] != '%')
		{
			_putchar(format[i]);
			printed_chars++;
		}
		else
		{
			i++;

			if (format[i] == 'c')
				printed_chars += handle_char(args);
			else if (format[i] == 's')
				printed_chars += handle_string(args);
			else if (format[i] == '%')
				printed_chars += handle_percent();
			else if (format[i] == 'd' || format[i] == 'i')
				printed_chars += handle_decimal(args);
		}
		i++;
	}

	va_end(args);
	return (printed_chars);
}

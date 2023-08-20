#include "main.h"

/**
 * _printf - printf function, it produces output according to a format
 * @format: format string
 *
 * Return: The number of characters printed
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
				printed_chars += print_char('%');
			else if (format[i] == 'c')
				printed_chars += print_char(va_arg(args, int));
			else if (format[i] == 's')
				printed_chars += print_string(va_arg(args, char *));
			else
				printed_chars += print_char('%') + print_char(format[i]);
		}
		else
			printed_chars += print_char(format[i]);
		i++;
	}

	va_end(args);
	return (printed_chars);
}

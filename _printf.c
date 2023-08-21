#include <stdarg.h>
#include <unistd.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
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
	int i = 0;

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
			if (format[i] == '\0')
				break;

			int flags = get_flags(format, &i);
			int width = get_width(format, &i, args);
			int precision = get_precision(format, &i, args);
			int size = get_size(format, &i);

			int num_chars = handle_print(format + i, &i, args, buffer,
							flags, width, precision, size);

			if (num_chars < 0)
			{
				va_end(args);
				return (-1);
			}
			printed_chars += num_chars;
		}
		i++;
	}

	va_end(args);
	return (printed_chars);
}

/**
 * _putchar - writes a character to the standard output
 * @c: the character to be written
 *
 * Return: on success, 1 is returned. On error, -1 is returned,
 * and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _print_number - prints an integer using recursion
 * @n: the integer to be printed
 *
 * Return: the number of characters printed
 */
int _print_number(int n)
{
	int len = 0;

	if (n / 10 != 0)
		len += _print_number(n / 10);
	len += _putchar((n % 10) + '0');

	return (len);
}

/* Add your handler functions here */

/**
 * main - entry point of the program
 *
 * Description: test case for the _printf function
 * it prints a formatted string using _printf and demonstrates the usage of
 * various format specifiers and values
 *
 * Return: Always returns 0 to indicate successful completion
 */
int main(void)
{
	/* Test your _printf function here */
	_printf("Hello, %s! %d + %d = %i\n", "world", 2, 3, 5);
	return (0);
}

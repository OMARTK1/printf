#include "main.h"
#include <stdarg.h>
#include <unistd.h>
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

/**
 * handle_char - handles the %c conversion specifier
 * @args: va_list containing the argument
 *
 * Return: number of characters printed
 */
int handle_char(va_list args)
{
	char c = va_arg(args, int);

	_putchar(c);
	return (1); /*Return the number of characters printed*/
}

/**
 * handle_string - handles the %s conversion specifier
 * @args: va_list containing the argument
 *
 * Return: number of characters printed
 */
int handle_string(va_list args)
{
	char *str = va_arg(args, char *);
	int printed_chars = 0;

	if (str)
	{
		while (*str)
		{
			_putchar(*str);
			str++;
			printed_chars++;
		}
	}

	return (printed_chars);
}

/**
 * handle_decimal - handles the %d and %i conversion specifiers
 * @args: va_list containing the argument
 *
 * Return: number of characters printed
 */
int handle_decimal(va_list args)
{
	int num = va_arg(args, int);
	int len = 0;

	if (num < 0)
	{
		_putchar('-');
		num = -num;
		len++;
	}

	len += _print_number(num);
	return (len);
}

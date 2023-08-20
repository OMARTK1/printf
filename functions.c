#include "main.h"
#include <unistd.h>

/**
 * print_char - prints a character
 * @c: character to print
 *
 * Return: The number of characters printed
*/
int print_char(char c)
{
	return (write(1, &c, 1));
}

/**
 * print_string - prints a string
 * @str: string to print
 *
 * Return: The number of characters printed
*/
int print_string(char *str)
{
	int len = 0;

	if (str)
	{
		while (str[len])
			len += print_char(str[len]);
	}
	else
		len += print_string("(null)");

	return (len);
}

/**
 * print_percent - prints a percent character '%'
 *
 * Return: The number of characters printed (always 1)
*/
int print_percent(void)
{
	return (print_char('%'));
}

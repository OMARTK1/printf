#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * _itoa - Converts an integer to a string.
 * @num: The integer to be converted.
 * @str: Pointer to the buffer to store the converted string.
 * @base: The base for conversion (e.g., 10 for decimal).
 * 
 * Return: The length of the converted string.
 */
int itoa(int num, char *str, int base)
{
	int i = 0;
	int is_negative = 0;

	if (num == 0)
	{
		str[i++] = '0';
		str[i] = '\0';
		return 1;
	}

	if (num < 0 && base == 10)
	{
		is_negative = 1;
		num = -num;
	}

	while (num != 0)
	{
		int rem = num % base;
		str[i++] = (rem > 9) ? (rem - 10) + 'a' : rem + '0';
		num /= base;
	}

	if (is_negative)
	{
		str[i++] = '-';
	}

	str[i] = '\0';

	/* Reverse the string */
	int len = i;
	int j;
	for (int j = 0; j < len / 2; ++j)
	{
		char temp = str[j];
		str[j] = str[len - j - 1];
		str[len - j - 1] = temp;
	}

	return len;
}

/**
 * _putchar - Writes a character to the standard output (stdout).
 * @c: The character to be written.
 */
void _putchar(char c)
{
	putchar(c);
}

/**
 * _strlen - Calculates the length of a string.
 * @str: The string whose length is to be calculated.
 * 
 * Return: The length of the string.
 */
size_t _strlen(const char *str)
{
	size_t len = 0;
	while (str[len] != '\0')
	{
		++len;
	}
	return len;
}

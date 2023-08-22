#include "main.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * write_to_stdout - writes a string to stdout
 * @str: string to be written
 */
void write_to_stdout(const char *str)
{
	if (str)
		fputs(str, stdout);
}

/**
 * is_valid_specifier - checks if a specifier character is valid
 * @specifier: specifier character to validate
 *
 * Return: 1 if the specifier is valid, 0 otherwise
 */
int is_valid_specifier(char specifier)
{
	size_t i;
	const char valid_specifiers[] = {'c', 's', '%', 'd', 'i', 'b', 'u', 'o',
		'x', 'X', 'p', 'r', 'R'};
	for (i = 0; i < sizeof(valid_specifiers) / sizeof(valid_specifiers[0]); ++i)
	{
		if (specifier == valid_specifiers[i])
			return (1);
	}
	return (0);
}

/**
 * append_specific_char - appends a character to the buffer
 * @buffer: pointer to the buffer
 * @c: character to append
 * @output_len: pointer to the length of the output buffer.
 *
 * Description: appends character to the buffer, reallocating memory if needed
 */
void append_specific_char(char **buffer, char c, int *output_len)
{
	if (!*buffer)
	{
		*buffer = malloc(2);
		(*buffer)[0] = c;
		(*buffer)[1] = '\0';
		*output_len = 1;
	}
	else
	{
		size_t len = *output_len;
		*buffer = realloc(*buffer, len + 2);
		(*buffer)[len] = c;
		(*buffer)[len + 1] = '\0';
		*output_len = len + 1;
	}
}

/**
 * _handle_invalid_specifier - handles an invalid format specifier
 * @specifier: the invalid specifier character
 * @printed_chars: pointer to the count of printed characters
 *
 * Description: appends a '?' character to the buffer for an invalid specifier
 */
void _handle_invalid_specifier(char specifier __attribute__((unused)),
		int *printed_chars)
{
	append_specific_char(NULL, '?', printed_chars);
}

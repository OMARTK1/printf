#include "main.h"
#include <string.h>

/**
 * write_to_stdout - Writes a string to the standard output (stdout).
 * @str: The string to be written.
 */
void write_to_stdout(const char *str)
{
	if (str != NULL)
	{
		fputs(str, stdout);
	}
}

/**
 * is_valid_specifier - Checks if a specifier character is valid.
 * @specifier: The specifier character to validate.
 * 
 * Return: 1 if the specifier is valid, 0 otherwise.
 */
int is_valid_specifier(char specifier)
{
	int i;
	/* List of valid specifier characters */
	const char valid_specifiers[] = {'c', 's', '%', 'd', 'i', 'b', 'u', 'o', 'x', 'X', 'p', 'r', 'R'};

	/* Check if the specifier character is in the valid_specifiers array */
	for (i = 0; i < (int)(sizeof(valid_specifiers) / sizeof(valid_specifiers[0])); ++i) /* cast to signed type */

	{
		if (specifier == valid_specifiers[i])
		{
			return 1; /* Specifier is valid */
		}
	}

	return 0; /* Specifier is not valid */
}

/**
 * append_specific_char - Appends a specific character to the buffer.
 * @buffer: Pointer to the buffer.
 * @c: Character to append.
 * 
 * Description: Appends a character to the buffer, reallocating memory if needed.
 */
void append_specific_char(char **buffer, char c)
{
	if (*buffer == NULL)
	{
		*buffer = (char *)malloc(2 * sizeof(char));
		(*buffer)[0] = c;
		(*buffer)[1] = '\0';
	}
	else
	{
		size_t current_length = strlen(*buffer);
		*buffer = (char *)realloc(*buffer, (current_length + 2) * sizeof(char));
		(*buffer)[current_length] = c;
		(*buffer)[current_length + 1] = '\0';
	}
}

/**
 * _handle_invalid_specifier - Handles an invalid format specifier.
 * @specifier: The invalid specifier character.
 * @printed_chars: Pointer to the count of printed characters.
 */
void _handle_invalid_specifier(char specifier __attribute__((unused)), int *printed_chars)
{
	/* Handle invalid specifier, e.g., print a '?' character */
	_putchar('?');
	++(*printed_chars);
}

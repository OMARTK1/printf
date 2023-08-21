#include "main.h"

/**
 * append_specific_char - append a specific character to the buffer
 * @buffer: pointer to the buffer
 * @c: character to append
 *
 * Description: appends a character to the buffer,
 *		reallocating memory if needed.
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
 * append_string - append a string to the buffer
 * @buffer: pointer to the buffer
 * @str: string to append
 *
 * Description: appends a string to the buffer, reallocating memory if needed.
 */
void append_string(char **buffer, const char *str)
{
	if (str == NULL)
	{
		return;
	}

	if (*buffer == NULL)
	{
		*buffer = strdup(str);
	}
	else
	{
		size_t current_length = strlen(*buffer);
		size_t str_length = strlen(str);

		*buffer = (char *)realloc(*buffer,
				(current_length + str_length + 1) * sizeof(char));
		strcat(*buffer, str);
	}
}

/**
 * write_to_stdout - write a string to stdout
 * @str: string to write
 *
 * Description: writes a string to the standard output (stdout).
 */
void write_to_stdout(const char *str)
{
	if (str != NULL)
	{
		fputs(str, stdout);
	}
}
/**
 * is_valid_specifier - Check if a specifier is valid
 * @specifier: Specifier character to validate
 *
 * Description: Validates if a given specifier character is valid.
 *
 * Return: 1 if the specifier is valid, otherwise 0.
 */
int is_valid_specifier(char specifier)
{
	/* Return 1 if valid, 0 otherwise */
	return (specifier == 'c' || specifier == 's' || specifier == 'd' ||
			specifier == 'i' || specifier == 'b' || specifier == 'S' ||
			specifier == 'u' || specifier == 'o' || specifier == 'x' ||
			specifier == 'X' || specifier == 'p' || specifier == 'r' ||
			specifier == 'R' || specifier == '%');
}

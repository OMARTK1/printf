#include "main.h"
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

void append_string(char **buffer, const char *str, int *output_len);

/**
 * _printf - Custom printf implementation that supports basic format specifiers
 * @format: The format string containing specifiers.
 * @...: Variable arguments based on the specifiers.
 * Return: The number of characters printed
 * (excluding the null byte used to end output to strings).
 */
int _printf(const char *format, ...)
{
	int printed_chars = 0;
	va_list args;

	va_start(args, format);


	_process_format(format, &printed_chars, args);

	va_end(args);
	return (printed_chars);
}

/**
 * _process_format - Processes the format string & handles specifiers
 * @format: The format string to be processed.
 * @printed_chars: Pointer to the count of printed characters.
 * @args: Variable arguments based on the format specifiers.
 */
void _process_format(const char *format, int *printed_chars, va_list args)
{
	const char *ptr;
	char *output_buffer = NULL;
	int output_len = 0;

	for (ptr = format; *ptr != '\0'; ++ptr)
	{
		if (*ptr == '%')
		{
			++ptr; /* Move past '%' */

			if (*ptr == '\0')
				break;

			if (*ptr == '%')
			{
				append_specific_char(&output_buffer, '%');
				++output_len;
			}
			else
			{
				char *specifier_output = process_format_specifier(&ptr,
						args, printed_chars);

				if (specifier_output != NULL)
				{
					append_string(&output_buffer, specifier_output, &output_len);
					free(specifier_output);
				}
			}
		}
		else
		{
			append_specific_char(&output_buffer, *ptr);
			++output_len;
		}
	}

	if (output_len > 0)
	{
		write_to_stdout(output_buffer);
	}

	if (output_buffer != NULL)
	{
		free(output_buffer);
	}
}

/**
 * process_format_specifier - Processes a format specifier &
 * updates the output buffer.
 * @ptr: Pointer to the current position in the format string.
 * @args: Variable arguments corresponding to the format specifier.
 * @printed_chars: Pointer to the count of printed characters.
 * Return: char
 * Description: This function processes a valid format specifier
 * and updates the output buffer with the formatted output.
 * It handles different specifier cases ('c', 's', 'd', 'i').
 * After processing the specifier, the function increments
 * the pointer to the format string,
 * updates the printed character count,
 * and modifies the output buffer accordingly.
 */
char *process_format_specifier(const char **ptr,
		va_list args, int *printed_chars)
{
	char specifier = *(*ptr + 1);
	++(*ptr);

	if (is_valid_specifier(specifier))
	{
		char *specifier_output = process_specifier(specifier, args);
		++(*printed_chars);
		return (specifier_output);
	}
	else
	{
		_handle_invalid_specifier(specifier, printed_chars);
		return (NULL);
	}
}

/**
 * process_specifier - Handles the processing of valid format specifiers.
 * @specifier: The format specifier character.
 * @args: Variable arguments corresponding to the format specifier.
 * Return: Dynamically allocated string containing the formatted output.
 *         The caller is responsible for freeing the memory.
 */
char *process_specifier(char specifier, va_list args)
{
	switch (specifier)
	{
		case 'c':
			{
				char *formatted_output = (char *)malloc(2 * sizeof(char));

				formatted_output[0] = va_arg(args, int);
				formatted_output[1] = '\0';
				return (formatted_output);
			}
		case 's':
			{
				char *input_str = va_arg(args, char *);

				if (input_str == NULL)
				{
					return (strdup("(null)"));
				}
				return (strdup(input_str));
			}
		case 'd':
		case 'i':
			{
				int num = va_arg(args, int);
				char num_str[12];  /* Enough for INT_MAX */

				snprintf(num_str, sizeof(num_str), "%d", num);
				return (strdup(num_str));
			}
		default:
			return (NULL); /* Invalid specifier */
	}
}

/**
 * append_string - Appends a string to the buffer &
 * updates output length.
 * @buffer: Pointer to the buffer.
 * @str: String to append.
 * @output_len: Pointer to the length of the output buffer.
 * Description: Appends the input string to the buffer,
 * reallocating memory if needed.
 */
void append_string(char **buffer, const char *str, int *output_len)
{
	if (*buffer == NULL)
	{
		*buffer = (char *)malloc((strlen(str) + 1) * sizeof(char));
		strcpy(*buffer, str);
		*output_len = strlen(str);
	}
	else
	{
		int str_len = strlen(str);

		*buffer = (char *)realloc(*buffer,
				(*output_len + str_len + 1) * sizeof(char));
		strcpy(*buffer + *output_len, str);
		*output_len += str_len;
	}
}


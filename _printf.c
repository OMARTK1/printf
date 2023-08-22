#include "main.h"
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * append_string - appends a string to the buffer and updates output length
 * @buffer: pointer to the buffer
 * @str: string to append
 * @output_len: pointer to the length of the output buffer
 *
 * Description: appends the input string to the buffer,
 *              reallocating memory if needed
 * _printf - Custom printf implementation that supports basic format specifiers
 * @format: The format string containing specifiers.
 * @...: Variable arguments based on the specifiers.
 * Return: The number of characters printed
 * (excluding the null byte used to end output to strings).
 */
void append_string(char **buffer, const char *str, int *output_len)
{
	if (*buffer == NULL)
	{
		*buffer = malloc((strlen(str) + 1) * sizeof(char));
		strcpy(*buffer, str);
		*output_len = strlen(str);
	}
	else
	{
		int str_len = strlen(str);
	int printed_chars = 0;
	va_list args;

	va_start(args, format);

		*buffer = realloc(*buffer, (*output_len + str_len + 1) * sizeof(char));
		strcpy(*buffer + *output_len, str);
		*output_len += str_len;
	}
}

/**
 * append_specific_char - appends a specific character to the buffer
 *                          and updates output length
 * @buffer: pointer to the buffer
 * @c: character to append
 * @output_len: Pointer to the length of the output buffer
 *
 * Description: appends the input character to the buffer,
 *              reallocating memory if needed
 */
void append_specific_char(char **buffer, char c, int *output_len)
{
	char str[2];

	str[0] = c;
	str[1] = '\0';
	append_string(buffer, str, output_len);
}

/**
 * _printf - printf function that produces output according to a format
 * @format: string containing the format specifiers
 *
 * Return: the number of characters printed (excluding the null byte)
	va_end(args);
	return (printed_chars);
 * _process_format - Processes the format string & handles specifiers
 * @format: The format string to be processed.
 * @printed_chars: Pointer to the count of printed characters.
 * @args: Variable arguments based on the format specifiers.
 */
int _printf(const char *format, ...)
{
	va_list args;
	int printed_chars = 0;
	char *formatted_output;

	if (format == NULL)
		return (-1);
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == '\0')
				return (-1);
			formatted_output = process_specifier(*format, args);
			if (formatted_output == NULL)
				return (-1);
			printed_chars += write(1, formatted_output,
					strlen(formatted_output));
			free(formatted_output);
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
			write(1, format, 1);
			printed_chars++;
		}
		format++;
	}
	va_end(args);
	return (printed_chars); /* Return the number of printed characters */
}



/**
 * process_specifier - handles the processing of valid format specifiers
 * @specifier: the format specifier character
 * @args: variable arguments corresponding to the format specifier
 *
 * Return: dynamically allocated string containing
 * the formatted output. the caller is responsible for freeing the memory
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
	char *formatted_output;
	char *s; /* For strings */
	int n; /* For integers */
	char num_str[12]; /* For integer strings */

	switch (specifier)
	{
		case 'c':
			s = malloc(2);
			s[0] = va_arg(args, int);
			s[1] = '\0';
			return (s);
		case 's':
			s = va_arg(args, char *);
			return (s ? strdup(s) : strdup("(null)"));
		case 'd':
		case 'i':
			n = va_arg(args, int);
			snprintf(num_str, 12, "%d", n);
			return (strdup(num_str));
		case '%':
			s = malloc(2);
			s[0] = '%';
			s[1] = '\0';
			return (s);
		case 'b':
			n = va_arg(args, unsigned int);
			return (convert_to_base(n, 2));
		case 'r':
			s = va_arg(args, char *);
			return (s ? reverse_string(s) : strdup("(null)"));
		case 'R':
			s = va_arg(args, char *);
			return (s ? rot13(s) : strdup("(null)"));
			break;
		case 'u':
			n = va_arg(args, unsigned int);
			return (convert_to_base(n, 10));
		case 'o':
			n = va_arg(args, unsigned int);
			return (convert_to_base(n, 8));
		case 'x':
			n = va_arg(args, unsigned int);
			return (convert_to_base(n, 16));
		case 'X':
			n = va_arg(args, unsigned int);
			s = convert_to_base(n, 16);
			return (upper_case(s));
		default:
			return (NULL);
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


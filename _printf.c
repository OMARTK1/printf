#include "main.h"
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void append_specific_char(char **buffer, char c, int *output_len);
char *process_specifier(char specifier, va_list args);
/**
 * _printf - printf function that produces output according to a format
 * @format: string containing the format specifiers
 *
 * Return: the number of characters printed (excluding the null byte)
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
			printed_chars += write(1, formatted_output, strlen(formatted_output));
			free(formatted_output);
		}
		else
		{
			write(1, format, 1);
			printed_chars++;
		}
		format++;
	}
	va_end(args);
	return (printed_chars);
}
/**
 * append_string - appends a string to the buffer & updates output length
 * @buffer: pointer to the buffer
 * @str: string to append
 * @output_len: pointer to the length of the output buffer
 * Description: appends the input string to the buffer,
 *              reallocating memory if needed
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

		*buffer = realloc(*buffer, (*output_len + str_len + 1) * sizeof(char));
		strcpy(*buffer + *output_len, str);
		*output_len += str_len;
	}
}
/**
 * process_specifier - handles the processing of valid format specifiers
 * @specifier: the format specifier character
 * @args: variable arguments corresponding to the format specifier
 *
 * Return: dynamically allocated string containing
 * the formatted output. the caller is responsible for freeing the memory
 */
char *process_specifier(char specifier, va_list args)
{
	char *s;
	int n;
	char num_str[12];

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
	}
}


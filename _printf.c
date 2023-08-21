#include "main.h"

/**
 * _print_percent - print a single '%' character
 */
static void _print_percent(void)
{
	write_to_stdout("%"); /* Write '%' to stdout */
}

/**
 * _handle_invalid_specifier - handle invalid specifier
 * @specifier: the invalid specifier character
 * @printed_chars: pointer to the count of printed characters
 */
static void _handle_invalid_specifier(char specifier, int *printed_chars)
{
	write_to_stdout("%"); /* Write '%' to stdout */
	write_to_stdout(&specifier); /* Write the invalid specifier to stdout */
	*printed_chars += 2;
}

/**
 * _process_format - process the format string
 * @format: format string containing specifiers
 * @printed_chars: pointer to the count of printed characters
 */
static void _process_format(const char *format, int *printed_chars)
{
	for (const char *ptr = format; *ptr != '\0'; ++ptr)
	{
		if (*ptr == '%')
		{
			if (*(ptr + 1) == '%')
			{
				_print_percent();
				++ptr;
				++(*printed_chars);
			}
			else
			{
				char specifier = *(ptr + 1);
				++ptr;

				if (is_valid_specifier(specifier))
				{
					/* Handle each specifier case (removed for brevity) */
				}
				else
				{
					_handle_invalid_specifier(specifier, printed_chars);
				}
			}
		}
		else
		{
			write_to_stdout(ptr);
			++(*printed_chars);
		}
	}
}

/**
 * _printf - printf function with limited specifiers
 * @format: format string containing specifiers
 * @...: variable arguments based on the specifiers
 *
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list args;

	va_start(args, format);
	int printed_chars = 0;
	char *output_buffer = NULL;

	_process_format(format, &printed_chars);

	/* Write any remaining content in the output buffer */
	if (output_buffer != NULL)
	{
		write_to_stdout(output_buffer);
		free(output_buffer);
	}

	va_end(args);
	return (printed_chars);
}

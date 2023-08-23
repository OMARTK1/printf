#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * format_non_printable_string - formats a string with non-printable characters
 * @str: input of a string
 *
 * Description: formats the input string by replacing non-printable characters
 * with their hexadecimal representation in the format "\xHH".
 *
 * Return: a dynamically allocated formatted string, or NULL on failure.
 * The caller is responsible for freeing the allocated memory.
 */
char *format_non_printable_string(const char *str)
{
	char *formatted_output = NULL;
	int output_len = 0;
	int str_len = strlen(str);

	for (int i = 0; i < str_len; i++)
	{
		if (!is_printable(str[i]))
		{
			char hex[6];

			snprintf(hex, sizeof(hex), "\\x%02X", (unsigned char)str[i]);
			append_string(&formatted_output, hex, &output_len);
		}
		else
		{
			append_specific_char(&formatted_output, str[i], &output_len);
		}
	}

	return (formatted_output);
}

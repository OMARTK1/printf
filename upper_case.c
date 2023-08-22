#include "main.h"
#include <string.h>
#include <stdlib.h>

/**
 * upper_case - converts a given string to uppercase
 * @str: input string to be converted to uppercase
 *
 * Return: a newly allocated string
 *          containing the uppercase version of the input string.
 *         The caller is responsible for freeing the allocated memory
 */
char *upper_case(const char *str)
{
	size_t length;
	size_t i;
	char *upper;

	if (str == NULL)
		return (NULL);

	length = strlen(str);
	upper = (char *)malloc((length + 1) * sizeof(char));

	if (upper == NULL)
		return (NULL);

	for (i = 0; i < length; ++i)
	{
		char c = str[i];

		if (c >= 'a' && c <= 'z')
		{
			upper[i] = c - 'a' + 'A';
		}
		else
		{
			upper[i] = c;
		}
	}
	upper[length] = '\0';

	return (upper);
}


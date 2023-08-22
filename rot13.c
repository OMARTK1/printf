#include "main.h"
#include <string.h>
#include <stdlib.h>

/**
 * rot13 - applies the ROT13 cipher to a given string
 * @str: input string to be encoded using ROT13
 *
 * Return: a newly allocated string containing the ROT13 encoded input string.
 *         the caller is responsible for freeing the allocated memory
 */
char *rot13(const char *str)
{
	size_t length;
	size_t i;
	char *result;

	if (str == NULL)
		return (NULL);

	length = strlen(str);
	result = (char *)malloc((length + 1) * sizeof(char));

	if (result == NULL)
		return (NULL);

	for (i = 0; i < length; ++i)
	{
		char c = str[i];

		if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		{
			if ((c >= 'A' && c <= 'M') || (c >= 'a' && c <= 'm'))
				result[i] = c + 13;
			else
				result[i] = c - 13;
		}
		else
		{
			result[i] = c;
		}
	}
	result[length] = '\0';

	return (result);
}

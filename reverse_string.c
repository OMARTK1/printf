#include "main.h"
#include <string.h>
#include <stdlib.h>

/**
 * reverse_string - reverses a given string
 * @str: input string to be reversed
 *
 * Return: a newly allocated string containing the reversed input string.
 *         the caller is responsible for freeing the allocated memory
 */
char *reverse_string(const char *str)
{
	size_t length;
	size_t i;
	char *reversed;

	if (str == NULL)
		return (NULL);

	length = strlen(str);
	reversed = (char *)malloc((length + 1) * sizeof(char));

	if (reversed == NULL)
		return (NULL);

	for (i = 0; i < length; ++i)
	{
		reversed[i] = str[length - i - 1];
	}
	reversed[length] = '\0';

	return (reversed);
}

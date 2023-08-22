#include <stdio.h>
#include <stdlib.h>

/**
 * convert_to_base - Converts a number to a string in the given base.
 * @num: The number to be converted.
 * @base: The base for conversion (e.g., 2, 8, 10, 16).
 * Return: Dynamically allocated string containing the converted number.
 *         The caller is responsible for freeing the memory.
 */
char *convert_to_base(unsigned int num, int base)
{
	unsigned int temp;
	int max_len;
	char *result;
	int index;

	if (base < 2 || base > 16)
		return (NULL);

	temp = num;
	max_len = 1;
	while (temp >= (unsigned int)base)
	{
		temp /= base;
		max_len++;
	}

	result = (char *)malloc((max_len + 1) * sizeof(char));
	if (!result)
		return (NULL);

	index = max_len - 1;
	result[max_len] = '\0';
	while (num >= (unsigned int)base)
	{
		int remainder = num % base;

		result[index] = (remainder < 10) ? (char)('0' + remainder) :
			(char)('A' + remainder - 10);

		num /= base;
		index--;
	}
	result[index] = (num < 10) ? (char)('0' + num) : (char)('A' + num - 10);

	return (result);
}

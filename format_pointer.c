#include "main.h"

/**
 * *format_pointer - function that formats a pointer to a string
 * @ptr: pointer to be formatted
 * Return: string
 */

char *format_pointer(void *ptr)
{
	char *formatted_output = NULL;
	char ptr_str[20];

	snprintf(ptr_str, sizeof(ptr_str), "%p", ptr);
	append_string(&formatted_output, ptr_str);

	return (formatted_output);
}

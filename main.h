#ifndef _PRINTF_H
#define _PRINTF_H

/* Macros */

#define BUFFER_SIZE 1024

/* Header files */

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <unistd.h>

int _printf(const char *format, ...);
void _process_format(const char *format, int *printed_chars, va_list args);
char *process_specifier(char specifier, va_list args);
void append_specific_char(char **buffer, char c, int *output_len);
void _handle_invalid_specifier(char specifier, int *printed_chars);
void write_to_stdout(const char *str);
int is_valid_specifier(char specifier);

/* Helper function prototypes */
int my_itoa(int num, char *str, int base);
size_t _strlen(const char *str);
int _putchar(char c);

#endif

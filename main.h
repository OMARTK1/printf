#ifndef _PRINTF_H
#define _PRINTF_H

#define BUFFER_SIZE 1024

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>

/* Function prototypes */
int _printf(const char *format, ...);
void write_to_stdout(const char *str);
int is_valid_specifier(char specifier);
void append_string(char **buffer, const char *str, int *output_len);
void _process_format(const char *format, int *printed_chars, va_list args);
char *process_specifier(char specifier, va_list args);
void append_specific_char(char **buffer, char c);
void _handle_invalid_specifier(char specifier, int *printed_chars);
char *process_format_specifier(const char **ptr, va_list args, int *printed_chars);

#endif

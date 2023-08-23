#ifndef _PRINTF_H
#define _PRINTF_H

/* Macros */
#define UNUSED(x) (void)(x)
#define BUFFER_SIZE 1024

/* Header files */

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stddef.h>
#include <limits.h>

/* FLAGS */
#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16

/* SIZES */
#define S_LONG 2
#define S_SHORT 1

/* Printing handler */
void _print_handler(const char *format, va_list args, int *len);
char *_convert_pointer_address(void *ptr);

/* Function prototypes */
int _printf(const char *format, ...);
void _process_format(const char *format, int *printed_chars, va_list args);
char *process_specifier(char specifier, va_list args);
void append_specific_char(char **buffer, char c, int *output_len);
void _handle_invalid_specifier(char specifier, int *printed_chars);
void write_to_stdout(const char *str);
void append_string(char **buffer, const char);
int is_valid_specifier(char specifier);

/* Helper function prototypes */
int my_itoa(int num, char *str, int base);
size_t _strlen(const char *str);
int _putchar(char c);

/* Prototype for the convert_to_base function */
char *convert_to_base(unsigned int num, int base);
char *reverse_string(const char *str);
char *rot13(const char *str);
char *upper_case(const char *str);

#endif

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

#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024

/* FLAGS */
#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16

/* SIZES */
#define S_LONG 1
#define S_SHORT 2

/* Printing funcions */
int _printf(const char *format, ...);
int _putchar(char c);
int _print_number(int n);

/* Handler functions */
int handle_char(va_list args);
int handle_string(va_list args);
int handle_percent(void);
int handle_decimal(va_list args);
/**
 * struct fmt - struct op
 *
 * @fmt: the format
 * @fn: the function associated
 */
struct fmt
{
	char fmt;
	int (*fn)(va_list, char[], int, int, int, int);
};
/**
 * typedef struct fmt fmt_t - Struct op
 *
 * @fmt: the format
 * @fm_t: the function associated
 */
typedef struct fmt fmt_t;

int _printf(const char *format, ...);
int handle_print(const char *fmt, int *i,
		va_list list, char buffer[], int flags, int width, int precision, int size);

/* FUNCTIONS */

/*Funtions to print chars and strings*/
int print_char(va_list types, char buffer[],
		int flags, int width, int precision, int size);
int print_string(va_list types, char buffer[],
		int flags, int width, int precision, int size);
int print_percent(va_list types, char buffer[],
		int flags, int width, int precision, int size);

/*Functions to print numbers*/
int print_int(va_list types, char buffer[],
		int flags, int width, int precision, int size);
int print_binary(va_list types, char buffer[],
		int flags, int width, int precision, int size);
int print_unsigned(va_list types, char buffer[],
		int flags, int width, int precision, int size);
int print_octal(va_list types, char buffer[],
		int flags, int width, int precision, int size);
int print_decimal(va_list types, char buffer[],
		int flags, int width, int precision, int size);
int print_hexadecimal(va_list types, char buffer[],
		int flags, int width, int precision, int size);
int print_hexa_upper(va_list types, char buffer[],
		int flags, int width, int precision, int size);

int print_hexa(va_list types, char map_to[],
		char buffer[], int flags, char flag_ch, int width, int precision, int size);

/*Function to print non printable characters*/
int print_non_printable(va_list types, char buffer[],
		int flags, int width, int precision, int size);

/*Funcion to print memory address*/
int print_pointer(va_list types, char buffer[],
		int flags, int width, int precision, int size);

/*Funciotns to handle other specifiers*/
int get_flags(const char *format, int *i);
int get_width(const char *format, int *i, va_list list);
int get_precision(const char *format, int *i, va_list list);
int get_size(const char *format, int *i);

/*Function to print string in reverse*/
int print_reverse(va_list types, char buffer[],
		int flags, int width, int precision, int size);

/*Function to print a string in rot 13*/
int print_rot13string(va_list types, char buffer[],
		int flags, int width, int precision, int size);

/* width handler */
int handle_write_char(char c, char buffer[],
		int flags, int width, int precision, int size);
int write_number(int is_positive, int ind, char buffer[],
		int flags, int width, int precision, int size);
int write_num(int ind, char bff[], int flags, int width, int precision,
		int length, char padd, char extra_c);
int write_pointer(char buffer[], int ind, int length,
		int width, int flags, char padd, char extra_c, int padd_start);

int write_unsgnd(int is_negative, int ind,
		char buffer[],
		int flags, int width, int precision, int size);

/* UTILS */
int is_printable(char);
int append_hexa_code(char, char[], int);
int is_digit(char);

/**
 * is_valid_specifier - check if a specifier character is valid
 * @specifier: specifier character to be checked
 * Return: 1 if the specifier is valid, 0 otherwise
 */
int is_valid_specifier(char specifier);

/**
 * write_to_stdout - write a string to the standard output (stdout)
 * @str: the string to be written
 */
void write_to_stdout(const char *str);

/**
 * append_string - append a string to a buffer
 * @buffer: pointer to the buffer where the string will be appended
 * @str: string to be appended
 * @output_len: the output to be print
 */
void append_string(char **buffer, const char *str, int *output_len)

/**
 * append_specific_char - Append a specific character to a buffer
 * @buffer: Pointer to the buffer
 * @c: Character to append
*/
void append_specific_char(char **buffer, char c);

/* Function prototypes */
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
void _handle_invalid_specifier(char specifier, int *printed_chars);
char *process_format_specifier(const char **ptr,
		va_list args, int *printed_chars);

/* Function prototypes */
int _printf(const char *format, ...);

#endif

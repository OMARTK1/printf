#ifndef _PRINTF_H
#define _PRINTF_H

#include <stdarg.h>
#include <unistd.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stddef.h>

/*Printing funcions*/
int _printf(const char *format, ...);
int _putchar(char c);
int _print_number(int n);

/*Handler functions*/
int handle_char(va_list args);
int handle_string(va_list args);
int handle_percent(void);
int handle_decimal(va_list args);

#endif

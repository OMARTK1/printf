#ifndef _PRINTF_H
#define _PRINTF_H

#include <stdarg.h>
#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

int _printf(const char *format, ...);
int print_char(char c);
int print_string(char *str);
int print_percent(void);

#endif /*_PRINTF_H */

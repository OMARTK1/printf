#ifndef _PRINTF_H
#define _PRINTF_H

#include <stdarg.h>
#include <unistd.h>

int _printf(const char *format, ...);
int print_char(char c);
int print_string(char *str);
int print_percent(void);
int write_char(char c);
int write_str(char *str);

#endif

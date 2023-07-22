#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * struct pf- a struct for conversion specifier and print functions
 * @conv: the conversion specifier
 * @func: the function associated
 */
typedef struct pf
{
	char *conv;
	int (*func)(va_list);
} t_pf;
int _printf(const char *format, ...);
int parser(const char *format, int len, t_pf *p_functions, va_list arg);
int _putchar(char c);
/* printing_fun */
int print_c(va_list arg);
int print_int(va_list arg);
int print_percent(va_list arg);
int print_int(va_list arg);
int print_string(va_list arg);

#endif

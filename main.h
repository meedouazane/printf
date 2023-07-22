#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdlib.h>

int _putchar(char c);
int _printf(const char *format, ...);
int parser(char *format, int len, t_pf *p_functions, va_list arg);



/**
 *  struct pf - a structur for conversion specifier and pinter functions
 *
 * @conv: The conversion specifier
 * @func: The function associated
 *
 */

typedef struct pf
{
	char *conv;
	int (*func)(va_list);
} t_pf;

#endif

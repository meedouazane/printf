#include "main.h"
/**
 * print_string - Print a string.
 *@arg: list of arguments.
 * return: Number of chars printed.
 */
int print_string(va_list arg)
{
	char *str = va_arg(arg, char *);
	int result, chars = 0;

	if (str != NULL) 
	{
		while (*str) 
		{
		result = _putchar(*str);
		if (result == -1) 
		return -1;
		chars++;
		str++;
		}
	}
	return (chars);
}
/**
 * print_c - Print a char.
 *@arg: list of arguments.
 * return: Number of chars printed.
 */
int print_c(va_list arg)
{
	char c = va_arg(arg, int);
	return (_putchar(c));
}
/**
 * print_percent - Print a percent.
 *@arg: list of arguments.
 * return: Number of chars printed.
 */
int print_percent(va_list arg)
{
	return (_putchar('%'));
}

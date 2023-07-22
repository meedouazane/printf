#include "main.h"
/**
 * print_string - Print a string.
 *@arg: list of arguments.
 * return: Number of chars printed.
 */
int print_string(va_list arg)
 {
	char *s = va_arg(args, char*);
	int len = 0;

	if (s == NULL)
	s = "(null)";
	while (*s != '\0')
	{
	write(1, s, 1);
	s++;
	len++;
	}
	return (len);
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
/**
 * print_percent - Print a percent.
 *@arg: list of arguments.
 * return: Number of chars printed.
 */
int print_int(va_list arg)
{

}

#include "main.h"

/**
 * print_string - Print a string.
 *@arg: list of arguments.
 * Return: Number of chars printed
 */

int print_string(va_list arg)
{
	char *s = va_arg(arg, char*);
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
 * Return: Number of chars printed.
 */

int print_c(va_list arg)
{
	char c = va_arg(arg, int);

	return (_putchar(c));
}

/**
 * print_percent - Print a percent.
 *@arg: list of arguments.
 * Return: Number of chars printed.
 */

int print_percent(__attribute__((unused))va_list arg)
{
	return (_putchar('%'));
}

/**
 * print_int - Print integer
 *@arg: list of arguments
 *
 * Return: numbers of bytes
 */

int print_int(va_list arg)
{
	int len = 0, n, number, divisior = 1;

	n = va_arg(arg, int);

	if (n < 0)
		len += _putchar('-');

	while (n / divisior >= 10)
	{
		divisior *= 10;
	}


	while (divisior != 0)
	{
		number = n / divisior;
		len += _putchar('0' + number);
		n = n % divisior;
		divisior = divisior / 10;
	}

	return (len);
}

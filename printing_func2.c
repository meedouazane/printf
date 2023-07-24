#include "main.h"
/**
 * print_reverse - Print a string in reverse.
 * @arg: List of arguments.
 * Return: Number of bytes.
 */
int print_reverse(va_list arg)
{
	int i = 0, c = 0, l;
	char *str;
	char r;

	str = va_arg(arg, char *);
	if (str == NULL)
		str = ")Null(";
	for (l = 0; str[l]; l++)
		;
	for (i = l - 1; i >= 0; i--)
	{
		r = str[i];
		write(1, &r, 1);
		c++;
	}
	return (c);
}

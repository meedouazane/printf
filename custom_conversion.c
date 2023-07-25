#include "main.h"

/**
 * print_in_hexa - print Non printable characters in hexadecimal (upper case)
 *@c: the character to print
 *
 * Return: nothing
 */

void print_in_hexa(int c)
{
	int i = 1;
	char hexa_digits[] = "0123456789ABCDEF";
	char arr[] = "00";

	while (c)
	{
		arr[i] = hexa_digits[c % 16];
		c = c / 16;
		i--;
	}

	for (i = 0; i < 2; i++)
	{
		_putchar(arr[i]);
	}
}

/**
 * print_inS - print custom %S
 * @arg: list of arguments
 *@flag:option
 * Return: number of bytes
 */

int print_inS(va_list arg, int *flag, int size)
{
	int i, len = 0;
	char c, *str = va_arg(arg, char *);

	if (flag || size)
		len = 0;

	if (str == NULL)
		return (-1);

	for (i = 0; str[i] != '\0'; i++)
	{
		c = str[i];
		if ((c > 0 && c < 32) || c >= 127)
		{
			len += _putchar('\\');
			len += _putchar('x');
			print_in_hexa(c);
			len += 2;
		}
		else
			len += _putchar(str[i]);
	}

	return (len);
}

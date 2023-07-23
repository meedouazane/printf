#include "main.h"
/**
 * print_binary - converte to binary an unsigned int.
 * @arg : list of argumenet.
 * Return: Number of bytes.
 */
int print_binary(va_list arg)
{
	unsigned int i, num = 0, sum = 0;
	unsigned int array[32];
	unsigned int mask = 2147483648; /* 2^31 = 2147483648 */
	int c;
	char b;

	num = va_arg(arg, unsigned int);
	array[0] = num / mask;
	for (i = 1; i < 32; i++)
	{
		mask = mask / 2;
		array[i] = (num / mask) % 2;
	}
	for (i = 0, sum = 0, c = 0; i < 32; i++)
	{
		sum = sum + array[i];
		if (sum || i == 31)
		{
			b = '0' + array[i];
			write(1, &b, 1);
			c++;
		}
	}
	return (c);
}
/**
 * print_octal - convert to octal.
 * @arg: List of arguments.
 * Return: Number of bytes.
 */
int print_octal(va_list arg)
{
	unsigned int num = va_arg(arg, unsigned int);
	unsigned int a[32];
	int j, i = 0, c = 0;
	char z;

	while (num != 0)
	{
		a[i] = num % 8;
		num /= 8;
		i++;
	}

	if (i == 0)
	{
		a[i] = 0;
		i++;
	}

	for (j = i - 1; j >= 0; j--)
	{
		z = '0' + a[j];
		write(1, &z, 1);
		c++;
	}
	return (c);
}

#include "main.h"
#include <stdio.h>

/**
 * print_binary - converte to binary an unsigned int.
 * @arg : list of argumenet.
 *@flag: option
 *@size: size of flags array
 * Return: Number of bytes.
 */
int print_binary(va_list arg, int *flag, int size)
{
	unsigned int i, num = 0, sum = 0;
	unsigned int array[32];
	unsigned int mask = 2147483648; /* 2^31 = 2147483648 */
	int c;
	char b;

	num = va_arg(arg, unsigned int);
	if (flag || size)
		c = 0;

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
 *@flag: option
 *@size: size of flags array
 * Return: Number of bytes.
 */
int print_octal(va_list arg, int *flag, int size)
{
	unsigned int num = va_arg(arg, unsigned int);
	unsigned int a[32];
	int j, i = 0, index, c;
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
	for (index = 0; index < size; index++)
	{
		if (flag[index] == 3)
		{
			if ((i == 1 && a[0] != 0) || i != 1)
				c += _putchar('0');
		}

	}
	for (j = i - 1; j >= 0; j--)
	{
		z = '0' + a[j];
		write(1, &z, 1);
		c++;
	}
	return (c);
}

/**
 * print_hex_x - convert to hexadecimal.
 * @arg: List of arguments.
 *@flag: option
 *@size: size of flags array
 * Return: Number of bytes.
 */

int print_hex_x(va_list arg, int *flag, int size)
{
	int i = 7, j, index, start, len = 0;
	char arr[8] = {'0', '0', '0', '0', '0', '0', '0', '0'};
	char hex_digits[] = "0123456789abcdef";
	unsigned int num = va_arg(arg, unsigned int);

	for (index = 0; index < size; index++)
	{
		if (flag[index] == 3)
		{
			len += _putchar('0');
			len += _putchar('x');
		}

	}


	if (num == 0)
	{
		write(1, "0", 1);
		return (1);
	}

	while (num != 0)
	{
		arr[i] = hex_digits[num % 16];
		num /= 16;
		i--;
	}

	start = i + 1;
	for (j = start; j <= 7; j++)
	{
		write(1, &arr[j], 1);
		len++;
	}

	return (len);
}


/**
 * print_hex_X - convert to hexadecimal.
 * @arg: List of arguments.
 *@flag: option
 *@size: size of flags array
 * Return: Number of bytes.
 */

int print_hex_X(va_list arg, int *flag, int size)
{
	int i = 7, j, start, index, len = 0;
	char arr[8] = {'0', '0', '0', '0', '0', '0', '0', '0'};
	char hex_digits[] = "0123456789ABCDEF";
	unsigned int num = va_arg(arg, unsigned int);

	for (index = 0; index < size; index++)
	{
		if (flag[index] == 3)
		{
			len += _putchar('0');
			len += _putchar('X');
		}

	}
	if (num == 0)
	{
		write(1, "0", 1);
		return (1);
	}

	while (num != 0)
	{
		arr[i] = hex_digits[num % 16];
		num /= 16;
		i--;
	}

	start = i + 1;
	for (j = start; j <= 7; j++)
	{
		write(1, &arr[j], 1);
		len++;
	}

	return (len);
}
/**
 * print_pointer- Printing a pointer.
 * @arg : List of arguments.
 *@flag: option
 *@size: size of flags array
 * Return: Number of bytes.
 */
int print_pointer(va_list arg, int *flag, int size)
{
	void *ptr = va_arg(arg, void *);
	unsigned long int num = (unsigned long int)ptr, t;
	char hex_d[] = "0123456789abcdef";
	int i, c, num_digits = 0, skip = 1, buffer_i = 0;
	char digit, buffer[LOCAL_BUFFER];

	if (flag || size)
		c = 0;
	buffer[buffer_i++] = '0';
	buffer[buffer_i++] = 'x';
	c += 2;
	t = num;
	if (num == 0)
		num_digits = 1;
	else
	{
		while (t != 0)
		{
			num_digits++;
			t >>= 4;
		}
	}
	for (i = (num_digits - 1) * 4; i >= 0; i -= 4)
	{
		digit = hex_d[(num >> i) & 0xF];
		if (digit != '0')
			skip = 0;
		if (!skip)
		{
			buffer[buffer_i++] = digit;
			c++;
		}
	}
	if (skip)
	{
		buffer[buffer_i++] = '0';
		c++;
	}
	write(1, buffer, buffer_i);
	return (c);
}

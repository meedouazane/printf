#include "main.h"

/**
 * int_flags - Print integer
 *@p_n: number retrived
 *@p_num: holding the positive number
 *@len: number of bytes printed
 *@flag: array of flags
 *@size: of the array flgs
 * Return: numbers of bytes
 */

int int_flags(int *p_n, unsigned int *p_num, int len, int *flag, int size)
{
	int i;

	for (i = 0; i < size; i++)
	{
		if (*(p_n) < 0 && (flag[i] == 1 || flag[i] == 2))
		{
			len += _putchar('-');
			*p_num = -(*p_n);
		}

		if (*(p_n) >= 0 && (flag[i] == 2 && flag[i + 1] == 1))
		{
			len += _putchar('+');
			i++;
		}
		else if (*(p_n) >= 0 && flag[i] == 2)
		{
			len += _putchar(' ');
		}
		else if (*(p_n) >= 0 && flag[i] == 1)
		{
			len += _putchar('+');
		}
	}
	return (len);
}

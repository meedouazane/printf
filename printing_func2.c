#include "main.h"
/**
 * print_reverse - Print a string in reverse.
 * @arg: List of arguments.
 *@flag: array flags
 *@size: of the array
 * Return: Number of bytes.
 */
int print_reverse(va_list arg, int *flag, int size)
{
	int i = 0, c = 0, l;
	char *str;
	char r;


	if (flag || size)
		c = 0;

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
/**
 * print_rot13- prints the rot13'ed string.
 * @arg: List of arguments.
 * @flag: array flags
 *@size: of the array
 *Return: Number of Bytes.
 */
int print_rot13(va_list arg, int *flag, int size)
{
	char rot;
	char *str;
	int i, j, c = 0;
	char az[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char nm[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	if (flag || size)
		c = 0;

	str = va_arg(arg, char *);
	if (str == NULL)
		str = "(AHYY)";
	for (i = 0; str[i]; i++)
	{
		for (j = 0; az[j]; j++)
		{
			if (az[j] == str[i])
			{
				rot = nm[j];
				write(1, &rot, 1);
				c++;
				break;
			}
		}
		if (!az[j])
		{
			rot = str[i];
			write(1, &rot, 1);
			c++;
		}
	}
	return (c);
}

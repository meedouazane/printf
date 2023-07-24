#include "main.h"
#include <stdio.h>


int check_flag(char c);
/**
 * parser - use format string and va_list to iterate over them
 *	and print the corrsponding character to stdout using _putchar
 *@format: the formating string
 *@len: the numbers of bytes of the charcters printed
 *@p_functions: array of structures that has two members:
 * conversion specifier(conv) , and a pointer function(func)
 *@arg: list of arguments
 * Return: On success, the number of bytes written is returned
 *	On error, -1 is returned
 */

int parser(const char *format, int len, t_pf *p_functions, va_list arg)
{
	int i = 0, j, flag;

	/*if (!format[i]) */
		/*return (len);*/
	for ( ; format[i] != '\0'; i++)    /* Iterates through the main string */
	{
		if (format[i] == '%')
		{
			flag = check_flag(format[i + 1]);
				i = (flag) ? i + 1 : i;
			/*Iterates through struct to find the right printing function*/
			for (j = 0; p_functions[j].conv != NULL; j++)
			{
				if (format[i + 1] == p_functions[j].conv[0])
				{
					len += p_functions[j].func(arg, flag);
					i++;
					break;
				}
			}
			if (p_functions[j].conv == NULL && format[i + 1] != '\0')
			{
				len += _putchar('%');
				len += _putchar(format[i + 1]);
				i++;
			}
			if (p_functions[j].conv == NULL && format[i + 1] == '\0')
				return (-1);
		}
		else
			len += _putchar(format[i]);
	}
	return (len);
}

/**
 * check_flag - check if the format string has a flag option
 *@c: the character that this function checks if's a flag
 *
 * Return: a number indicates the option found
 */

int check_flag(char c)
{
	int num_op = 0, i;
	t_fg arr[] = {
		{"+", 1},
		{NULL, 0}
	};

	for (i = 0; arr[i].op != NULL; i++)
	{
		if (c == arr[i].op[0])
			num_op = arr[i].x;
	}

	/*printf("flag is %d\n", num_op);*/
	return (num_op);
}

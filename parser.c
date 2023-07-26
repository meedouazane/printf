#include "main.h"

int *check_flag(const char *c, int index, int *size);
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
	int i = 0, j, *flag = NULL, size = 0;

	/*if (!format[i]) */
		/*return (len);*/
	for ( ; format[i] != '\0'; i++)    /* Iterates through the main string */
	{
		if (format[i] == '%')
		{
			flag = check_flag(format, i + 1, &size);
			i += size;
			/*Iterates through struct to find the right printing function*/
			for (j = 0; p_functions[j].conv != NULL; j++)
			{
				if (format[i + 1] == p_functions[j].conv[0])
				{
					len += p_functions[j].func(arg, flag, size);
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
			{
				if (flag != NULL)
				{
					free(flag);
					flag = NULL;
				}
				return (-1);
			}
			if (flag != NULL)
			{
				free(flag);
				flag = NULL;
			}

			/*VALGRIND_DO_LEAK_CHECK;*/
		}
		else
			len += _putchar(format[i]);
	}

	return (len);
}

/**
 * check_flag - check if the format string has a flag option
 *@c: the character that this function checks if's a flag
 *@index: starting searching from
 *@size: size of array flags
 * Return: numbers array indicates the options found
 */

int *check_flag(const char *c, int index, int *size)
{
	int num_op = 0, *ar_fg = NULL, i = index, j, k = 0;
	t_fg arr[] = {
		{"+", 1},
		{" ", 2},
		{"#", 3},
		{NULL, 0}
	};
	ar_fg = malloc(sizeof(int) * 10);
	*size = 0; /* Reset size to 0 */

	for (j = 0; j < 10; j++)  /* Reset ar_fg */
		ar_fg[j] = 0;

	for ( ; c[i] != '\0'; i++)
	{
		for (j = 0; arr[j].op != NULL; j++)
		{
			if (c[i] == arr[j].op[0])
			{
				num_op = arr[j].x;
				ar_fg[k++] = num_op;
				(*size)++;
				break;
			}
		}
		if (arr[j].op == NULL)
			break;

	}

	return (ar_fg);
}

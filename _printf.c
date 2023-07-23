#include "main.h"

/**
 * _printf - print formatted string
 *@format: a character pointer to a list of arguments
 *
 * Return: On success, the number of bytes printed is returned
 *	On error,  -1 is returned
 */

int _printf(const char *format, ...)
{
	t_pf p_functions[] = {
		{"c", print_c},
		{"s", print_string},
		{"%", print_percent},
		{"i", print_int},
		{"d", print_int},
		{"b", print_binary},
		{"o", print_octal},
		{"u", print_unsgined_number},
		{"x", print_hex_x},
		{"X", print_hex_X},
		{"S", print_inS},
		{"p", print_pointer},
		{NULL, NULL}
	};
	int len = 0;
	va_list arg;

	if (format == NULL)
		return (-1);

	va_start(arg, format);

	len = parser(format, len, p_functions, arg);

	va_end(arg);

	return (len);

}

#include <unistd.h>

/**
 * _putchar - printing character c to stdout
 *@c: the character to be printed
 *
 * Return: On success, the number of bytes written is returned.
 *	On error, -1 is returned.
 *	errno is set to indicate the error
 */

int _putchar(char c)
{

	return (write(1, &c, 1));
}

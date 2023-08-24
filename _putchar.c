#include <unistd.h>

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _print - uses helper function _putchar to print string
 * @c: string to be printed
 *
 * Return: void
 */
void _print(char *c)
{
	int i = 0;

	while (c[i])
	{
		_putchar(c[i]);
		i++;
	}
}

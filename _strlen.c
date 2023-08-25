#include "main.h"

/**
 * _strlen - returns string length
 * @s: pointer to string
 *
 * Return: returns an integer.
 */

int _strlen(char *s)
{
	int i = 0;

	while (s[i])
		i++;

	return (i);
}

#include "main.h"

/**
 * _strcat - concatenates 2 strings
 * @dest: pointer to string value
 * @src: pointer to a string value, will be added to dest.
 *
 * Return: char *
 */
char *_strcat(char *dest, char *src)
{
	int index = 0, dest_len = 0;

	while (dest[index++])
		dest_len++;

	for (index = 0; src[index]; index++)
		dest[dest_len++] = src[index];

	return (dest);
}

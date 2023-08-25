#include "main.h"
/**
 * _trim - removes whitespace anywhere in string
 * @s: string to be trimmed
 *
 * Example:
 *	int main(void)
 *	{
 *		char *ss = "     hello";
 *		printf("%s\n", ss);
 *		char *trimmed = _trim(ss);
 *		printf("%s\n", trimmed);
 *
 *		free(trimmed);
 *		return (0);
 *	}
 * N.T: free returned char *
 *
 * Return: char *. needs to be freed
*/

char *_trim(char *s)
{
	int i, n;
	char *str;

	i = 0, n = 0;
	while (s[i])
	{
		if (s[i] != ' ')
			n++;
		i++;
	}

	str = malloc(sizeof(char) * n + 1);
	i = 0;
	n = 0;

	while (s[i])
	{
		if (s[i] != ' ')
		{
			str[n] = s[i];
			n++;
		}
		i++;
	}

	return (str);
}

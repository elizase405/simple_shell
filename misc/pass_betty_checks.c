#include <stdio.h>
#include <unistd.h>

/**
 * main - Function to accept argument from user
 * and print it back
 * @argc: no of passed arguments
 * @argv: array of strings containing passed arguments
 *
 * Return: int
 */

int main(int argc, char **argv)
{
	int n, i, j;
	char nl;

	nl = '\n';
	i = 0;
	n = 0;

	(void) argc;

	while (argv[i])
	{
		for (j = 0; argv[i][j]; j++)
			n++;
		write(1, argv[i], n);
		write(1, &nl, 1);
		i++;
	}
	return (0);
}

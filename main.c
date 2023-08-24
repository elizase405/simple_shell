#include "main.h"

/**
 * main - Entry point
 * @argc: total number of arguments passed by user
 * @argv: array of strings of arguments passed by user
 *
 * Return: 0 if successful. -1 if failed
 */

int main(int argc, char **argv)
{
	if (argc == 1)
		shell_prompt(argv, environ);
	return (0);
}

#include "main.h"

/**
 * main - Entry point
 * @argc: total number of arguments passed by user
 * @argv: array of strings of arguments passed by user
 * @env: array of strings of process enviroment variables
 *
 * Return: 0 if successful. -1 if failed
 */

int main(int argc, char **argv)
{
	int val;

	if (argc == 1)
		val = shell_prompt(argv, environ);
	return (val);
}

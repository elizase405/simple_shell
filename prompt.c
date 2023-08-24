#include "main.h"

/**
 * shell_prompt - Start of a unix command line interpreter
 * @argv: array of strings of arguments passed by user
 * @env: array of strings of process enviroment variables
 *
 * Functions used:
 * 	- _print: located in _putchar.c
 * Return: 1 if successful. -1 if failed
 */

void shell_prompt()
{
	char *buf;
	char **_argv;
	int exec;

	while (exec)
	{
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "$ ", 2);
		buf = use_getline();
		_argv = use_strtok(buf);
		exec = use_execve(_argv);

		free(buf);
		free(_argv);
	}
}

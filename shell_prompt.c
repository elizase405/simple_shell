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

int shell_prompt(char **argv, char **env)
{
	while (1)
	{
		char *buf;
		char *_argv[] = {NULL, NULL};
		int i = 0, j;
		pid_t cid;
		size_t n = 0;
		(void) argv;

		buf = NULL;

		if (isatty(STDIN_FILENO) == 1)
			write(STDOUT_FILENO, "$ ", 2);

		if (getline(&buf, &n, stdin) == -1)
		{
			free(buf);
			return (0);
		}
	
		_argv[0] = _trim(buf);

		for (i = 0; _argv[i]; i++)
		{
			for (j = 0; _argv[i][j]; j++)
				;
		}

		_argv[i - 1][j - 1] = '\0';
		cid = fork();

		if (cid == -1)
		{
			free(buf), free(_argv[0]);
			perror("cid failed");
			return (-1);
		}

		if (cid == 0)
		{
			if (execve(_argv[0], _argv, env) == -1)
			{
				free(buf), free(_argv[0]);
				return (-1);
			}
		}
		else
		{
			wait(NULL);
			free(buf), free(_argv[0]);
		}
	}
	return (0);
}

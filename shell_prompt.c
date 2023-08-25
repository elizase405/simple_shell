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
		char *buf, *full_cmd;
		char **_argv;
		pid_t cid;
		size_t n = 0;

		buf = NULL;

		write(STDIN_FILENO, "$ ", 2);

		if (getline(&buf, &n, stdin) == -1)
		{
			free(buf);
			return (0);
		}
	
		_argv = use_strtok(buf);

		cid = fork();

		if (cid == -1)
		{
			free(buf);
			perror("cid failed");
			return (-1);
		}

		if (cid == 0)
		{
			full_cmd = use_path(_argv[0]);
			if (execve(full_cmd, _argv, env) == -1)
			{
				_print(argv[0]);
				_print(": 1: ");
				_print(_argv[0]);
				_print(": not found\n");
				free(buf), free(_argv), free(full_cmd);
				return (-1);
			}
		}
		else
		{
			wait(NULL);
			free(buf), free(_argv);
		}
	}
	return (0);
}

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
 * main - Start of a unix command line interpreter
 * @argc: no of arguments passed by user
 * @argv: array of strings of arguments passed by user
 * @env: array of strings of process enviroment variables
 *
 * Return: 0 if successful. -1 if failed
 */

int main(int argc, char **argv, char **env)
{
	while (1)
	{
		char *buf;
		char **_argv;
		char *token;
		char *delim = " ";
		int i = 0, j;
		pid_t cid;
		size_t n = 0;

		buf = NULL;

		write(STDIN_FILENO, "$ ", 2);

		if (getline(&buf, &n, stdin) == -1)
		{
			free(buf);
			perror("getline failed");
			return (-1);
		}
		token = strtok(buf, delim);
		_argv = malloc(sizeof(char *) * n);

		while (token)
		{
			_argv[i] = token;
			token = strtok(NULL, delim);
			i++;
		}

		argv[i] = NULL;

		for (i = 0; _argv[i]; i++)
		{
			for (j = 0; _argv[i][j]; j++)
				;
		}

		_argv[i - 1][j - 1] = '\0';
		cid = fork();

		if (cid == -1)
		{
			perror("cid failed");
			return (-1);
		}

		if (cid == 0)
		{
			if (execve(_argv[0], _argv, NULL) == -1)
			{
				perror("execve failed");
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

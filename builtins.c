#include "main.h"

char *all_builtins[] = {
        "exit",
        "cd",
        "env",
        "help"
};

int exit_builtin(char **_argv)
{
	(void) _argv;
	exit(0);
	return (0);
}

int env_builtin(char **_argv)
{
	int i = 0;
	(void) _argv;

	while (environ[i])
	{
		_print(environ[i]);
		_putchar('\n');
		i++;
	}

	return (1);
}

int cd_builtin(char **_argv)
{
	if (_argv[1] == NULL)
		write(STDERR_FILENO, "directory not stated\n", 21);
	else
	{
		if (chdir(_argv[1]) == -1)
			write(STDERR_FILENO, "failed", 6);
	}
	return (1);
}

int total_builtins()
{
	return (sizeof(all_builtins) / sizeof(char *));
}

int help_builtin(char **_argv)
{
	int i = 0;
	(void) _argv;
	_print("Welcome to shell help\n");
	_print("Enter your command.\n");

	while (i < total_builtins())
	{
		_print(all_builtins[i]);
		_putchar('\n');
		i++;
	}

	_print("man for more information.\n");

	return (1);
}

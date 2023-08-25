#include "main.h"

char *use_path(char *cmd)
{
	int cmd_len, token_len;
	char *path, *path_copy, *token, *full_path;

	path = getenv("PATH");

	if (path)
	{
		path_copy = strdup(path);
		cmd_len = _strlen(cmd);
		token = strtok(path_copy, ":");

		while (token)
		{
			token_len = _strlen(token);
			full_path = malloc(token_len + cmd_len + 2);

			strcpy(full_path, token);
			_strcat(full_path, "/");
			_strcat(full_path, cmd);
			_strcat(full_path, "\0");

			if (stat(full_path, &buffer) == 0)
			{
				free(path_copy);
				return (full_path);
			}
			else
			{
				free(full_path);
				token = strtok(NULL, ":");
			}
		}

		free(path_copy);

		if (stat(cmd, &buffer) == 0)
			return (cmd);
		return (NULL);
	}
	return (NULL);
}

#include "main.h"

int use_cid(char **_argv)
{
	pid_t cid;

	cid = fork();
	if (cid == 0)
	{
		if (execve(_argv[0], _argv, environ) == -1)
			return (0);
	}
	else
		wait(NULL);
	return (1);
}

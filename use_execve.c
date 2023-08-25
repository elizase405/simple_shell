#include "main.h"

int use_execve(char **_argv)
{
	if (_argv[0] == NULL)
		return (1);

	return use_cid(_argv);
}

#include "main.h"

char *use_getline(void)
{
	char *buf;
	size_t n = 0;

	if (getline(&buf, &n, stdin) == -1)
	{
		if (feof(stdin))
			exit(EXIT_SUCCESS);
		else
			exit(EXIT_FAILURE);
	}

	return buf;
}

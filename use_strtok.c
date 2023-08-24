#include "main.h"

char **use_strtok(char *buf)
{
	int i = 0;
	char **toks = malloc(STRTOK_BUFSIZE * sizeof(char *));
	char *tok;

	if (!toks)
		exit(EXIT_FAILURE);

	tok = strtok(buf, STRTOK_DELIM);
	while (tok)
	{
		toks[i] = tok;
		tok = strtok(NULL, STRTOK_DELIM);
		i++;
	}

	toks[i] = NULL;

	return (toks);
}

#include <stdio.h>
#include <stdlib.h>

char *_getenv(const char *name);

int main()
{
	char *result = _getenv("PATH");
	char *res = getenv("PATH");

	if (result != NULL)
		printf("Found: %s\n", result);
	else
		printf("Not Found: %s\n", result);
	if (res != NULL)
                printf("Found: %s\n", res);
        else
                printf("Not Found: %s\n", res);
	return (0);
}

char *_getenv(const char *name)
{
	extern char **environ;
	int i = 0, n = 0, j, num;
	char *arr;

	/*
	 * loop through the whole enviroment
	 * and get the total number of characters(num)
	 * that match 'name'.
	 * We use that total to allocate space
	 * for 'arr' that will eventually
	 * store this chars.
	 */
	while (environ[i])
	{
		for (j = 0; name[j]; j++)
		{
			if (environ[i][j] == name[j])
			{
				printf("environ:%c, name:%c\n", environ[i][j], name[j]);
				num++;
			}
		}
		i++;
	}

	arr = malloc(sizeof(char) * num);

	/*
	 * loop through the whole enviroment
	 * and find the char that matches a name char
	 * store it in 'arr'
	 */
	i = 0;
	while (environ[i])
	{
		for (j = 0; name[j]; j++)
		{
			if (environ[i][j] == name[j])
			{
				arr[n] = environ[i][j];
				n++;
			}
		}
		i++;
	}
	printf("%s %s\n", arr, name);

	for (i = 0; arr[i]; i++)
	{
		if (arr[i] = name[i])
			printf("Arr:%c, name:%c, num:%d\n", arr[i], name[i], num);
	}
	free(arr);

	return (environ[i]);

}

#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

extern char **environ;

int shell_prompt(char **argv, char **env);
char *_strcat(char *dest, char *src);
int _strlen(char *);
int _putchar(char c);
void _print(char *c);
char *_trim(char *s);

#endif

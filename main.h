#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

#define STRTOK_BUFSIZE 64
#define STRTOK_DELIM " \t\r\n\a"

struct stat buffer;

int shell_prompt(char **argv, char **env);
char **use_strtok(char *buf);
char *use_path(char *cmd);
char *_strcat(char *dest, char *src);
int _strlen(char *);
int _putchar(char c);
void _print(char *c);

#endif

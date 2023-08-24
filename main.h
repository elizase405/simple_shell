#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

#define STRTOK_BUFSIZE 64
#define STRTOK_DELIM " \t\r\n\a"
extern char **environ;

void shell_prompt();
char **use_strtok(char *buf);
char *use_getline(void);
int use_execve(char **_argv);
int use_cid(char **_argv);
char *_strcat(char *dest, char *src);
int _strlen(char *);
int _putchar(char c);
void _print(char *c);
char *_trim(char *s);

#endif

#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stddef.h>

void _env(char **env);
int _putchar(char c);
int _strcmp(char *s1, char *s2);
char *_getenv(const char *name);
extern char **environ;
int _strlen(char *s);
void _puts(char *str);
char *str_concat(char *s1, char *s2);
char *_strdup(char *str);

#endif

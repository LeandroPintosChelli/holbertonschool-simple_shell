#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stddef.h>

/**
 * built - Structure for built-in functions.
 * @name: Name of function.
 * @f: Pointer to function.
 */

typedef struct built
{
	char *name;
	void (*f)(char **);
} built_t;

void (*check_builtin(char *))(char **);
void _env(char **env);
void _salir(char **env);
int _putchar(char c);
int _strcmp(char *s1, char *s2);
char *_getenv(const char *name);
extern char **environ;
int _strlen(char *s);
char *str_concat(char *s1, char *s2);
char *_strdup(char *str);
char *_which(char *);
char *_strchr(char *, int);


#endif

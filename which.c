#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
/**
* _which - search a path
* @str: pointer to char
* Return: int
*/
char *_which(char *str)
{
	char *path = NULL, *pathdup = NULL, *token = NULL, *fullpath = NULL;
	struct stat st;

	path = _getenv("PATH");
	pathdup = _strdup(path);
	token = strtok(pathdup, ":");
	free(path);
	while (token)
	{
		fullpath = str_concat(token, "/");
		path = str_concat(fullpath, str);
		if (stat(path, &st) == 0)
		{
			free(pathdup);
			free(fullpath);
			return (path);
		}
		else
		{
			token = strtok(NULL, ":");
			free(fullpath);
			free(path);
		}
	}
	free(pathdup);
	return (NULL);
}
/**
* pathver - main
* @str: string
* Return: 0
*/
int pathver(char *str)
{
	if (_strchr(str, '/') == NULL)
		return (-1);
	else
		return (0);
}
/**
* _strchr - locates a character in a string
* @s: char pointer
* @c: char
* Return: char
*/
char *_strchr(char *s, char c)
{
	int loc;

	for (loc = 0; s[loc]; loc++)
	{
		if (s[loc] == c)
		{
			return (&s[loc]);
		}
	}
	if (c == '\0' && s[loc] == '\0')
	{
		return (&s[loc]);
	}
	return ('\0');
}

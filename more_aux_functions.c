#include "main.h"
/**
* _which - search a path
* @str: pointer to char
* Return: int
*/
char *_which(char *str)
{
	char *path = NULL, *pathdup = NULL, *token, *fullpath;
	struct stat st;
	
	path = _getenv("PATH");
	pathdup = _strdup(path);
	token = strtok(pathdup, ":");
	while (token)
	{
		fullpath = _str_concat(token, "/");
		path = _str_concat(fullpath, str);
		if (stat(path, &st) == 0)
		{
			printf("%s\n", path);
			return (path);
		}
		token = strtok(NULL, ":");
	}
	return (NULL);
}

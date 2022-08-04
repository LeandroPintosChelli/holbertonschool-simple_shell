#include "main.h"

/**
* _which - Searches for path to file input.
* @str: String input.
*
* Return: Pointer to full path for file or NULL if not found.
*/

char *_which(char *str)
{
	char *path = NULL, *pathdup = NULL, *token = NULL, *fullpath = NULL;
	struct stat st;

	if (strchr(str, '/') != NULL)
	{
		if (stat(str, &st) == 0)
			return (str);
		else
			return (NULL);
	}

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

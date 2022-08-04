#include "main.h"

/**
* _which - Searches for path to file input.
* @str: String input.
* @res: Pointer to char pointer to store result.
*
* Return: 1 if memory was allocated and 0 otherwise.
*/

int _which(char *str, char **res)
{
	char *path = NULL, *pathdup = NULL, *token = NULL, *fullpath = NULL;
	struct stat st;

	if (strchr(str, '/') != NULL)
	{
		if (stat(str, &st) == 0)
		{
			*res = str;
			return (0);
		}
		else
		{
			*res = NULL;
			return (0);
		}
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
			*res = path;
			return (1);
		}
		else
		{
			token = strtok(NULL, ":");
			free(fullpath);
			free(path);
		}
	}
	free(pathdup);
	*res = NULL;
	return (0);
}

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

/**
* _getenv - function to do getenv
* @name: pointer
* Return: NULL
*/
char *_getenv(const char *name)
{
	char *path;
	int i, j;
	int status;

	for (i = 0; environ[i] != NULL; i++)
	{
	status = 1;
	for (j = 0; environ[i][j] != '='; j++)
	{
		if (name[j] != environ[i][j])
		{
			status = 0;
			break;
		}
	}
	if (status)
	{
		path = _strdup(&environ[i][j + 1]);
		return (path);
	}
	}
	return (NULL);
}

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

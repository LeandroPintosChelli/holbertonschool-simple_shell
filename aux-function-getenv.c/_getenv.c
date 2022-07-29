#include "main.h"

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
* _strdup - check code
* @str: duplicate string
* Return: Always 0
*/
char *_strdup(char *str)
{
	int s, i;
	char *c;

	if (str == NULL)
	{
		return (NULL);
	}
	s = strlen(str);
	c = (char *)malloc(s * sizeof(char) + 1);

	if (c == NULL)
	{
		return (NULL);
	}
	else
	{
	for (i = 0; i < s; i++)
		c[i] = str[i];
	}
	return (c);
}

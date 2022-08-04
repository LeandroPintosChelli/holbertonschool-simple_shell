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

/**
* _env - print environment
* @env: pointer to a char
* Return: void
*/
void _env(__attribute__((unused)) char **env, __attribute__((unused)) char *freeme)
{
	/*size_t len;

	for (; *env;)
	{
		len = strlen(*env);
		write(1, *env, len);
		_putchar('\n');
		*env = *env + len;
	}*/
	printf("envioo\n");
}

/**
 * _exit - Exit built-in function.
 * @env: Enviroment variables.
 */

void _salir(__attribute__((unused)) char **env, char *freeme)
{
	free(freeme);
	exit(0);
}

/**
 * _strchr - Searches char in string.
 * @str: Pointer to string of chars.
 * @c: Char to search.
 *
 * Return: Pointer to first occurance of c in str or NULL if not found.
 */

char *_strchr(char *str, int c)
{
	while (str && *str)
	{
		if (*str == c)
			return (str);
		str++;
	}
	return (NULL);
}

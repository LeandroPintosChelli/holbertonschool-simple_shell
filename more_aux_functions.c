#include "main.h"

/**
* _getenv - function to do getenv
* @name: pointer
*
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
* p_error - Print error to stderr.
* @cmd: Command name.
* @program: Executable name.
* @status: Pointer to integer.
*/

void p_error(char *cmd, char *program, int *status)
{
	write(2, program, _strlen(program));
	write(2, ": 1: ", 5);
	write(2, cmd, _strlen(cmd));
	write(2, ": not found\n", 12);
	*status = 127;
}

/**
 * _salir - Exit built-in function.
 * @freeme: Buf to free before exit.
 * @status: Exit code.
 */

void _salir(char *freeme, int status)
{
	free(freeme);
	if (status == 0)
		exit(status);
	else
		exit(status);
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

/**
 * _env - Prints enviroment variables.
 * @buf: Buffer not used.
 * @stat: Status code not used.
 */

void _env(__attribute__((unused)) char *buf, __attribute__((unused)) int stat)
{
	int i;

	for (i = 0; environ && environ[i]; i++)
	{
		write(1, environ[i], _strlen(environ[i]));
		write(1, "\n", 1);
	}
}

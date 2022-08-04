#include "main.h"

/**
 * check_builtin - Checks for builtin function.
 * @str: String input.
 * 
 * Return: Pointer to built-in function or NULL if not found.
 */

void (*check_builtin(char *str))(char *, int)
{
	built_t arr[] = {
		{"exit", _salir},
		{"env", _env}
	};
	int i;

	if (!str)
		return (NULL);
	for (i = 0; i < 2; i++)
	{
		if (_strcmp(str, arr[i].name) == 0)
			return (arr[i].f);
	}
	return (NULL);
}

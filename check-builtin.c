#include "main.h"

/**
 * check_builtin - Checks for builtin function.
 * @str: String input.
 * 
 * Return: Pointer to built-in function or NULL if not found.
 */

void (*check_builtin(char *str))(char **, char *)
{
	built_t arr[] = {
		{"exit", _salir}	
	};
	int i;

	if (!str)
		return (NULL);
	for (i = 0; i < 1; i++)
	{
		if (_strcmp(str, arr[i].name) == 0)
			return (arr[i].f);
	}
	return (NULL);
}

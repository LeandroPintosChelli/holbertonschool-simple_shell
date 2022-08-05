#include "main.h"

/**
 * fill_buff - Fills array of strings with tokens.
 * @buf: Pointer to arr of strings.
 * @tok: First token.
 */

void fill_buff(char **buf, char *tok)
{
	int i;

	for (i = 0; i < 1024 && tok != NULL; i++)
	{
		buf[i] = tok;
		tok = strtok(NULL, " \t\n\r");
	}
	buf[i] = NULL;
}

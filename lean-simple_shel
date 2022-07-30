#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <stdlib.h>
int _strlen(char *s);
/**
* main - Simple shell
*
* Return: null
*/
int main(void)
{
	int child;
	char *command[16], *tok, *lineptr = NULL;
	size_t i, n = 0;
	int status;

	while (1)
	{
	if (getline(&lineptr, &n, stdin) == -1)
		break;
		free(lineptr);
	tok = strtok(lineptr, " \t\n\r");
	for (i = 0; i < 16 && tok != NULL; i++)
	{
		command[i] = tok;
		tok = strtok(NULL, " \t\n\r");
	}
	command[i] = NULL;
	child = fork();
	if (child == 0)
	{
		if ((command[0][0] != ' ') && (command[0][_strlen(command[0])] != ' ') && execve(command[0], command, NULL) == -1)
		{
			perror("Error");
			free(lineptr);
			free(tok);
			return (1);
		}
	}
	else
		wait(&status);
	}
	free(lineptr);
	free(tok);
	return (0);
}

/**
 * _strlen - string lenght
 * @s: function that returns the length of a string.
 * Return: Always 0.
 */
int _strlen(char *s)
{
	int i = 0;

	while (*s != '\0')
	{
		i++;
		s++;
	}
	return (i);
}

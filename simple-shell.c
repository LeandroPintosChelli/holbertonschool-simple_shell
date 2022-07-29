#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <stdlib.h>
/**
* main - Simple shell
*
* Return: null
*/
void main(void)
{
	int child;
	char *command[16], *tok, *lineptr = NULL;
	size_t i, n;
	int status;

	while (1)
	{
	write(1, "$ ", 2);
	if (getline(&lineptr, &n, stdin) == -1)
	break;
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
		if (execve(command[0], command, NULL) == -1)
		{
			perror("Error");
			free(tok);
			free(lineptr);
			exit(0);
		}
	}
		if (child > 0)
		wait(&status);
	}
	write(1, "\n", 1);
	free(lineptr);
	exit(status);
}

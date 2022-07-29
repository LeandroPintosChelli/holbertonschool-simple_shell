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
int main(void)
{
	int child = 0;
	char *command[16], *tok, *lineptr = NULL;
	size_t i, n;
	int status;
  
	while (1)
	{
	printf("$ ");
	if (getline(&lineptr, &n, stdin) == -1)
	break;
	tok = strtok(lineptr, " \t\n\r");
	for (i = 0; i < 16 && tok != NULL; i++)
	{
		command[i] = tok;
		tok = strtok(NULL, " \t\n\r");
	}
	command[i] = NULL;
	if (fork() == 0)
	{
		if (execve(command[0], command, NULL) == -1)
		{
			perror("execve");
			free(tok);
			free(lineptr);
			exit(0);
		}
	}
		if (child > 0)
		wait(&status);
	}
	printf("\n");
	free(lineptr);
	exit(status);
}

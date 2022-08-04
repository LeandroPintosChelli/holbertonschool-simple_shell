#include "main.h"
/**
* main - simple shell
* @ac: unused
* @av: void
* @env: unused
* Return: 0
*/
int main(__attribute__((unused)) int ac, char **av, char **env)
{
	char *input = NULL, *buf[1024], *tok;
	size_t e = 0, i = 0, n = 0;
	int status = 0;
	int child;

	(void) av;
	while (1)
	{
		if (isatty(STDIN_FILENO) == 1)
			write(1, "$ ", 2);
		if (getline(&input, &n, stdin) == -1)
			break;
		tok = strtok(input, " \t\n\r");
		if (tok && _strcmp(tok, "exit") == 0)
		{
			free(input);
			return (i);
		}
		for (i = 0; i < 1024 && tok != NULL; i++)
		{
			buf[i] = tok;
			tok = strtok(NULL, " \t\n\r");
		}
		buf[i] = NULL;
		if (buf[0] == NULL)
		{
			free(input);
			continue;
		}
		if (_strcmp(input, "env") == 0)
		{
			for (e = 0; env[e] != NULL; e++)
			{
				printf("%s\n", env[e]);
			}
			continue;
		}
		if (pathver(buf[0]) == -1)
		{
			buf[0] = _which(buf[0]);
		}
		if (buf[0] && stat())
		{
			child = fork();
			if (child == 0)
			{
				if (execve(buf[0], buf, env) == -1)
					perror("");
			}
			else
				wait(&status);
		}
		if (buf[0] != input)
			free(buf[0]);
	}
	free(input);
	return (0);
}

#include "main.h"
/**
* main - simple shell
* @ac: unused
* @env: unused
* Return: 0
*/
int main(__attribute__((unused)) int ac, char **env)
{
	char **av(void);
	char *input = NULL, *buf[1024], *tok;
	size_t i, n = 0;
	int status = 0;
	int child;
	struct stat file;

	while (1)
	{
		if (getline(&input, &n, stdin) == -1)
			break;
		tok = strtok(input, " \t\n\r");
		for (i = 0; i < 1024 && tok != NULL; i++)
		{
			buf[i] = tok;
			tok = strtok(NULL, " \t\n\r");
		}
		buf[i] = NULL;
		if (!buf[0])
		{
			free(buf[0]);
			free(input);
			return (0);
		}
		child = fork();
		if (child == 0)
		{
			if (execve(buf[0], buf, env) == -1)
			{
				perror("");
				return (0);
			}
		}
		else
			wait(&status);
	}
	free(input);
	return (0);
}

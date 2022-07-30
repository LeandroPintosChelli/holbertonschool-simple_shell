#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(__attribute__((unused)) int ac, char **av, char **env)
{
	char *input = 0;
	size_t n = 0;
	int status;
	struct stat file;

	while (1)
	{
		printf("#blas$ ");
		if (getline(&input, &n, stdin) == -1)
		{
			free(input);
			break;
		}
		if (strcmp(input, "\n") == 0)
			continue;
		input = strtok(input, "\n");
		if (input && stat(input, &file) == 0)
		{
			if (fork() == 0)
				execve(input, av, env);
		}
		else
		{
			printf("%s: No such file or directory\n", av[0]);
			continue;
		}
		wait(&status);
	}

	return (0);
}

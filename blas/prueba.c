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
	ssize_t res;
	int status;
	struct stat file;

	while (1)
	{
		printf("#cisfun$ ");
		if (input)
		{
			free(input);
			n = 0;
		}
		res = getline(&input, &n, stdin);
		printf("getline: %ld\n", res);
		if (res == -1)
		{
			free(input);
			break;
		}
		printf("%s\n", input);
	}

	return (0);
}

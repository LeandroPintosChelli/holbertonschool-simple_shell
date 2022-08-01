#include "main.h"

/**
* main - simple shell
* @ac: unused
* @av: unused
* @env: unused
* Return: 0
*/
int main(__attribute__((unused)) int ac, char **av, char **env)
{
	char *input = 0;
	size_t n = 0;
	int status;
	struct stat file;

	while (1)
	{
		if (getline(&input, &n, stdin) == -1)
		{
			free(input);
			break;
		}
		if (_strcmp(input, "\n") == 0)
			continue;
		input = strtok(input, "\n");
		if (input && stat(input, &file) == 0)
		{
			if (fork() == 0)
				execve(input, av, env);
		}
		else
		{
			perror("");
			continue;
		}
		wait(&status);
	}

	return (0);
}

/**
 * _strcmp - check the code
 * @s1: a
 * @s2: Write a function that compares two strings.
 * Return: Always 0.
 */
int _strcmp(char *s1, char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

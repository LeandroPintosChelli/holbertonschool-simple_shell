#include "main.h"
/**
* main - simple shell
* @ac: unused
* @av: unused
* @env: unused
* Return: 0
*/
int main(__attribute__((unused)) int ac, __attribute__((unused)) char **av, char **env)
{
	char *input = NULL;
	int child;
	char *buf[1024];
	char *tok;
	size_t i, n = 0;
	int status = 0;

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
		if (_strcmp(input, "env") == 0)
		{
			_env(env);
			continue;
		}
		child = fork();
		if (!buf[0])
		{
			free(buf[0]);
			free(input);
			return (0);
		}
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

/**
* _env - print environment
* @env: pointer to a char
* Return: void
*/
void _env(char **env)
{
	size_t len;

	for (; *env; *env++)
	{
		len = strlen(*env);
		write(1, *env, len);
		_putchar('\n');
	}
}

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

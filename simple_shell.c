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
	if (_strcmp(input, "env") == 0)
	{
		_env(env);
		continue;
	}
	if (stat(input, &file) == 0)
	{
		if (fork() == 0)
		{
			if (execve(buf[0], buf, env) == -1)
			{
				return (0);
			}
		}
		else
			wait(&status);
	}
	else
		perror("");
	}
	free(input);
	return (0);
}
<<<<<<< HEAD
=======

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

	for (; *env;)
	{
		len = strlen(*env);
		write(1, *env, len);
		_putchar('\n');
		*env = *env + 1;
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
>>>>>>> 4a0c0593a5a722755e1fc68d423a2b92f5ba3e06

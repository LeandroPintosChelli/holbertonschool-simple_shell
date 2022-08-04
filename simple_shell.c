#include "main.h"
/**
* main - simple shell
* @ac: Number of arguments passed to main.
* @av: Array of string arguments.
* @env: Enviroment variables.
*
* Return: Always 0.
*/

int main(__attribute__((unused)) int ac, char **av, char **env)
{
	char *input = NULL, *buf[1024], *tok, *path = NULL;
	size_t i, n = 0;
	int status = 0, cmd = 0, exit_code = 0;
	void (*builtin)(char *, int);

	while (1)
	{
		if (isatty(STDIN_FILENO) == 1)
			write(1, "$ ", 2);
		if (getline(&input, &n, stdin) == -1)
			break;
		tok = strtok(input, " \t\n\r");
		if (tok == NULL)
			continue;
		for (i = 0; i < 1024 && tok != NULL; i++)
		{
			buf[i] = tok;
			tok = strtok(NULL, " \t\n\r");
		}
		buf[i] = NULL;
		builtin = check_builtin(buf[0]);
		if (builtin != NULL)
		{
			(*builtin)(input, exit_code);
			continue;
		}
		cmd = _which(buf[0], &path);
		if (path == NULL)
		{
			p_error(buf[0], av[0], &exit_code);
			continue;
		}
		buf[0] = path;
		if (fork() == 0)
			execve(buf[0], buf, env);
		else
		{
			wait(&status);
			exit_code = WEXITSTATUS(status);		
		}
		if (cmd)
			free(path);
	}
	free(input);
	return (exit_code);
}

#include "main.h"

int main(void);
/**
* _getenv - function to do getenv
* @name: pointer
* Return: NULL
*/
char *_getenv(const char *name)
{
	int i, j;
	int status;

	for (i = 0; environ[i] != NULL; i++)
	{
	status = 1;
	for (j = 0; environ[i][j] != '='; j++)
	{
		if (name[j] != environ[i][j])
		{
			status = 0;
			break;
		}
	}
	if (status)
	{
		return (&environ[i][j + 1]);
	}
	}
	return (NULL);
}
/**
* main - function
*
* Return: 0
*/
int main(void)
{
	printf("PATH : %s\n", _getenv("PATH"));
	printf("HOME : %s\n", _getenv("HOME"));
	printf("ROOT : %s\n", _getenv("ROOT"));
	return (0);
}

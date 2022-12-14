#include "main.h"

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

/**
 * _strlen - string lenght
 * @s: function that returns the length of a string.
 * Return: Always 0.
 */
int _strlen(char *s)
{
	int i = 0;

	while (*s != '\0')
	{
		i++;
		s++;
	}
	return (i);
}

/**
* str_concat - check code
* @s1: a
* @s2: b
* Return: Always 0
*/
char *str_concat(char *s1, char *s2)
{
	int i = 0, a = 0, b = 0;
	char *c = NULL;

	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";
	a = _strlen(s1);
	b = _strlen(s2);
	c = (char *)malloc(sizeof(char) * ((a + b)) + 1);
	if (!c)
		return (NULL);
	for (i = 0; i < a; i++)
	{
		c[i] = s1[i];
	}
	for (i = 0; i < b; i++)
	{
		c[i + a] = s2[i];
	}
	c[i + a] = '\0';
	return (c);
}

/**
 * _strcmp - string compare
 * @s1: a
 * @s2: function that compares two strings.
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
* _strdup - check code
* @str: duplicate string
* Return: Always 0
*/
char *_strdup(char *str)
{
	int s = 0, i = 0;
	char *c = NULL;

	if (str == NULL)
	{
		return (NULL);
	}
	s = _strlen(str);
	c = (char *)malloc(s * sizeof(char) + 1);

	if (c == NULL)
	{
		return (NULL);
	}
	else
	{
	for (i = 0; i < s; i++)
		c[i] = str[i];
	}
	c[i] = '\0';
	return (c);
}



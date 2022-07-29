#include "main.h"
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
 *_strcat - string cat
 * @dest: a
 * @src: copies the string pointed
 * Return: Always 0.
 */
char *_strcat(char *dest, char *src)
{
	size_t dest_len = _strlen(dest);
	size_t i;

	for (i = 0 ; src[i] != '\0'; i++)
	dest[dest_len + i] = src[i];
	dest[dest_len + i] = '\0';

	return (dest);
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
 * _puts - check the code
 * @str: function that returns the length of a string.
 * Return: Always 0.
 */
void _puts(char *str)
{
	int i = 0;

	while (*str != '\0')
	{
		_putchar(*str);
		i++;
		str++;
	}
	_putchar('\n');
}

/**
* _strdup - check code
* @str: duplicate string
* Return: Always 0
*/
char *_strdup(char *str)
{
	int s, i;
	char *c;

	if (str == NULL)
	{
		return (NULL);
	}
	s = strlen(str);
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
	return (c);
}

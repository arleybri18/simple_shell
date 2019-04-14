#include "holberton.h"

/**
 * _strdup - duplicate a string with dynamic array
 *
 * @str: string to duplicate
 *
 * Return: NULL if a size or malloc fail, or copy array it's ok
 */
char *_strdup(char *str)
{
	char *copy;
	unsigned int i = 0, j = 0;

	if (str == NULL)
		return (NULL);
	while (*(str + i))
		i++;
	copy = malloc(1024 * sizeof(char));
	if (copy == NULL)
	{
		free(copy);
		return (NULL);
	}
	while (j <= i)
	{
		copy[j] = str[j];
		j++;
	}
	return (copy);
}

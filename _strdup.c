#include "holberton.h"
#include <stdlib.h>

/** _strdup - duplicate a string with dynamic array
 *
 * @str: string
 *
 * Return: NULL if a size or malloc fail, or copy array it's ok.
 */
char *_strdup(char *str)
{
	char *copy;
	char len = '0';
	unsigned int i = 0;
	unsigned int j = 0;

	if (str == NULL)
		return (NULL);
	while (len != '\0')
	{
		len = *(str + i);
		i++;
	}
	copy = malloc(i * sizeof(char));
	if (copy == NULL)
		return (NULL);
	while (j < i)
	{
		copy[j] = str[j];
		j++;
	}
	return (copy);
}

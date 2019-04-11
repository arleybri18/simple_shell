#include "holberton.h"
#include <stdlib.h>


/**
 * _strlenght - calculate a length of a string
 *
 * @s: string
 *
 * Return: size of string
 */

unsigned int _strlenght(char *s)
{
	unsigned int i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}


/**
 * _strdup - duplicate a string with dynamic array
 *
 * @str: string
 *
 * Return: NULL if a size or malloc fail, or copy array it's ok.
 */

char *_strdup(char *str)
{
	unsigned int i;
	unsigned int size;
	char *arr;
	/* Validate lenght of array*/
	if (!str)
		return (NULL);
	size = 1 + _strlenght(str);
	if (size == 0)
		return (NULL);

	/* allocate space char array*/
	arr = malloc(size * sizeof(char));
	/* validate return function malloc*/
	if (arr == NULL)
		return (NULL);
	for (i = 0; i <= size; i++)
	{
		arr[i] = str[i];
	}
	return (arr);
	free(arr);
}

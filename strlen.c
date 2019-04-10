#include "holberton.h"

/**
 * _strlen - it get a lenght of string
 * @s: receive the string
 *
 * Return: return value of len
 */

int _strlen(char *s)
{
	int len;

	len = 0;
	while (*(s + len) != '\0')
	{
		len++;
	}

	return (len);
}

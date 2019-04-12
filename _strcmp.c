#include "holberton.h"

/**
 * _strcmp - compare two words and retur if match or not match
 * @s1: firts array
 * @s2: second array
 *
 * Return: return value of flag variable
 */

int _strcmp(char *s1, char *s2)
{
	int i;
	int flag;

	flag = 0;
	if (!s1 || !s2)
		return (1);
	for (i = 0; s1[i] != '\0' && flag == 0; i++)
	{
		if (s1[i] != s2[i])
			flag = s1[i] - s2[i];
	}

	return (flag);
}

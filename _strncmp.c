#include "holberton.h"

/**
 * _strncmp - compare two words and retur if match or not match
 * @s1: firts array
 * @s2: second array
 * @len: length to compare
 *
 * Return: return value of flag variable
 */

int _strncmp(char *s1, char *s2, int len)
{
	int i;
	int flag = 0;

	for (i = 0; s1[i] != '\0' && flag == 0 && i < len; i++)
	{
		if (s1[i] != s2[i])
			flag = s1[i] - s2[i];
	}

	return (flag);
}

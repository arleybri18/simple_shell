#include "holberton.h"
#include <stdio.h>
/**
 * *_strcat - concatenates two strings.
 * @src: given string to be appended
 * @dest: big string to aapend src
 * Return: string dest
 */
char *_strcat(char *dest, char *src)
{
	int destlen = 0;
	int srclen = 0;
	int i = 0, b = 0;

	if (src == NULL)
		src = "";
	if (dest == NULL)
		dest = "";
	while (*(dest + destlen) != '\0')
	{
		destlen++;
	}
	while (*(src + srclen) != '\0')
	{
		srclen++;
	}
	for (i = 0; i < srclen; i++)
	{
		if (*(src + i) != '\0')
		{
			b = destlen + i;
			*(dest + b) = *(src + i);
		}
	}
	b = destlen + srclen;
	*(dest + b) = '\0';
	return (dest);
}

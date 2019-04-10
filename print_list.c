#include "holberton.h"

/**
 * print_list - prints a singly linked list
 * @h: pointer to the head of the list
 * Return: nothing
 */
void print_list(const path *h)
{
	path *thisnode = (path *)h;

	while (thisnode != NULL)
	{
		if (!thisnode->str)
		{
			break;
		}
		printf("%s\n", thisnode->str);
		thisnode = thisnode->next;
	}
}

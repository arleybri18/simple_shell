#include "holberton.h"
/**
 * _extractpath - creates a linked list with the value of
 * an environment variable
 * @head: pointer to NULL.
 * @string: pointer to a string with the value of the variable.
 * Return: pointer to the head of the list.
 */
path **_extractpath(path **head, char *string)
{
	char *store_path = NULL;
	path *newnode = NULL;
	path *lastnode = *head;

	newnode = malloc(sizeof(path));
	if (newnode == NULL)
	{
		free(newnode);
		return (NULL);
	}
	store_path = strtok(string, ":");

	if (!store_path)
		return (head);
	newnode->str = store_path;
	newnode->next = NULL;
	if (*head == NULL)
		*head = newnode;

	while (store_path != NULL)
	{
		store_path = strtok(NULL, ":");
		if (!store_path)
			break;

		newnode = malloc(sizeof(path));
		if (newnode == NULL)
		{
			free(newnode);
			return (0);
		}
		newnode->str = store_path;
		newnode->next = NULL;
		lastnode = *head;
		while (lastnode->next)
			lastnode = lastnode->next;
		lastnode->next = newnode;
	}
	return (head);
}

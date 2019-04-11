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
	char *store_path;
	path *newnode;
	path *lastnode = *head;
	int len = 0, i = 0;

	newnode = malloc(sizeof(path));
	if (newnode == NULL)
	{
		free(newnode);
		return (NULL);
	}
	store_path = strtok(string, ":");
	len = _strlen(store_path);
	while (i < len)
	{
		printf("%c\n", store_path[i]);
		i++;
	}

	printf("first path%s\n", store_path);
	newnode->str = store_path;
	newnode->next = NULL;
	if (*head == NULL)
	{
		*head = newnode;
	}
	while (store_path != NULL)
	{
		store_path = strtok(NULL, ":");
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

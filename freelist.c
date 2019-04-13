#include "holberton.h"
/**
 * free_list - frees a list_t list.
 * @head: given linked list
 * Return: nothing.
 */
void free_list(path *head)
{
	if (head == NULL)
		return;
	if (head->next != NULL)
		free_list(head->next);
	/*free(head->str);*/
	free(head);
}

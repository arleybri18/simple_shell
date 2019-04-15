#include "holberton.h"

/**
 * command - this function validate command to execute
 *
 * @commands: pointer to comands
 * @list: lists of the path for search commands
 * Return: Command to execute
 */
char *command(char **commands, path *list)
{
	struct stat st;
	char *concat = NULL;

	if (commands[0] == NULL)
		exit(EXIT_SUCCESS);
	if (!list)
	{
		/*printf("NULL PATH");*/
		exit(EXIT_SUCCESS);
	}
	if (!list->str)
	{
		/*printf("NULL PATH");*/
		exit(EXIT_SUCCESS);
	}
	/*if (stat(commands[0], &st) != 0)*/
	if (commands[0][0] != '/')
	{
		while (list)
		{	concat = _strdup(list->str);
			if (!concat)
			{
				printf("insufficient memory was available.");
				free(concat);
				exit(EXIT_SUCCESS);
			}
			concat = _strcat(concat, "/");
			concat = _strcat(concat, commands[0]);
			if (stat(concat, &st) == 0)
				break;
			list = list->next;
		}
	}
	else
		concat = commands[0];
	if (stat(concat, &st) != 0)
		return (commands[0]);
	return (concat);
}

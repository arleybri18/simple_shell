#include "holberton.h"

/**
 * fun_exec - this function exec the commands
 *
 * @commands: contain the strings with the commands
 * Return: Nothing
 */
void fun_exec(char **commands)
{
	int new_id;
	struct stat st;
	path *head = NULL, *node, **store_paths = NULL;
	char *concat = NULL, *pathstr = NULL;

	pathstr = _getenv("PATH");
	store_paths = _extractpath(&head, pathstr);
	if (!store_paths)
	{
		/*printf("NULL PATH");*/
		free_list(head);
		exit(EXIT_SUCCESS);
	}

	if (commands[0] != NULL)
	{
		if (_strncmp(commands[0], "exit", 4) == 0)
			exit(EXIT_SUCCESS);
	}

	/*create child proccess */
	new_id = fork();
	if (new_id == 0)
	{

		if (commands[0] == NULL)
			exit(EXIT_SUCCESS);

		node = *store_paths;
		if (!node)
		{
			/*printf("NULL PATH");*/
			exit(EXIT_SUCCESS);
		}
		if (!node->str)
		{
			/*printf("NULL PATH");*/
			exit(EXIT_SUCCESS);
		}
		/*if (stat(commands[0], &st) != 0)*/
		if (commands[0][0] != '/')
		{
			while (node)
			{	concat = _strdup(node->str);
				if (!concat)
				{
					printf("insufficient memory was available.");
					free_list(head);
					free(concat);
					exit(EXIT_SUCCESS);
				}
				concat = _strcat(concat, "/");
				concat = _strcat(concat, commands[0]);
				if (stat(concat, &st) == 0)
					break;
				node = node->next;
			}
		}
		else
			concat = commands[0];
		/*execute process*/
		if (stat(concat, &st) == 0)
		{
			execve(concat, commands, NULL);
			free_list(head);
			free(concat);
			exit(EXIT_SUCCESS);
		}

		else
		{
			printf("%s: No such file or directory\n", commands[0]);
			free(concat);
			free_list(head);
		}
	}
	else
	{
		free_list(head);
		free(concat);
		wait(NULL);
	}
}

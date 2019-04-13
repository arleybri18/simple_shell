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
	char *concat = NULL, *concat1 = NULL, *concat2 = NULL, *pathstr = NULL;

	if (commands[0] == NULL)
		exit(EXIT_SUCCESS);
	pathstr = _getenv("PATH");
	store_paths = _extractpath(&head, pathstr);
	if (!store_paths)
	{
		printf("NULL PATH");
		exit(EXIT_SUCCESS);
	}
	if (_strcmp(commands[0], "exit") == 0)
		exit(EXIT_SUCCESS);
	/*create child proccess */
	new_id = fork();
	if (new_id == 0)
	{
		if (stat(commands[0], &st) != 0)
		{node = *store_paths;
			if (!node)
			{
				printf("NULL PATH");
				exit(EXIT_SUCCESS);
			}
			if (!node->str)
			{
				printf("NULL PATH");
				exit(EXIT_SUCCESS);
			}
			while (node->str)
			{	concat = _strdup(node->str);
				if (!concat)
				{
				printf("insufficient memory was available.");
				exit(EXIT_SUCCESS);
				}
				concat1 = _strcat(concat, "/");
				concat2 = _strcat(concat1, commands[0]);
				if (stat(concat2, &st) == 0)
					break;
				node = node->next;
			}
		}
		else
			concat2 = commands[0];
		/*execute process*/
		if (stat(concat2, &st) == 0)
			execve(concat2, commands, NULL);
		else
		{
			printf("%s: No such file or directory\n", commands[0]);
		}
	}
	else
		wait(NULL);
}

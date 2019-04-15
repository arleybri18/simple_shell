#include "holberton.h"

/**
 * fun_exec - this function exec the commands
 *
 * @commands: contain the strings with the commands
 * Return: Nothing
 */
void fun_exec(char **commands)
{
	int new_id, flag;
	struct stat st;
	path *head = NULL, *node, **store_paths = NULL;
	char *concat, *concat1, *concat2, *pathstr;

	pathstr = _getenv("PATH");
	store_paths = _extractpath(&head, pathstr);
	if (_strcmp(commands[0], "exit") == 0)
		exit(EXIT_SUCCESS);
	/*create child proccess */
	new_id = fork();
	if (new_id == 0)
	{
		if (commands[0] == NULL)
			exit(EXIT_SUCCESS);
		if (commands[0][0] != '/')
		{
		node = *store_paths;
		flag = 0;
		while (node->str)
		{	concat = _strdup(node->str);
			concat1 = _strcat(concat, "/");
			concat2 = _strcat(concat1, commands[0]);
			if (stat(concat2, &st) == 0 && flag == 0)
			{
				flag = 1;
				break;
			}
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
			free(concat2);
			free_list(*store_paths);
			printf("%s: No such file or directory\n", commands[0]);
		}
	}
	else
		wait(NULL);
}
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
	char *concat, *concat1, *concat2, *pathstr;

	pathstr = _getenv("PATH");
	store_paths = _extractpath(&head, pathstr);

	/*create child proccess */
	new_id = fork();
	if (new_id == 0)
	{
		if (commands[0] == NULL)
		{
			exit(0);
		}
		if (stat(commands[0], &st) != 0)
		{
			node = *store_paths;
			while (node->str)
			{
				concat = _strdup(node->str);
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
			free(concat2);
			free_list(*store_paths);
			printf("%s: No such file or directory\n", commands[0]);
		}
	}
	else
		wait(NULL);
}

#include "holberton.h"

/**
 * fun_exec - this function exec the commands
 *
 * @commands: contain the strings with the commands
 * Return: Nothing
 */
void fun_exec(char **commands)
{
	int new_id, i;
	struct stat st;
	path *head = NULL, **store_paths = NULL;
	char *exec_command = NULL, *pathstr = NULL;
	/*char **envir = environ;*/

	pathstr = _getenv("PATH");
	store_paths = _extractpath(&head, pathstr);
	if (!store_paths)
	{
		/*printf("NULL PATH");*/
		free_list(head);
		exit(EXIT_SUCCESS);	}
	/*create child proccess */
	new_id = fork();
	if (new_id == 0)
	{
		exec_command = command(commands, *store_paths);
		/*execute process*/
		if (_strncmp(commands[0], "env", 3) == 0)
		{
			for (i = 0; environ != NULL; i++)
				printf("%s\n", environ[i]);	}
		else if (stat(exec_command, &st) == 0)
		{
			execve(exec_command, commands, NULL);
			free_list(head);
			free(exec_command);
			exit(EXIT_SUCCESS);		}
		else
		{
			printf("%s: No such file or directory\n", commands[0]);
			free_list(head);
			free(exec_command);		}
	}
	else
	{
		free_list(head);
		free(exec_command);
		wait(NULL);	}
}

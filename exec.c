#include "holberton.h"

/**
 * fun_exec - this function exec the commands
 *
 * @commands: contain the strings with the commands
 * @argv: arguments of the main
 * @env: variable environ received from main
 * Return: Nothing
 */
void fun_exec(char **argv, char **env, char **commands)
{
	int new_id;
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
			print_env(env);
		else if (stat(exec_command, &st) == 0)
		{
			execve(exec_command, commands, NULL);
			free_list(head);
			free(exec_command);
			exit(EXIT_SUCCESS);		}
		else
		{
			handle_errors(argv, commands);
			free_list(head);
			free(exec_command);		}
	}
	else
	{
		free_list(head);
		free(exec_command);
		wait(NULL);	}
}

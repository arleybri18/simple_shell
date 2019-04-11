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
	pid_t child_id;
	path *head;
	char *pathstr, *alone, bin[10] = "/bin/";
	path **store_paths;

	head = NULL;
	store_paths = NULL;
	pathstr = _getenv("PATH");
	store_paths = _extractpath(&head, pathstr);
	/*print_list(*store_paths);*/
	(void)store_paths;
	/*create child proccess */
	new_id = fork();
	if (new_id == 0)
	{
		if (commands[0][0] != '/')
		{
			alone = commands[0];
			commands[0] = _strcat(bin, alone);
		}
		/*execute process*/
		child_id = getpid();
		if (stat(commands[0], &st) == 0)
		{
			execve(commands[0], commands, NULL);
			sleep(1);
		}
		else
		{
			printf("%s: No such file or directory\n", commands[0]);
		}
	}
	else
	{
		wait(&child_id);
	}
}

#include "holberton.h"

/**
 * fun_exec - this function exec the commands
 *
 * @commands: contain the strings with the commands
 * Return: Nothing
 */

void fun_exec(char **commands)
{
	int new_id, terminal = 0;
	struct stat st;
	pid_t child_id, parent_id;

	/*validate EOF*/
	terminal = isatty(0);

	/*create child proccess */
	new_id = fork();
	if (new_id == 0)
	{
		child_id = getpid();
		parent_id = getpid();
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
		if (terminal == 0)
			exit(98);
		wait(&child_id);
	}
}

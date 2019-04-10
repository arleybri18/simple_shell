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

	/*create child proccess */
	new_id = fork();
	if (new_id == 0)
	{
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

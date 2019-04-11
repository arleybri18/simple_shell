#include "holberton.h"

/**
 * fun_exec - this function exec the commands
 *
 * @commands: contain the strings with the commands
 * Return: Nothing
 */
char *_strcat(char *dest, char *src);
void fun_exec(char **commands)
{
	int new_id;
	struct stat st;
	pid_t child_id;
	path *head;
	path *node;
	char *concat,*concat1, *concat2;
	char *pathstr/*, *alone, bin[10] = "/bin/"*/;
	path **store_paths;

	head = NULL;
	store_paths = NULL;
	pathstr = _getenv("PATH");
	store_paths = _extractpath(&head, pathstr);

	node = head;
		
	/*print_list(*store_paths);*/
	(void)store_paths;
	/*create child proccess */
	new_id = fork();
	if (new_id == 0)
	{/*
		if (stat(commands[0], &st) != 0)
		{			
			if (commands[0][0] != '/')
			{
				alone = commands[0];
				commands[0] = _strcat(bin, alone);
			}
		}*/
		/*execute process*/


	while (node->next != NULL)
	{
		concat = strdup(node->str);
		/*printf("concat es %s\n", concat);*/
		concat1 = _strcat(concat, "/");
		/*printf("concat1 es %s\n", concat1);*/
		concat2 = _strcat(concat1, commands[0]);
		if (stat(concat2, &st) == 0)
		{
			printf("concat2 es %s\n", concat2);
			node = head;
			printf("%s\n", node->str);
			break;
		}
		/*printf("node es %s\n", node->str);*/
		node = node->next;
	}






		child_id = getpid();
		printf("segundo llamado concat2 %s\n", concat2);
		if (stat(concat2, &st) == 0)
		{
			execve(concat2, commands, NULL);
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

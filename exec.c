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
	char *pathstr, *alone, bin[10] = "/bin/";
	path **store_paths;

	head = NULL;
	store_paths = NULL;
	pathstr = _getenv("PATH");
	store_paths = _extractpath(&head, pathstr);
	print_list(*store_paths);

	/*create child proccess */
	new_id = fork();
	if (new_id == 0)
	{
		if (commands[0][0] != '/')
		{
			alone = commands[0];
			commands[0] = strcat(bin, alone);
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
	char *_strcat(char *dest, char *src)
	{
		int destlen = 0;
		int srclen = 0;
		int i = 0;
		char b;

		while (*(dest + destlen) != '\0')
		{
			destlen++;
		}
		while (*(src + srclen) != '\0')
		{
			srclen++;
		}
		for (i = 0; i < srclen; i++)
		{
			if (*(src + i) != '\0')
			{
				b = destlen + i;
				*(dest + b) = *(src + i);
			}
		}
		b = destlen + srclen;
		*(dest + b) = '\0';
		printf("Dest;%s", dest);
		return (dest);
	}

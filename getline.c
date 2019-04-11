#include "holberton.h"
/**
 * fun_getline -  function that get the characters in the line
 *
 * Return: Nothing;
 */

void fun_getline(void)
{
	int count = 1;
	char *buffer;
	size_t bufsize = 1024;
	ssize_t characters;
	char delim[] = " \n";
	char *string;
	char **commands;

	/*allocate memory for commands*/
	commands = malloc(1024 * sizeof(char *));

	if (buffer == NULL || commands == NULL)
	{
		perror("Unable to allocate memory");
		exit(1);
	}

	/*print promt*/
	if (isatty(0) != 0)
		printf("#cisfun$");
	/*getline*/
	characters = getline(&buffer, &bufsize, stdin);
	if (characters == EOF)
		exit(98);
	else
	{	/*saved commands typed*/
		string = strtok(buffer, delim);
		commands[0] = string;
		while (string != NULL)
		{
			string = strtok(NULL, delim);
			commands[count] = string;
			count++;
		}
		fun_exec(commands);
	}
}

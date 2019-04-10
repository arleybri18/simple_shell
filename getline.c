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
	size_t bufsize = 32;
	size_t characters;
	char delim[] = " \n";
	char *string;
	char **commands;

	/*allocate memory for buffer and commands*/
	buffer = (char *)malloc(bufsize * sizeof(char));
	commands = malloc(30 * sizeof(char *));

	if (buffer == NULL || commands == NULL)
	{
		perror("Unable to allocate memory");
		exit(1);
	}
	/*print promt*/
	printf("#cisfun$");
	/*getline*/
	characters = getline(&buffer, &bufsize, stdin);
	if (characters == -1)
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

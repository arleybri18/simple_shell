#include "holberton.h"
/**
 * fun_getline -  function that get the characters in the line
 *
 * Return: Nothing;
 */

void fun_getline(void)
{
	int count = 1;
	char *buffer = NULL;
	size_t bufsize = 1024;
	ssize_t characters = 0;
	char delim[] = " \n";
	char *string;
	char *commands[20];

	if (isatty(0) != 0)
		printf("#cisfun$");
	/*getline*/
	characters = getline(&buffer, &bufsize, stdin);
	if (characters == EOF)
	{
		write(STDOUT_FILENO, "\n", 1);
		exit(98);
	}
	if (buffer == NULL || commands == NULL)
	{
		perror("Unable to allocate memory");
		exit(1);
	}
	else
	{
		/*saved commands typed*/
		string = strtok(buffer, delim);
		commands[0] = string;
		while (string != NULL)
		{
			string = strtok(NULL, delim);
			commands[count] = string;
			count++;
		}
		fun_exec(commands);
		free(buffer);
	}
}

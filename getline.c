#include "holberton.h"
/**
 * fun_getline -  function that get the characters in the line
 *
 * @argv: arguments received on main
 * @env: variable enviroment of the main
 * Return: Nothing;
 */

void fun_getline(char **argv, char **env)
{
	int count = 1;
	char *buffer = NULL;
	size_t bufsize = 0;
	ssize_t characters = 0;
	char delim[] = " \t\r\n";
	char *string;
	char *commands[50];

	if (isatty(0) != 0)
		write(STDOUT_FILENO, "", 1);
	/*getline*/
	characters = getline(&buffer, &bufsize, stdin);
	if (characters == EOF || characters == -1)
	{
		write(STDOUT_FILENO, "\n", 1);
		exit(EXIT_SUCCESS);
	}
	if (buffer == NULL || commands == NULL)
	{
		perror("Unable to allocate memory");
		exit(EXIT_SUCCESS);
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
		if (commands[0] != NULL)
		{
			if (_strncmp(commands[0], "exit", 4) == 0)
				exit(EXIT_SUCCESS);
		}
		fun_exec(argv, env, commands);
	}
}

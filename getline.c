#include "holberton.h"
/**
 * fun_getline -  function that get the characters in the line
 *
 * @argv: arguments received on main
 * @env: variable enviroment of the main
 * @last_status: save de last status
 * Return: Nothing;
 */
int fun_getline(char **argv, char **env, int *last_status)
{
	int count = 1;
	char *buffer = NULL;
	size_t bufsize = 0;
	ssize_t characters = 0;
	char delim[] = " \t\r\n";
	char *string;
	char *commands[50];

	/*getline*/
	characters = _getline(&buffer, &bufsize);
	if (characters == EOF || characters == -1)
	{
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
				exit(*last_status);
		}
		*last_status = fun_exec(argv, env, commands);
	}
	return (*last_status);
}
/**
 * _getline - do the same getline function from C
 *
 * @buffer: pointer to a null array
 * @n: size of buffer
 *
 * Return: characters read;
 */
ssize_t _getline(char **buffer, size_t *n)
{
	char buf[120];
	ssize_t characters = 0, resize = 1;

	*buffer = malloc(120 * sizeof(char));
	characters = read(STDIN_FILENO, &buf, 120);
	if (buf[0] == 0)
		return (-1);
	strncat(*buffer, buf, characters);
	if (characters == 120)
	{
		while (characters == 120)
		{
			resize++;
			*buffer = realloc(*buffer, resize * 120);
			characters = read(STDIN_FILENO, buf, 120);
			if (characters == -1)
				return (-1);
			strncat(*buffer, buf, characters);
		}
	}
	*n = resize * 120;
	return (characters);
}

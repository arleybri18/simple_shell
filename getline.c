#include "holberton.h"
int semic(int semi, int *ls, char **cmds, char **argv, char **env, char **);
/**
 * fun_getline -  function that get the characters in the line
 *
 * @argv: arguments received on main
 * @env: variable enviroment of the main
 * @ls: save de last status
 * Return: Nothing;
 */

int fun_getline(char **argv, char **env, int *ls)
{
	int count = 1, semi = 0;
	size_t bufsize = 0;
	ssize_t characters = 0;
	char delim[] = " \t\r\n", *string, *cmds[50], *buffer = NULL, *sec[5];

	/*getline*/
	characters = getline(&buffer, &bufsize, stdin);
	if (characters == EOF || characters == -1)
		exit(EXIT_SUCCESS);
	if (buffer == NULL || cmds == NULL)
	{
		perror("Unable to allocate memory");
		exit(EXIT_SUCCESS);
	}
	else
	{
		/*saved commands typed*/
		string = strtok(buffer, delim);
		cmds[0] = string;
		while (string != NULL)
		{
			string = strtok(NULL, delim);
			cmds[count] = string;
			if (cmds[count] && _strncmp(cmds[count], ";", 1) == 0)
				semi++;
			count++;
		}
		if (cmds[0] != NULL)
		{
			if (_strncmp(cmds[0], "exit", 4) == 0)
				exit(*ls);
		}
		if (semi > 0)
			*ls = semic(semi, ls, cmds, argv, env, sec);
		else
			*ls = fun_exec(argv, env, cmds);
	}
	return (*ls);
}
/**
 * semic - handle the commands separator ;
 *
 * @argv: arguments received on main
 * @env: variable enviroment of the main
 * @ls: save de last status
 * @semi: number of semicolon in cmds
 * @cmds: array with commands
 * @sec: array to store commands without semicolon
 * Return: Nothing;
 */
int semic(int semi, int *ls, char **cmds, char **argv, char **env, char **sec)
{
	int i = 0, b = 0, count = 0;

	while (count < semi + 1)
	{
		b = 0;
		while (cmds[i])
		{
			sec[b] = cmds[i];
			if (cmds[i + 1] && _strncmp(cmds[i + 1], ";", 1) == 0)
			{
				sec[b + 1] = NULL;
				i++;
				break;
			}
			if (cmds[i + 1] == NULL)
				break;
			b++;
			i++;
		}
		*ls = fun_exec(argv, env, sec);
		if (cmds[i + 1] == NULL)
			break;
		i++;
		b = 0;
		while (b < 5)
		{
			sec[b] = NULL;
			b++;
		}
		count++;
	}
	return (*ls);
}

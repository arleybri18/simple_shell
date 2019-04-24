#include "holberton.h"

/**
 * print_env - print_enviroment
 *
 * @env: variable environ
 * Return: Nothing
 */

void print_env(char **env)
{
	int i;

	env = environ;
	for (i = 0; env[i]; i++)
	{
		write(STDOUT_FILENO, env[i], _strlen(env[i]));
		write(STDOUT_FILENO, "\n", 1);
	}
}

#include "holberton.h"

/**
 * main - main function of shell
 *
 * @argc: number of arguments
 * @argv: arguments of main
 * @env: envrioment variable
 * Return: Always 0 if successful
 */

int main(int argc, char **argv, char **env)
{
	signal(SIGINT, handle_sigint);
	while (1)
	{
		if (argc > 0)
			fun_getline(argv, env);
	}
	return (0);
}

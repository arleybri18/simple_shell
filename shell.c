#include "holberton.h"

/**
 * main - main function of shell
 *
 * Return: Always 0 if successful
 */

int main(void)
{

	signal(SIGINT, handle_sigint);
	while (1)
	{
		fun_getline();
	}
	return (0);
}

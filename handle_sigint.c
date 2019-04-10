#include "holberton.h"
/**
 * handle_sigint -  function to handle de sigint
 *
 * @sig: number to interrup proccess
 * Return: Nothing
 */

void handle_sigint(int sig)
{
	if (sig != 0)
		printf("\n#cisfun$");
	fflush(stdout);
}

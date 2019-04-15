#include "holberton.h"
/**
 * _getenv - returns a pointer to the corresponding
 * value string of a environment variable.
 * @name: pointer to string-name of the require variable.
 * Return: a pointer to the string of the value or NULL.
 */
char *_getenv(char *name)
{
	int i = 0, b = 0, c = 0;
	char **test = environ;
	char *string = NULL, *copy = NULL;

	if (!name)
		return (NULL);
	while (test[i])
	{
		b = 0;
		while (name[b])
		{
			if (name[b] == test[i][b])
				c++;
			else
			{
				c = 0;
				break;
			}
			b++;
		}
		string = NULL;
		if (_strlen(name) == c && test[i][b] == '=')
		{
			copy = _strdup(environ[i]);
			strtok(copy, "=");
			string = strtok(NULL, "=");
			return (string);
			free(copy);
		}
		i++;
	}
	free(copy);
	return (NULL);
}

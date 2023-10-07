#include "shell.h"

/**
 * _getenv - it searches for an enviroment value
 * @name: the key of the variable
 * Return: it returns the value if the key is found
 * it returns NULL if not found
 */

char *_getenv(const char *name)
{
	char *env, *token, *value;
	int idx = 0;

	while (environ[idx] != NULL)
	{
		env = strdup(environ[idx]);
		token = strtok(env, "=");

		if (token != NULL && strcmp(token, name) == 0)
		{
			value = strdup(strtok(NULL, ""));
			free(env);
			return (value);
		}

		free(env);
		idx++;
	}
	return (NULL);
}

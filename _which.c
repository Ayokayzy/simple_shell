#include "shell.h"

/**
 * _which - a program that looks for a file in PATH.
 * @filename: the file
 * Return: it return the fullpath of the filename if found
 * NULL if the file was not found
 */

char *_which(char *filename)
{
	struct stat st;
	char *fullpath, *path, *token;

	if (filename == NULL)
		return (NULL);

	path = _getenv("PATH");
	if (path == NULL)
	{
		free(path);
		return (NULL);
	}

	token = strtok(path, ":");
	while (token != NULL)
	{
		fullpath = _concat(token, "/", filename);
		if (fullpath == NULL)
		{
			free(path);
			return (NULL);
		}

		if (stat(fullpath, &st) == 0)
		{
			free(path);
			return (fullpath);
		}
		free(fullpath);
		token = strtok(NULL, ":");
	}

	free(path);
	return (NULL);
}


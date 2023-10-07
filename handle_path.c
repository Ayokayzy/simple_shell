#include "shell.h"

/**
 * has_path - checks if the users command has parh or not
 * @command: the command the user entered
 * Return: returns 1 if the command has a path
 * 0 if there is no path
 */

int has_path(char *command)
{
	return (command != NULL && command[0] == '/');
}

/**
 * handle_path - handles a commands path
 * @command: the command to be handled
 * Return: returns a full path of the command if it exists
 * NULL if it does not exist
 */

char *handle_path(char *command)
{
	char *full_path = NULL;
	struct stat st;

	if (command == NULL)
		return (NULL);

	if (has_path(command) == 1)
	{
		if (stat(command, &st) == 0)
		{
			return (command);
		}
	}
	else
	{
		full_path = _which(command);

		if (full_path != NULL)
			return (full_path);
	}
	return (NULL);
}

#include "shell.h"

/**
 * is_builtin - checks is command is a built in command
 * @command: the command to be checked
 * Return: 1 if built-in, -1 if not
 */

int is_builtin(char *command)
{
	if (command == NULL)
		return (1);

	if (strcmp(command, "exit") == 0 ||
		strcmp(command, "env") == 0)
		return (0);

	return (1);
}

/**
 * handle_builtin - executes the built in commands
 * @command: the command to be executed
 * @av: the argument variable
 * @line: the buffer
 * Return: 0 if success 1 if failure
 */

int handle_builtin(char *command, char **av, char *line)
{
	if (strcmp(command, "env") == 0)
	{
		return (_printenv());
	}

	if (strcmp(command, "exit") == 0)
	{
		return (builtin_exit(av, line));
	}
	return (0);
}

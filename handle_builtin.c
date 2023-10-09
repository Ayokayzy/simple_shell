#include "shell.h"

/**
 * is_builtin - checks is command is a built in command
 * @command: the command to be checked
 * Return: 1 if built-in, -1 if not
 */

int is_builtin(char *command)
{
	if (command == NULL)
		return (0);

	if (strcmp(command, "exit") == 0 ||
		strcmp(command, "env") == 0)
		return (1);

	return (0);
}

/**
 * handle_builtin - executes the built in commands
 * @command: the command to be executed
 * @status: the error status
 * @av: the argument variable
 * @buff: the command strings
 */

void handle_builtin(char *command, int status, char **av, char *buff)
{
	if (strcmp(command, "env") == 0)
	{
		_printenv();
	}

	if (strcmp(command, "exit") == 0)
	{
		builtin_exit(status, av, buff);
	}
}

#include "shell.h"
/**
 * execute_command - function that execute commands
 * @argv: argument vector
 * @av: double pointer argument
 * @line: the buffer
 * Return: returns
 */

ssize_t execute_command(char **av, char **argv, char *line)
{
	char *command;

	if (av == NULL || !av)
	{
		perror("hsh");
		return (1);
	}
	command = handle_path(av[0]);
	if (command == NULL)
	{
		error_print(argv[0], av[0]);
		return (127);
	}
	return (_fork(av, argv, command, line));
}


/**
 * handle_err - function that handle error
 * @err: first arg
 * @command: second err
 * Return: void
 */
void handle_err(char *err, char *command)
{
	perror(err);
	free(command);
}

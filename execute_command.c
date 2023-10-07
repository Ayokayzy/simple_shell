#include "shell.h"
/**
 * execute_command - function that execute commands
 * @av: double pointer argument
 * Return: returns
 */

ssize_t execute_command(char **av)
{
	int wait_status;
	char *command;
	pid_t pid;

	if (av[0] == NULL)
	{
		fprintf(stderr,  "Invalid command or arguments\n");
		return (-1);
	}
	command = handle_path(av[0]);
	if (command == NULL)
	{
		fprintf(stderr, "%s: not found\n", av[0]);
		return (-1);
	}
	pid = fork();
	if (pid == -1)
	{
		handle_err("fork", command);
		return (-1);
	}
	if (pid == 0)
	{
		if (execve(command, av, environ) == -1)
		{
			handle_err("execve", command);
			return (-1);
		}
	}
	else
	{
		if (wait(&wait_status) == -1)
		{
			handle_err("wait", command);
			return (-1);
		}
	}
	free(command);
	return (0);
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
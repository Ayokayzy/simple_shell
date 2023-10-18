#include "shell.h"

/**
 * _fork - executes a command
 * @av: array of tokens
 * @argv: programs argument vectors
 * @command: the command to be executed
 * @line: the buffer
 * Return: 0 if success 1 if failure
 */

int _fork(char **av, char **argv, char *command, char *line)
{
	pid_t pid;
	int wait_status;

	pid = fork();
	if (pid == -1)
	{
		error_print(argv[0], av[0]);
		free(command);
		return (1);
	}
	else if (pid == 0)
	{
		if (execve(command, av, environ) == -1)
		{
			handle_err(argv[0], command);
			free(line);
			free_tokens(av);
			exit(1);
		}
	}
	else
	{
		if (wait(&wait_status) == -1)
		{
			error_print(argv[0],
			av[0]);
			free(command);
			return (1);
		}
	}
	free(command);
	return (0);
}

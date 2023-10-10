#include "shell.h"
/**
 * builtin_exit - function to exit the program
 * @status: first argument that takes in input
 * @av: argument variables
 * @buff: the command string
 * Return: returns (null)
 */
void builtin_exit(int status, char **av, char *buff)
{
	if (buff != NULL)
		free(buff);
	free_tokens(av);
	if (status == 1)
	{
		fprintf(stderr, "Error: Prgoram exiting with status %d\n", status);
	}

	exit(status);
}

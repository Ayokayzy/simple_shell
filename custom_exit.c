#include "shell.h"
/**
 * builtin_exit - function to exit the program
 * @av: argument variables
 * @line: the buffer
 * Return: returns 0 if success and 1 if failure
 */
int builtin_exit(char **av, char *line)
{
	free_tokens(av);
	free(line);
	exit(0);
}

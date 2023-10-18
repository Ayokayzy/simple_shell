#include "shell.h"

/**
 * _printenv - A program that prints enviroment variables
 * Return: 0 if successfull 1 if failure
 */

int _printenv(void)
{
	int idx = 0;

	if (environ == NULL)
		return (1);

	while (environ[idx] != NULL)
	{
		printstring(environ[idx]);
		idx++;
	}

	return (0);
}

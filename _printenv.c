#include "shell.h"

/**
 * _printenv - A program that prints enviroment variables
 */

void _printenv(void)
{
	int idx = 0;

	while (environ[idx] != NULL)
	{
		printf("%s\n", environ[idx]);
		idx++;
	}
}

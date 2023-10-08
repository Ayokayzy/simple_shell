#include "shell.h"

/**
 * _printenv - A program that prints enviroment variables
 */

void _printenv(void)
{
	int idx = 0, indx2;

	while (environ[idx] != NULL)
	{
		indx2 = 0;
		while ((environ[idx])[indx2])
		{
			printchar((environ[idx])[indx2]);
			indx2++;
		}
		printchar('\0');
		printchar('\n');
		idx++;
	}
}

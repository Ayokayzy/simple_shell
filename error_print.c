#include "shell.h"

/**
 * error_print - prints error to standard output
 * @filename: executable file name.
 * @command: command entered.
 */

void error_print(char *filename, char *command)
{
	char *str1, *str2;

	str1 = concat2str(filename, ": 1: ");
	str2 = _concat(str1, command, ": not found");
	free(str1);
	printstring(str2);
	free(str2);
}

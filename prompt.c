#include "shell.h"

/**
 * prompt - displays a cursor so a user can type something
 */

void prompt()
{
	int interactive = isatty(STDIN_FILENO);

	if (interactive == 1)
		write(1, "$ ", _strlen("$ "));
}

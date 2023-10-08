#include "shell.h"

/**
 * printchar - prints a  character  to standard output
 * @c: character to be printed
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int printchar(char c)
{
	return (write(1, &c, 1));
}
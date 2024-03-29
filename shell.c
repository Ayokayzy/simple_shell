#include "shell.h"

/**
 * main - shell entry point
 * @argc: number of argument
 * @argv: argument vectors
 * Return: 0 on success.
 */

int main(int argc __attribute__((unused)), char **argv)
{
	ssize_t chars_read;
	char *line = NULL, **av = NULL, *delimeter = " \n";
	size_t n = 0;
	int status = 0;


	while (1)
	{
		prompt();
		chars_read = getline(&line, &n, stdin);

		if (chars_read == -1)
		{
			break;
		}
		av = get_argv(line, delimeter);
		if (av != NULL)
		{
			if (is_builtin(av[0]) == 0)
				status = handle_builtin(av[0], av, line);
			else
				status = execute_command(av, argv, line);
		}
		free_tokens(av);
	}
	free(line);
	return (status);
}

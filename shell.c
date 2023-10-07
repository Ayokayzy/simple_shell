#include "shell.h"

int main() {
	ssize_t chars_read;
	char *line = NULL, **av = NULL, *delimeter = " \n";
	size_t n = 0;


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
			execute_command(av);
		}
		free_tokens(av);
	}
	free(line);
	return (0);
}

#include "shell.h"

int main() {
	ssize_t chars_read;
	char *line = NULL, **av, *delimeter = " \n";
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
		if (av == NULL)
		{
			continue;
		}
		else
		{
			execute_command(av);
		}
	}
	free(line);
	free_tokens(av);
	return (0);
}

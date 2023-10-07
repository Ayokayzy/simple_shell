#include "shell.h"

/**
 * get_argv - a function that splits a string and returns an
 * array of each word of the string.
 * @buffer: allocated memory to store strings
 * Return: an array of tokens
 */

char **get_argv(char *buffer, char *delim)
{
	char *str1;
	char *tok, *token;
	int ac, idx;
	char **av;

	if (buffer == NULL)
		return (NULL);

	str1 = _strdup(buffer);
	tok = strtok(str1, delim);
	ac = 0;
	while (tok != NULL)
	{
		ac++;
		tok = strtok(NULL, delim);
	}
	free(str1);

	av = malloc(sizeof(char *) * (ac + 1));
	if (av == NULL)
	{
		free(av);
		return (NULL);
	}
	token = strtok(buffer, delim);

	idx = 0;
	while (token != NULL)
	{
		av[idx] = _strdup(token);
		token = strtok(NULL, delim);
		idx++;
	}
	av[idx] = NULL;

	return (av);
}

/**
 * free_tokens - function that free tokens
 * @av: takes in double pointer argument
 * Return: null
 */

void free_tokens(char **av)
{
	int idx = 0;

	if (av == NULL)
		return;

	while (av[idx] != NULL)
	{
		free(av[idx]);
		idx++;
	}
	free(av);
} 

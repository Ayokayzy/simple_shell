#include "shell.h"

/**
 * concat2str - concatenates two strings.
 * @a: first string.
 * @b: second string.
 * Return: pointer pointing to a newly allocated space
 * in memory which contains the contents of s1,
 * followed by the contents of s2, and null terminated
 */

char *concat2str(char *a, char *b)
{
	char *new_mem;
	int i, j;

	if (a == NULL || b == NULL)
		return (NULL);

	new_mem = malloc(sizeof(char) * (_strlen(a) + _strlen(b) + 1));
	if (new_mem == NULL)
		return (NULL);

	i = 0, j = 0;
	while (a[i] != '\0')
	{
		new_mem[i] = a[i];
		i++;
	}

	while (b[j] != '\0')
	{
		new_mem[i] = b[j];
		j++;
		i++;
	}

	new_mem[i] = '\0';
	return (new_mem);
}

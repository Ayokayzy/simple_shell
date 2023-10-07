#include "shell.h"
/**
 * _concat - function that concatenates three strings
 * @a: takes in first argument
 * @b: takes in second argument
 * @c: takes in third argument
 * Return: returns memory of new argument
 */

char *_concat(char *a, char *b, char *c)
{
	char *new_mem;
	int i, j, k;

	if (a == NULL || b == NULL || c == NULL)
		return (NULL);

	new_mem = malloc(sizeof(char) * (_strlen(a) + _strlen(b) + _strlen(c) + 1));
	if (new_mem == NULL)
		return (NULL);

	i = 0, j = 0, k = 0;
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

	while (c[k] != '\0')
	{
		new_mem[i] = c[k];
		k++;
		i++;
	}
	new_mem[i] = '\0';
	return (new_mem);
}

/*
 * int main()
 * {
 *	char *new_str;
 *
 *	new_str = _concat("Hi, ", "how are ", "you!");
 *	if (new_str == NULL)
 *		printf("NULL");
 *
 *	printf("%s\n", new_str);
 *	free(new_str);
 *	return (0);
 * }
 */

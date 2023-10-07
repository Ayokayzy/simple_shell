#include "shell.h"
/**
 * _strlen - function that calculate the length of a string
 * @str: takes in a pointer to a string
 * Return: returns count
 */

int _strlen(char *str)
{
	int count = 0;

	while (str[count] != '\0')
	{
		count++;
	}
	return (count);
}

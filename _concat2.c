#include "shell.h"

/**
 * concat2str - concatenates two strings.
 * @s1: first string.
 * @s2: second string.
 * Return: pointer pointing to a newly allocated space
 * in memory which contains the contents of s1,
 * followed by the contents of s2, and null terminated
 */

char *concat2str(char *s1, char *s2)
{
	char *new_str;
	unsigned int len_s1 = 0, len_s2 = 0, new_len;
	unsigned int i = 0, j = 0;

	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";
	while (s1[len_s1] != '\0')
		len_s1++;
	while (s2[len_s2] != '\0')
		len_s2++;
	new_len = len_s1 + len_s2 + 1;
	new_str = malloc(new_len * sizeof(*new_str));
	if (new_str)
	{
		for (; i < len_s1; i++)
			*(new_str + i) = s1[i];
		for (; j < len_s2; j++)
		{
			*(new_str + i) = s2[j];
			i++;
		}
		return (new_str);
	}
	else
		return (NULL);
}

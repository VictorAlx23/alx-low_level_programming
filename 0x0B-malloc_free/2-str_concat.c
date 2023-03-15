#include "main.h"
#include <stdlib.h>
/**
 * str_concat - takes two inputs, adds them for to get size
 * @s1: first input to be added
 * @s2: second input to be added
 * Return: concat of s1 and s2
 */
char *str_concat(char *s1, char *s2)
{
	char *concat;
	int i, j;

	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";
	i = j = 0;
	while (s1[i] != '\0')
		i++;
	while (s2[j] != '\0')
		j++;
	concat = malloc(sizeof(char) * (i + j + 1));
	if (concat == NULL)
		return (NULL);
	i = j = 0;
	while (s1[i] != '\0')
	{
		concat[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		concat[j] = s2[j];
		i++, j++;
	}
	concat[i] = '\0';

	return (concat);
}

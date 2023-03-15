#include "main.h"
#include <stdlib.h>
#include <stdio.h>
/**
 * _strdup - return a function that points to a new string which is a duplicate of the string str
 * @str: char
 * Return: 0
 */
char *_strdup(char *str)
{
	char *new;
	int i, r = 0;

	if (str == NULL)
	{
		return(NULL);
	}
	i = 0;

	while(str[i] != '\0')
		i++;
	new = malloc (sizeof(char) * (i + 1));
	if (new == NULL)
		return(NULL);

	for (r = 0; str[r]; r++)
		new[r] = str[r];
	return(new);
}

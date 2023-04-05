#include "lists.h"
#include <string.h>
#include <stdlib.h>
/**
 * add_node -  adds a new node at the beginning of a list_t list.
 * @head: double pointer to the list_t list
 * @str: The string to be added to the node
 * Return: he address of the new element, or NULL if it failed
 */
list_t *add_node(list_t **head, const char *str)
{
	list_t *new_node;
	unsigned int str_len = 0;

	new_node = malloc(sizeof(list_t));
	if (new_node == NULL)
	{
		return (NULL);
	}
	new_node->str = strdup(str);
	while (str[str_len] != '\0')
	{
		str_len++;
	}
	new_node->len = str_len;
	new_node->next = *head;
	*head = new_node;
	return (new_node);
}
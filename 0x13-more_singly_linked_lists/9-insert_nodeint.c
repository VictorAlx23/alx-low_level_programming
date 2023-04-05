#include "lists.h"
/**
 * insert_nodeint_at_index - Inserts a node at a given position
 * @head: A pointer to the head of the linked list
 * #idx: The index of the list where the node should be added (starts at 0)
 * @n: The integer to be stores in the new node
 * Return: The address of the new node, or NULL if it fails
 */
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	listint_t *new_node, *current;
	unsigned int i;

	if (head == NULL)
		return (NULL);
	new_node = malloc(sizeof(listint_t));
	if (new_node == NULL)
		return (NULL);
	new_node->n = n;
	if (idx == 0)
	{
		 new_node->next = *head;
        *head = new_node;
        return (new_node);
	}

	current = *head;

	for (i = 0; i < idx - 1 && current != NULL; i++)
		current = current->next;

	if (current == NULL)
	{
		free(new_node);
		return (NULL);
	}
	new_node->next = current->next;
	current->next = new_node;
	return (new_node);
}

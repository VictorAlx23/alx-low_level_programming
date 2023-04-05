#include "lists.h"
/**
 * get_nodeint_at_index - Returns the nth node of a linked list
 * @head: A pointer to the head of a linked list
 * @index: The index of the node to be returned
 * Return: The nth node of a linked list or NULL if it doesn't exist
 */
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	listint_t *current = head;
	unsigned int count = 0;

	while (current != NULL)
	{
		if (count == index)
			return (current);
		count++;
		current = current->next;
	}
	return (NULL);
}

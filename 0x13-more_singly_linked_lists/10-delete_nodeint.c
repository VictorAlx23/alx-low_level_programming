#include "lists.h"
/**
 * delete_nodeint_at_index - Deletes the node at index index of a listint_t linked list.
 * @head: Pointer to the head node of the list.
 * @index: Index of the node to be deleted. Index starts at 0.
 *
 * Return: 1 if the deletion succeeded, -1 if it failed.
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	if (*head == NULL)
		return (-1);

	listint_t *temp = *head;
	if (index == 0) 
	{
        *head = (*head)->next;
        free(temp);
		return (1);
	}
	for (unsigned int i = 0; temp != NULL && i < index - 1; i++)
		temp = temp->next;
	if (temp == NULL || temp->next == NULL)
	    return (-1);

	listint_t *next = temp->next->next;
	free(temp->next);
	temp->next = next;

	return (1);
}

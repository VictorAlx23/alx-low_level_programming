#include "lists.h"
/**
 * sum_listint - Returns the sum of all the data (n) of a linked list
 * @head: A pointer to the head of a linked list
 * Return : The sum of all data (n) of a linked list
 */
int sum_listint(listint_t *head)
{
	int sum = 0;
	listint_t *current = head;

	while (current != NULL)
	{
		sum += current->n;
		current = current->next;
	}
	return (sum);
}

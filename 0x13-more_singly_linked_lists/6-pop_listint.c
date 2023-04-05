#include "lists.h"
/**
 * pop_listint -  deletes the head node of a listint_t linked list, and returns the head node’s data (n).
 * @head: A pointer to the pointer to the head of a linked list
 * Return : The data of the head mode, or 0 if the linked list is empty
 */
int pop_listint(listint_t **head)
{
	int data;
	listint_t *temp;

	if (head == NULL)
		return (0);
	temp = *head;
	*head = (*head)->next;
	data = temp->n;
	free(temp);
	return (data);
}

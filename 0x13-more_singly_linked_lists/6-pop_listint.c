#include "lists.h"
/**
 * pop_listint -  deletes the head node of a listint_t linked list
 * @head: A pointer to the pointer to the head of a linked list
 * Return: The data of the head mode, or 0 if the linked list is empty
 */
int pop_listint(listint_t **head)
{
	int data;
	listint_t *temp;

	if (head == NULL || *head == NULL)
		return (0);
	data = (*head)->n;
	temp = (*head)->next;
	free(*head);
	*head = temp;
	return (data);
}

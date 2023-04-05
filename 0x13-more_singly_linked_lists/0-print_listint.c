#include "lists.h"
/**
 * size_t print_listint -  prints all the elements of a listint_t list.
 * @h: Pointer to the first node of the list
 * Return: Number of nodes
 */
size_t print_listint(const listint_t *h)
{
	size_t count = 0;

	if (h == NULL)
	{
		printf("Error\n");
		return 0;
	}
	while (h != NULL)
	{
		printf("%d\n", h->n);
		count++;
		h = h->next;
	}
	printf("The number of nodes is: %lu\n", count);
	return count;
}

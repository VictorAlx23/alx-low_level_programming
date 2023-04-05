#include "lists.h"
#include <stdlib.h>
#include <stddef.h>
/**
 * list_len - returns the number of elements in a linked list_t list.
 * @h: pointer to the first node in the list
 * Return: The number of nodes in the list
 */
size_t list_len(const list_t *h)
{
	size_t count = 0;

	while (h != NULL)
	{
		count++;
		h = h->next;
	}
	return (count);
}
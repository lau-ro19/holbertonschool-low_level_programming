#include "lists.h"

/**
 * dlistint_len - returns the number of elements in a linked dlistint_t list
 * @h: pointer to the head of the doubly linked list
 *
 * Return: the number of nodes in the list
 */
size_t dlistint_len(const dlistint_t *h)
{
	size_t count = 0;

	/* Iterate through the list until the pointer is NULL */
	while (h != NULL)
	{
		/* Increment the node counter */
		count++;

		/* Move to the next node using the 'next' pointer */
		h = h->next;
	}

	return (count);
}

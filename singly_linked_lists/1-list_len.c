#include <stddef.h>
#include "lists.h"

/**
 * list_len - returns the number of elements in a linked list_t list
 * @h: pointer to the head of the list_t list
 *
 * Return: the number of elements in the list
 */
size_t list_len(const list_t *h)
{
	size_t n = 0;

	/* Iterate through the list until the end (NULL) */
	while (h != NULL)
	{
		/* Increment the counter for each node found */
		n++;

		/* Move the pointer to the next node in the sequence */
		h = h->next;
	}

	/* Return the total count of elements */
	return (n);
}

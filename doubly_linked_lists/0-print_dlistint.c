#include <stdio.h>
#include "lists.h"

/**
 * print_dlistint - prints all the elements of a dlistint_t list
 * @h: pointer to the head of the doubly linked list
 *
 * Return: the number of nodes in the list
 */
size_t print_dlistint(const dlistint_t *h)
{
	size_t count = 0;

	/* Iterate through the list until the pointer is NULL */
	while (h != NULL)
	{
		/* Print the integer value of the current node */
		printf("%d\n", h->n);

		/* Increment the node counter */
		count++;

		/* Move to the next node using the 'next' pointer */
		h = h->next;
	}

	return (count);
}

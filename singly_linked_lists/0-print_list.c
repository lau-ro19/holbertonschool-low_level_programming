#include <stdio.h>
#include "lists.h"

/**
 * print_list - prints all the elements of a list_t list
 * @h: pointer to the head of the list_t list
 *
 * Return: the number of nodes
 */
size_t print_list(const list_t *h)
{
	size_t nodes = 0;

	/* Iterate through the list until the end (NULL) */
	while (h != NULL)
	{
		/* Check if the string is NULL as per requirements */
		if (h->str == NULL)
		{
			printf("[0] (nil)\n");
		}
		else
		{
			/* Print the length and the string content */
			printf("[%u] %s\n", h->len, h->str);
		}

		/* Increment the node counter */
		nodes++;

		/* Move to the next node in the list */
		h = h->next;
	}

	/* Return the total count of nodes found */
	return (nodes);
}

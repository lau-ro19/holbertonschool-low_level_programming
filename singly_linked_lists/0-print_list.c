#include <stdio.h>
#include "lists.h"

/**
 * print_list - prints all the elements of a list_t list
 * @h: pointer to the head of the list
 *
 * Return: the number of nodes in the list
 */
size_t print_list(const list_t *h)
{
	size_t nodes = 0;

	/* Loop through the list until the end (NULL) */
	while (h != NULL)
	{
		/* Check if string is NULL to print (nil) */
		if (h->str == NULL)
		{
			printf("[0] (nil)\n");
		}
		else
		{
			/* Print length and string content */
			printf("[%u] %s\n", h->len, h->str);
		}

		/* Move to the next node and increment counter */
		nodes++;
		h = h->next;
	}

	return (nodes);
}

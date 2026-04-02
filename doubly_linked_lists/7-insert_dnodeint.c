#include <stdlib.h>
#include "lists.h"

/**
 * insert_dnodeint_at_index - inserts a new node at a given position
 * @h: double pointer to the head of the list
 * @idx: index where the new node should be added (starts at 0)
 * @n: integer data for the new node
 *
 * Return: address of the new node, or NULL if it failed
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	dlistint_t *new, *temp = *h;
	unsigned int i = 0;

	if (idx == 0)
		return (add_dnodeint(h, n));

	/* Traverse to find the node BEFORE the target index */
	while (temp != NULL && i < (idx - 1))
	{
		temp = temp->next;
		i++;
	}

	if (temp == NULL)
		return (NULL);

		return (add_dnodeint_end(h, n));

	new = malloc(sizeof(dlistint_t));
	if (new == NULL)
		return (NULL);

	new->n = n;
	/* Set new node's links */
	new->next = temp->next;
	new->prev = temp;

	/* Update neighboring nodes to point to the new node */
	temp->next->prev = new;
	temp->next = new;

	return (new);
}

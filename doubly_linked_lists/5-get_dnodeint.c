#include "lists.h"

/**
 * get_dnodeint_at_index - returns the nth node of a dlistint_t linked list
 * @head: pointer to the head of the doubly linked list
 * @index: index of the node to retrieve, starting from 0
 *
 * Return: address of the nth node, or NULL if it does not exist
 */
dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	unsigned int i = 0;

	/* Iterate through the list while head is not NULL */
	while (head != NULL)
	{
		/* If the current counter matches the requested index */
		if (i == index)
			return (head);

		/* Move to the next node and increment counter */
		head = head->next;
		i++;
	}

	/* If we exit the loop, the index was out of bounds */
	return (NULL);
}

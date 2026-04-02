#include <stdlib.h>
#include "lists.h"

/**
 * add_dnodeint_end - adds a new node at the end of a dlistint_t list
 * @head: double pointer to the head of the list
 * @n: integer to be included in the new node
 *
 * Return: address of the new element, or NULL if it failed
 */
dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
	dlistint_t *new, *last;

	if (head == NULL)
		return (NULL);

	/* Allocate memory for the new node on the Heap */
	new = malloc(sizeof(dlistint_t));
	if (new == NULL)
		return (NULL);

	/* Initialize the new node */
	new->n = n;
	new->next = NULL;

	/* If the list is empty, make the new node the head */
	if (*head == NULL)
	{
		new->prev = NULL;
		*head = new;
		return (new);
	}

	/* Otherwise, traverse to find the last node */
	last = *head;
	while (last->next != NULL)
		last = last->next;

	/* Link the last node and the new node */
	last->next = new;
	new->prev = last;

	return (new);
}

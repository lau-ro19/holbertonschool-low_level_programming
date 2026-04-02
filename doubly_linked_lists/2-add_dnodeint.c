#include <stdlib.h>
#include "lists.h"

/**
 * add_dnodeint - adds a new node at the beginning of a dlistint_t list
 * @head: double pointer to the head of the list
 * @n: integer to be included in the new node
 *
 * Return: address of the new element, or NULL if it failed
 */
dlistint_t *add_dnodeint(dlistint_t **head, const int n)
{
	dlistint_t *new;

	if (head == NULL)
		return (NULL);

	/* Allocate memory for the new node on the Heap */
	new = malloc(sizeof(dlistint_t));
	if (new == NULL)
		return (NULL);

	/* Initialize the new node's data */
	new->n = n;
	new->prev = NULL;

	/* The new node points to the current head as its next */
	new->next = *head;

	/* If the list is not empty, update the old head's prev pointer */
	if (*head != NULL)
		(*head)->prev = new;

	/* Update the head pointer to point to the new node */
	*head = new;

	return (new);
}

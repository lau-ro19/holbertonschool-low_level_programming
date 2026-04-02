#include <stdlib.h>
#include "lists.h"

/**
 * free_dlistint - frees a dlistint_t list
 * @head: pointer to the head of the doubly linked list
 *
 * Return: void
 */
void free_dlistint(dlistint_t *head)
{
	dlistint_t *temp;

	/* Iterate through the list while head is not NULL */
	while (head != NULL)
	{
		/* Save the pointer to the next node before freeing the current one */
		temp = head->next;

		/* Release the memory allocated on the Heap for the current node */
		free(head);

		/* Move the head pointer to the next node (stored in temp) */
		head = temp;
	}
}

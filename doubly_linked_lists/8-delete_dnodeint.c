#include <stdlib.h>
#include "lists.h"

/**
 * delete_dnodeint_at_index - deletes the node at index of a dlistint_t list
 * @head: double pointer to the head of the list
 * @index: index of the node that should be deleted (starts at 0)
 *
 * Return: 1 if it succeeded, -1 if it failed
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *temp = *head;
	unsigned int i = 0;

	if (head == NULL || *head == NULL)
		return (-1);

	/* Traverse to the node at the specified index */
	while (temp != NULL && i < index)
	{
		temp = temp->next;
		i++;
	}

	/* If index is out of range */
	if (temp == NULL)
		return (-1);

	/* If deleting the head node */
	if (temp == *head)
	{
		*head = temp->next;
		if (*head != NULL)
			(*head)->prev = NULL;
	}
	else
	{
		/* Bridge the gap: skip the 'temp' node */
		temp->prev->next = temp->next;

		/* If we are NOT deleting the last node, update the next node's prev */
		if (temp->next != NULL)
			temp->next->prev = temp->prev;
	}

	free(temp);
	return (1);
}

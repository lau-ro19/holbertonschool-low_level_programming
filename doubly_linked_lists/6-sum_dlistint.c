#include "lists.h"

/**
 * sum_dlistint - returns the sum of all the data (n) of a dlistint_t list
 * @head: pointer to the head of the doubly linked list
 *
 * Return: the sum of all data, or 0 if the list is empty
 */
int sum_dlistint(dlistint_t *head)
{
	int sum = 0;

	/* If the list is empty, the loop won't execute and returns 0 */
	while (head != NULL)
	{
		/* Add the current node's integer value to the total */
		sum += head->n;

		/* Move to the next node */
		head = head->next;
	}

	return (sum);
}

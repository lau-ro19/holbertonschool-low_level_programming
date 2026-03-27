#include <stdlib.h>
#include "lists.h"

/**
 * free_list - frees a list_t list
 * @head: pointer to the head of the list_t list
 *
 * Description: This function iterates through the list, frees the
 * duplicated string in each node, and then frees the node itself.
 */
void free_list(list_t *head)
{
	list_t *current_node;

	while (head != NULL)
	{
		/* Store the current node */
		current_node = head;

		/* Move head to the next node before freeing current */
		head = head->next;

		/* Free the string duplicated by strdup */
		free(current_node->str);

		/* Free the structure itself */
		free(current_node);
	}
}

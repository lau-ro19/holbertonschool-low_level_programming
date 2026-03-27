#include <stdlib.h>
#include <string.h>
#include "lists.h"

/**
 * add_node - adds a new node at the beginning of a list_t list
 * @head: double pointer to the list_t list
 * @str: new string to be added in the node
 *
 * Return: the address of the new element, or NULL if it failed
 */
list_t *add_node(list_t **head, const char *str)
{
	list_t *new;
	unsigned int len = 0;

	/* Calculate the length of the string */
	while (str[len])
		len++;

	/* Allocate memory for the new node */
	new = malloc(sizeof(list_t));
	if (new == NULL)
		return (NULL);

	/* Duplicate the string using strdup */
	new->str = strdup(str);
	if (new->str == NULL)
	{
		free(new);
		return (NULL);
	}

	/* Assign values and update pointers */
	new->len = len;
	new->next = (*head);
	(*head) = new;

	return (*head);
}

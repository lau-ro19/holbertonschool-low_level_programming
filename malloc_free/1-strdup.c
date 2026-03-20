#include "main.h"
#include <stdlib.h>

/**
 * create_array - Creates an array of chars and initializes it with a char.
 * @size: The size of the array to be created.
 * @c: The char to initialize the array with.
 *
 * Return: A pointer to the array, or NULL if it fails or size is 0.
 */
char *create_array(unsigned int size, char c)
{
	char *str;
	unsigned int i;


	if (size == 0)
		return (NULL);

	str = malloc(sizeof(char) * size);

	if (str == NULL)
		return (NULL);

	for (i = 0; i < size; i++)
	{
		str[i] = c;
	}

	return (str);
}

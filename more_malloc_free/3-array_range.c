#include "main.h"
#include <stdlib.h>

/**
 * array_range - Creates an array of integers.
 * @min: The starting value (included).
 * @max: The ending value (included).
 *
 * Return: A pointer to the newly created array.
 * If min > max or malloc fails, returns NULL.
 */
int *array_range(int min, int max)
{
	int *ptr;
	int i, size;

	if (min > max)
		return (NULL);

	/* Calcul de la taille : on ajoute 1 pour inclure les deux bornes */
	size = (max - min) + 1;

	ptr = malloc(sizeof(int) * size);

	if (ptr == NULL)
		return (NULL);

	for (i = 0; i < size; i++)
	{
		ptr[i] = min++;
	}

	return (ptr);
}

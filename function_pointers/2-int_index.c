#include "function_pointers.h"
#include <stdlib.h>

/**
 * int_index - Searches for an integer in an array.
 * @array: The array to search in.
 * @size: The number of elements in the array.
 * @cmp: A pointer to the function to be used to compare values.
 *
 * Return: The index of the first element for which cmp doesn't return 0.
 * If no element matches, size <= 0, or array/cmp is NULL, return -1.
 */
int int_index(int *array, int size, int (*cmp)(int))
{
	int i;

	if (array == NULL || cmp == NULL || size <= 0)
		return (-1);

	for (i = 0; i < size; i++)
	{
		if (cmp(array[i]) != 0)
		{
			return (i);
		}
	}

	return (-1);
}

#include "main.h"
#include <stdio.h>

/**
 * print_diagsums - prints the sum of the two diagonals of a square matrix
 * @a: pointer to the first element of the matrix (treated as 1D)
 * @size: the size (width/height) of the matrix
 *
 * Return: void
 */
void print_diagsums(int *a, int size)
{
	int i;
	int sum1 = 0;
	int sum2 = 0;

	for (i = 0; i < size; i++)
	{
		sum1 += a[i * (size + 1)];

		sum2 += a[(i + 1) * (size - 1)];
	}

	printf("%d, %d\n", sum1, sum2);
}

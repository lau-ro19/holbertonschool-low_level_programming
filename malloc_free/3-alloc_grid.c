#include "main.h"
#include <stdlib.h>

/**
 * alloc_grid - returns a pointer to a 2 dimensional array of integers.
 * @width: width of the grid.
 * @height: height of the grid.
 *
 * Return: pointer to 2D array, or NULL on failure or invalid dimensions.
 */
int **alloc_grid(int width, int height)
{
	int **grid;
	int i, j;

	/* 1. Vérification des dimensions */
	if (width <= 0 || height <= 0)
		return (NULL);

	/* 2. Allocation du tableau de pointeurs (les lignes) */
	grid = malloc(sizeof(int *) * height);
	if (grid == NULL)
		return (NULL);

	/* 3. Allocation de chaque ligne (le contenu de la grille) */
	for (i = 0; i < height; i++)
	{
		grid[i] = malloc(sizeof(int) * width);
		if (grid[i] == NULL)
		{
			/* ÉCHEC : On doit libérer tout ce qui a été alloué avant */
			for (j = 0; j < i; j++)
				free(grid[j]);
			free(grid);
			return (NULL);
		}

		/* 4. Initialisation à 0 */
		for (j = 0; j < width; j++)
			grid[i][j] = 0;
	}

	return (grid);
}

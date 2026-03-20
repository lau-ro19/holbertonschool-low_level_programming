#include "main.h"
#include <stdlib.h>

/**
 * free_grid - frees a 2 dimensional grid previously created by alloc_grid.
 * @grid: the 2D array to be freed.
 * @height: the height of the grid.
 *
 * Return: Nothing.
 */
void free_grid(int **grid, int height)
{
	int i;

	/* 1. Sécurité : si la grille est déjà NULL, rien à faire */
	if (grid == NULL || height <= 0)
		return;

	/* 2. On libère chaque ligne individuellement */
	for (i = 0; i < height; i++)
	{
		free(grid[i]);
	}

	/* 3. On libère enfin le tableau de pointeurs principal */
	free(grid);
}

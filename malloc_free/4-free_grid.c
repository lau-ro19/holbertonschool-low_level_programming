#include "main.h"
#include <stdlib.h>

/**
 * free_grid - libère la mémoire d'une grille 2D précédemment allouée.
 * @grid: l'adresse de la grille (double pointeur)
 * @height: la hauteur de la grille (nombre de lignes)
 *
 * Return: Rien.
 */
void free_grid(int **grid, int height)
{
    int i;

    if (grid == NULL)
        return;

    for (i = 0; i < height; i++)
    {
        free(grid[i]);
    }

    free(grid);
}

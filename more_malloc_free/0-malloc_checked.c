#include "main.h"
#include <stdlib.h>

/**
 * malloc_checked - Allocates memory using malloc.
 * @b: The number of bytes to allocate.
 *
 * Return: A pointer to the allocated memory.
 * If malloc fails, the function causes normal process termination
 * with a status value of 98.
 */
void *malloc_checked(unsigned int b)
{
	void *ptr;

	/* 1. On tente l'allocation */
	ptr = malloc(b);

	/* 2. On vérifie immédiatement l'échec */
	if (ptr == NULL)
	{
		/* Si NULL, on quitte avec le code d'erreur 98 */
		exit(98);
	}

	/* 3. On retourne le pointeur (qui est forcément valide ici) */
	return (ptr);
}

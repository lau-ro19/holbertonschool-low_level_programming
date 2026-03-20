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

	/* 1. Sécurité : si la taille est 0, on ne fait rien */
	if (size == 0)
		return (NULL);

	/* 2. Allocation de la mémoire */
	/* On multiplie par sizeof(char) pour être propre, même si c'est 1 octet */
	str = malloc(sizeof(char) * size);

	/* 3. Vérification de l'allocation */
	if (str == NULL)
		return (NULL);

	/* 4. Initialisation du tableau avec le caractère c */
	for (i = 0; i < size; i++)
	{
		str[i] = c;
	}

	/* 5. On retourne le pointeur vers le début de la zone mémoire */
	return (str);
}

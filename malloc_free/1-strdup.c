#include "main.h"
#include <stdlib.h>

/**
 * _strdup - returns a pointer to a newly allocated space in memory,
 * which contains a copy of the string given as a parameter.
 * @str: The string to duplicate.
 *
 * Return: A pointer to the duplicated string, or NULL if str is NULL
 * or if insufficient memory was available.
 */
char *_strdup(char *str)
{
	char *duplicate;
	unsigned int i, len = 0;

	/* 1. Sécurité : si la chaîne est NULL, on s'arrête */
	if (str == NULL)
		return (NULL);

	/* 2. Calculer la taille de la chaîne source */
	while (str[len] != '\0')
		len++;

	/* 3. Allouer la mémoire (taille + 1 pour le '\0') */
	duplicate = malloc(sizeof(char) * (len + 1));

	/* 4. Vérifier si l'allocation a réussi */
	if (duplicate == NULL)
		return (NULL);

	/* 5. Copier la chaîne caractère par caractère */
	for (i = 0; i <= len; i++)
	{
		duplicate[i] = str[i];
	}

	/* 6. Retourner le pointeur vers la nouvelle chaîne */
	return (duplicate);
}

#include "main.h"
#include <stdlib.h>

/**
 * str_concat - Concatenates two strings into a newly allocated space.
 * @s1: The first string.
 * @s2: The second string.
 *
 * Return: Pointer to the new string, or NULL on failure.
 */
char *str_concat(char *s1, char *s2)
{
	char *concat;
	unsigned int len1 = 0, len2 = 0, i, j;

	/* 1. Si NULL est passé, on traite comme une chaîne vide "" */
	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";

	/* 2. Calcul des longueurs */
	while (s1[len1] != '\0')
		len1++;
	while (s2[len2] != '\0')
		len2++;

	/* 3. Allocation (Taille s1 + Taille s2 + 1 pour le caractère nul) */
	concat = malloc(sizeof(char) * (len1 + len2 + 1));

	/* 4. Vérification de l'allocation */
	if (concat == NULL)
		return (NULL);

	/* 5. Copie de s1 */
	for (i = 0; i < len1; i++)
		concat[i] = s1[i];

	/* 6. Copie de s2 à la suite de s1 */
	for (j = 0; j < len2; j++, i++)
		concat[i] = s2[j];

	/* 7. Ajout du caractère nul final */
	concat[i] = '\0';

	return (concat);
}

#include "main.h"
#include <stdlib.h>

/**
 * string_nconcat - Concatenates two strings using n bytes from s2.
 * @s1: First string.
 * @s2: Second string.
 * @n: Number of bytes of s2 to concatenate.
 *
 * Return: Pointer to the newly allocated space, or NULL if failure.
 */
char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	char *concat;
	unsigned int len1 = 0, len2 = 0, i, j;

	/* 1. Traiter NULL comme une chaîne vide */
	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";

	/* 2. Calculer les longueurs */
	while (s1[len1])
		len1++;
	while (s2[len2])
		len2++;

	/* 3. Ajuster n si nécessaire */
	if (n >= len2)
		n = len2;

	/* 4. Allocation (len1 + n + 1 pour le '\0') */
	concat = malloc(sizeof(char) * (len1 + n + 1));
	if (concat == NULL)
		return (NULL);

	/* 5. Copier s1 */
	for (i = 0; i < len1; i++)
		concat[i] = s1[i];

	/* 6. Copier n octets de s2 */
	for (j = 0; j < n; j++, i++)
		concat[i] = s2[j];

	/* 7. Terminaison par le caractère nul */
	concat[i] = '\0';

	return (concat);
}

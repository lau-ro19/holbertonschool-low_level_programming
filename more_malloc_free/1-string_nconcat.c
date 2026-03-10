#include "main.h"
#include <stdlib.h>

/**
 * string_nconcat - concatène s1 et les n premiers octets de s2
 * @s1: première chaîne
 * @s2: deuxième chaîne
 * @n: nombre d'octets de s2 à copier
 *
 * Return: pointeur vers l'espace alloué, ou NULL si échec
 */
char *string_nconcat(char *s1, char *s2, unsigned int n)
{
    char *concat;
    unsigned int len1 = 0, len2 = 0, i, j;

    if (s1 == NULL)
        s1 = "";
    if (s2 == NULL)
        s2 = "";

    while (s1[len1])
        len1++;
    while (s2[len2])
        len2++;

    if (n >= len2)
        n = len2;

    concat = malloc(sizeof(char) * (len1 + n + 1));
    if (concat == NULL)
        return (NULL);

    for (i = 0; i < len1; i++)
        concat[i] = s1[i];

    for (j = 0; j < n; j++, i++)
        concat[i] = s2[j];

    concat[i] = '\0';

    return (concat);
}

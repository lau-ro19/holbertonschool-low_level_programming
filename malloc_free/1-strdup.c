#include "main.h"
#include <stdlib.h>

/**
 * _strdup - renvoie un pointeur vers un nouvel espace mémoire
 * contenant une copie de la chaîne passée en paramètre.
 * @str: la chaîne à copier
 *
 * Return: pointeur vers la copie, ou NULL si str est NULL ou échec malloc
 */
char *_strdup(char *str)
{
    char *copy;
    unsigned int i, len = 0;

    if (str == NULL)
        return (NULL);

    while (str[len] != 0)
        len++;

    copy = malloc(sizeof(char) * (len + 1));

    if (copy == NULL)
        return (NULL);

    for (i = 0; i <= len; i++)
    {
        copy[i] = str[i];
    }

    return (copy);
}

#include "main.h"
#include <stdlib.h>

/**
 * malloc_checked - alloue de la mémoire en utilisant malloc
 * @b: le nombre d'octets à allouer
 *
 * Return: un pointeur vers la mémoire allouée
 * Si malloc échoue, termine le processus avec le statut 98
 */
void *malloc_checked(unsigned int b)
{
    void *ptr;

    ptr = malloc(b);

    if (ptr == NULL)
    {
        exit(98);
    }

    return (ptr);
}

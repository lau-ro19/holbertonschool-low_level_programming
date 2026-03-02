#include "main.h"

/**
 * reset_to_98 - Met à jour la valeur pointée par n à 98.
 * @n: Un pointeur vers un entier.
 *
 * Description: Cette fonction accède à l'adresse mémoire stockée dans n
 * et change la valeur qui s'y trouve.
 */
void reset_to_98(int *n)
{
	*n = 98;
}

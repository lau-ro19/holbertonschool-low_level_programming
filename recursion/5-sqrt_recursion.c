#include "main.h"

/**
 * find_sqrt - Helper function to find the natural square root.
 * @n: The number to find the square root of.
 * @i: The current iterator to test.
 *
 * Return: The square root if found, or -1.
 */
int find_sqrt(int n, int i)
{
	/* Si i*i dépasse n, il n'y a pas de racine naturelle */
	if (i * i > n)
	{
		return (-1);
	}

	/* Si on a trouvé la racine */
	if (i * i == n)
	{
		return (i);
	}

	/* Sinon, on teste le nombre suivant */
	return (find_sqrt(n, i + 1));
}

/**
 * _sqrt_recursion - Returns the natural square root of a number.
 * @n: The number to calculate the square root of.
 *
 * Return: The natural square root, or -1 if it doesn't exist.
 */
int _sqrt_recursion(int n)
{
	/* Cas particulier : racine d'un nombre négatif n'existe pas en int */
	if (n < 0)
	{
		return (-1);
	}

	/* On commence la recherche à partir de 0 */
	return (find_sqrt(n, 0));
}

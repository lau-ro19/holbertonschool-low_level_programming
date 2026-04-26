#include "main.h"

/**
 * factorial - Returns the factorial of a given number.
 * @n: The number to calculate the factorial of.
 *
 * Return: The factorial of n, or -1 if n is lower than 0.
 */
int factorial(int n)
{
	/* Gestion de l'erreur pour les nombres négatifs */
	if (n < 0)
	{
		return (-1);
	}

	/* Cas de base : la factorielle de 0 est 1 */
	if (n == 0)
	{
		return (1);
	}

	/* Appel récursif : n * factorial(n - 1) */
	return (n * factorial(n - 1));
}

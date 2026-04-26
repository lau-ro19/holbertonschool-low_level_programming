#include "main.h"

/**
 * _pow_recursion - Returns the value of x raised to the power of y.
 * @x: The base value.
 * @y: The exponent.
 *
 * Return: x raised to the power of y, or -1 if y is negative.
 */
int _pow_recursion(int x, int y)
{
	/* Si l'exposant est négatif, on retourne une erreur */
	if (y < 0)
	{
		return (-1);
	}

	/* Cas de base : tout nombre à la puissance 0 vaut 1 */
	if (y == 0)
	{
		return (1);
	}

	/* Appel récursif : x * x^(y-1) */
	return (x * _pow_recursion(x, y - 1));
}

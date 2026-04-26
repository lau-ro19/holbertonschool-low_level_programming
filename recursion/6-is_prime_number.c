#include "main.h"

/**
 * check_prime - Checks recursively if n is divisible by i.
 * @n: The number to check.
 * @i: The current divisor to test.
 *
 * Return: 1 if prime, 0 if not.
 */
int check_prime(int n, int i)
{
	/* Si n est divisible par i, ce n'est pas un nombre premier */
	if (n % i == 0)
		return (0);

	/* Si i dépasse la moitié de n, c'est un nombre premier */
	if (i * i > n)
		return (1);

	/* On teste le diviseur suivant */
	return (check_prime(n, i + 1));
}

/**
 * is_prime_number - Returns 1 if n is prime, otherwise 0.
 * @n: The number to check.
 *
 * Return: 1 if prime, 0 if n <= 1 or not prime.
 */
int is_prime_number(int n)
{
	/* Les nombres <= 1 ne sont pas premiers */
	if (n <= 1)
		return (0);

	/* Cas particulier pour 2 et 3 */
	if (n <= 3)
		return (1);

	/* On commence à tester la divisibilité à partir de 2 */
	return (check_prime(n, 2));
}

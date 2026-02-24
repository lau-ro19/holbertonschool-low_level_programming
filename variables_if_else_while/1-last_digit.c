#include <stdlib.h>
#include <time.h>
#include <stdio.h>

/**
 * main - Entrée du programme, génère un nombre et l'analyse
 *
 * Return: Toujours 0 (Succès)
 */
int main(void)
{
	int n;
    int digit;

	srand(time(0));
	n = rand() - RAND_MAX / 2;
	digit = n % 10;

	printf("Last digit of %d is %d ", n, digit);

	if (digit > 5)
	{
		printf("and is greater than 5\n");
	}
	else if (digit == 0)
	{
		printf("and is 0\n");
	}
	else
	{
		printf("and is less than 6 and not 0\n");
	}

	return (0);
}

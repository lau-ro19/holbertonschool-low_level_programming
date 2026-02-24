#include <stdio.h>

/**
 * main - Entrée du programme, génère un nombre et l'analyse
 *
 * Return: Toujours 0 (Succès)
 */

int main(void)
{
	int n;

	for (n = 0; n <= 9; n++)
	{
		putchar(n + '0');

		if (n < 9)
		{
			putchar(',');
			putchar(' ');
		}
	}

	putchar('\n');

	return (0);
}

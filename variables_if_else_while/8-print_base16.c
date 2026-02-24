#include <stdio.h>

/**
 * main - Entrée du programme, génère un nombre et l'analyse
 *
 * Return: Toujours 0 (Succès)
 */

int main(void)
{
	char hex;

	for (hex = '0'; hex <= '9'; hex++)
	{
		putchar(hex);
	}

	for (hex = 'a'; hex <= 'f'; hex++)
	{
		putchar(hex);
	}
	putchar('\n');

	return (0);
}

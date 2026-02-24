#include <stdio.h>

/**
 * main - Entrée du programme, génère un nombre et l'analyse
 *
 * Return: Toujours 0 (Succès)
 */

int main(void)
{
	char low;
	char up;

	for (low = 'a'; low <= 'z'; low++)
	{
		putchar(low);
	}

	for (up = 'A'; up <= 'Z'; up++)
	{
		putchar(up);
	}

	putchar('\n');

	return (0);
}

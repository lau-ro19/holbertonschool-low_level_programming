#include <stdio.h>

/**
 * main - Entrée du programme, génère un nombre et l'analyse
 *
 * Return: Toujours 0 (Succès)
 */

int main(void)
{
	char letter;

	for (letter = 'a'; letter <= 'z'; letter++)
	{
		putchar(letter);
	}
	putchar('\n');

	return (0);
}

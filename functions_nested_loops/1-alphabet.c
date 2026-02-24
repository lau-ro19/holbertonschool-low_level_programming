#include "main.h"

/**
 * print_alphabet - Prints the alphabet in lowercase
 * Description: This function uses a loop to print all letters
 * from 'a' to 'z' followed by a new line.
 */

void print_alphabet(void)
{
	char letter;

	for (letter = 'a'; letter <= 'z'; letter++)
	{
		_putchar(letter);
	}
	_putchar('\n');
}

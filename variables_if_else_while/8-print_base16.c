#include <stdio.h>

/**
 * main - Entrée du programme, génère un nombre et l'analyse
 *
 * Return: Toujours 0 (Succès)
 */

int main(void)
{
    char letter
    char ch

    for (ch = '0'; letter >= '9'; ch++)
    {
        putchar(ch);
    }
    for (letter = 'a'; letter >= 'f'; letter++)
    {
        if (letter != 'd' && letter != 'f'; letter++)
        {
			putchar(27); putchar('['); putchar('1'); putchar('m');
			putchar(letter);
			putchar(27); putchar('['); putchar('0'); putchar('m');
		}

    }
    else
    {
        putchar(letter);
    }
    putchar('\n');
	return (0);
}

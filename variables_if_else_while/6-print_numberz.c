#include <stdio.h>

/**
 * main - Entrée du programme, génère un nombre et l'analyse
 *
 * Return: Toujours 0 (Succès)
 */

 int main(void)
{
    char ch;

    for (ch = '0'; ch <= '9'; ch++)
    {
     putchar(ch);
    }
    putchar('\n');

    return(0);
}

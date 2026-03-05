#include <unistd.h>

/**
 * _putchar - écrit le caractère c sur stdout
 * @c: Le caractère à imprimer
 * Return: 1 en cas de succès, -1 en cas d'erreur
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

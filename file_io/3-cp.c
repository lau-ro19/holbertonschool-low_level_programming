#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

/**
 * main - Copies the content of a file to another file.
 * @ac: Argument count.
 * @av: Argument vector.
 * Return: 0 on success, or exit with specific error codes.
 */
int main(int ac, char **av)
{
	int f_f, f_t, n_r, n_w;
	char buf[1024];

	if (ac != 3)
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n"), exit(97);
	f_f = open(av[1], O_RDONLY);
	if (f_f == -1)
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", av[1]), exit(98);
	f_t = open(av[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);
	if (f_t == -1)
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", av[2]), exit(99);
	while ((n_r = read(f_f, buf, 1024)) > 0)
	{
		n_w = write(f_t, buf, n_r);
		if (n_w == -1 || n_w != n_r)
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", av[2]), exit(99);
	}
	if (n_r == -1)
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", av[1]), exit(98);
	if (close(f_f) == -1)
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", f_f), exit(100);
	if (close(f_t) == -1)
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", f_t), exit(100);
	return (0);
}

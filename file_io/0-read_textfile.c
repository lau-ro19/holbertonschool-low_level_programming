#include "main.h"
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

/**
 * read_textfile - Reads a text file and prints it to POSIX standard output.
 * @filename: A pointer to the name of the file.
 * @letters: The number of letters it should read and print.
 *
 * Return: The actual number of letters it could read and print.
 * 0 if the file cannot be opened or read, if filename is NULL,
 * or if write fails.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int fd;
	ssize_t n_read, n_wrote;
	char *buffer;

	if (filename == NULL)
		return (0);

	/* 1. Allouer de l'espace pour les lettres */
	buffer = malloc(sizeof(char) * letters);
	if (buffer == NULL)
		return (0);

	/* 2. Ouvrir le fichier */
	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		free(buffer);
		return (0);
	}

	/* 3. Lire le fichier */
	n_read = read(fd, buffer, letters);
	if (n_read == -1)
	{
		free(buffer);
		close(fd);
		return (0);
	}

	/* 4. Écrire sur la sortie standard (STDOUT_FILENO) */
	n_wrote = write(STDOUT_FILENO, buffer, n_read);
	if (n_wrote == -1 || n_wrote != n_read)
	{
		free(buffer);
		close(fd);
		return (0);
	}

	/* 5. Nettoyage */
	free(buffer);
	close(fd);

	return (n_wrote);
}

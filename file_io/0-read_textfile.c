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
 * 0 if failure.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int fd;
	ssize_t n_r, n_w;
	char *buffer;

	if (filename == NULL)
		return (0);
	buffer = malloc(sizeof(char) * letters);
	if (buffer == NULL)
		return (0);
	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		free(buffer);
		return (0);
	}
	n_r = read(fd, buffer, letters);
	if (n_r == -1)
	{
		free(buffer);
		close(fd);
		return (0);
	}
	n_w = write(STDOUT_FILENO, buffer, n_r);
	free(buffer);
	close(fd);
	if (n_w == -1 || n_w != n_r)
		return (0);
	return (n_w);
}

#include "main.h"
#include <fcntl.h>
#include <unistd.h>

/**
 * create_file - Creates a file and writes text_content into it.
 * @filename: The name of the file to create.
 * @text_content: A NULL terminated string to write to the file.
 *
 * Return: 1 on success, -1 on failure.
 */
int create_file(const char *filename, char *text_content)
{
	int fd, len = 0, n_wrote;

	if (filename == NULL)
		return (-1);

	/* 1. Calculer la longueur du texte si non NULL */
	if (text_content != NULL)
	{
		while (text_content[len])
			len++;
	}

	/* 2. Ouvrir le fichier avec les flags appropriés */
	/* O_CREAT: crée le fichier s'il n'existe pas */
	/* O_WRONLY: ouverture en écriture seule */
	/* O_TRUNC: si le fichier existe, le vider (tronquer à 0) */
	/* 0600: permissions rw------- */
	fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0600);
	if (fd == -1)
		return (-1);

	/* 3. Écrire le contenu si text_content n'est pas NULL */
	if (text_content != NULL)
	{
		n_wrote = write(fd, text_content, len);
		if (n_wrote == -1 || n_wrote != len)
		{
			close(fd);
			return (-1);
		}
	}

	close(fd);
	return (1);
}

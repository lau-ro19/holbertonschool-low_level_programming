#ifndef MAIN_H
#define MAIN_H

#include <stddef.h>
#include <sys/types.h>

/* --- Prototypes des tâches de File I/O --- */

/* Tâche 0: read_textfile */
ssize_t read_textfile(const char *filename, size_t letters);

/* Tâche 1: create_file */
int create_file(const char *filename, char *text_content);

/* Tâche 2: append_text_to_file */
int append_text_to_file(const char *filename, char *text_content);

/* Tâche 3: cp (Note: cp est un exécutable, la fonction main est dans 3-cp.c) */

/* --- Fonctions Helper (si nécessaire) --- */
int _putchar(char c);

#endif /* MAIN_H */

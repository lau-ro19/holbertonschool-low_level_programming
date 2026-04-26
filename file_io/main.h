#ifndef MAIN_H
#define MAIN_H

#include <stddef.h>
#include <sys/types.h>

/* --- Prototypes --- */

/* Tâche 0 */
ssize_t read_textfile(const char *filename, size_t letters);

/* Tâche 1 */
int create_file(const char *filename, char *text_content);

/* Tâche 2 */
int append_text_to_file(const char *filename, char *text_content);

/* Tâche 3: Program cp */

int _putchar(char c);

#endif /* MAIN_H */

# C - File I/O (Input/Output)

Ce projet porte sur la manipulation de fichiers en langage C à l'aide des appels système (system calls) plutôt que des fonctions de la bibliothèque standard (comme `fopen` ou `fprintf`). L'objectif est d'apprendre à ouvrir, lire, écrire et fermer des fichiers en utilisant les descripteurs de fichiers.

## 📝 Description des fichiers

| Fichier | Description |
| :--- | :--- |
| `0-read_textfile.c` | Lit un fichier texte et l'affiche sur la sortie standard POSIX (`STDOUT_FILENO`). |
| `1-create_file.c` | Crée un fichier avec des permissions spécifiques (`rw-------`) et y écrit du texte. |
| `2-append_text_to_file.c` | Ajoute du texte à la fin d'un fichier existant. |
| `3-cp.c` | Programme qui copie le contenu d'un fichier vers un autre, incluant une gestion d'erreurs rigoureuse. |
| `main.h` | Fichier d'en-tête contenant tous les prototypes des fonctions. |

## 🛠️ Fonctions Système Utilisées

Pour ce projet, les appels système suivants ont été privilégiés :
* **`open`** : Ouvre un fichier et retourne un descripteur de fichier.
* **`read`** : Lit les données depuis un descripteur de fichier vers un buffer.
* **`write`** : Écrit des données depuis un buffer vers un descripteur de fichier.
* **`close`** : Ferme un descripteur de fichier ouvert.

## 🚀 Compilation et Tests

Chaque fichier doit être compilé avec les flags `-Wall -Werror -Wextra -pedantic -std=gnu89`.

Exemple pour la tâche 0 :
```bash
gcc -Wall -pedantic -Werror -Wextra -std=gnu89 0-main.c 0-read_textfile.c -o a
./a

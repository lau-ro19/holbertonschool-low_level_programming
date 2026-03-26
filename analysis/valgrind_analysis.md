Valgrind Memory Analysis Report

1. aliasing_example.c: Use-after-free
Command: valgrind ./aliasing_example

Reported Issue: Invalid read/write of size 4
Error Type: Use-after-free (Accès après libération).

Memory Object: Le bloc d'entiers alloué par malloc dans make_numbers.

Description: Valgrind signale une erreur à la ligne printf(" reading b[2]=%d\n", b[2]);. Bien que le pointeur a ait été libéré, le pointeur b (qui est un alias de a) pointe toujours vers la même adresse.

Lifetime Violation: La durée de vie de l'objet sur le tas (Heap) s'est terminée prématurément par rapport à l'utilisation du pointeur b.

AI Correction
AI Starting Point: "The error occurs because b is uninitialized."
Correction: C'est faux. b est parfaitement initialisé (b = a). L'erreur est une violation de validité temporelle : on accède à une adresse qui appartient désormais au système et non plus au programme.

2. heap_example.c: Memory Leaks
Command: valgrind --leak-check=full ./heap_example

Reported Issue: 6 bytes in 1 blocks are definitely lost
Error Type: Leak due to lost ownership (Perte de propriété).

Memory Object: La chaîne de caractères "Alice\0" allouée pour p->name.

Description: Valgrind indique que de la mémoire allouée à la ligne p->name = (char *)malloc(len + 1); n'est plus accessible.

Lifetime Violation: La fonction person_free_partial libère la structure parente Person *p sans libérer le membre p->name. Une fois le pointeur p libéré, l'adresse de name est perdue sur la pile, rendant le bloc de 6 octets sur le tas orphelin.

3. crash_example.c: Invalid Address
Command: valgrind ./crash_example

Reported Issue: Process terminating with default action of signal 11 (SIGSEGV)
Error Type: NULL pointer dereference.

Memory Object: Pointeur nums.

Description: L'erreur survient lors de nums[0] = 42;. Comme n=0, allocate_numbers a renvoyé NULL. Tenter d'écrire à l'adresse 0x0 provoque un arrêt immédiat par le système d'exploitation.

Summary of Findings
Program	Error Category	Root Cause	Impact
aliasing_example	Use-after-free	Aliasing via b = a	Potential data corruption
heap_example	Memory Leak	Partial free of struct	Memory exhaustion over time
crash_example	Segfault	Unchecked NULL return	Immediate program crash
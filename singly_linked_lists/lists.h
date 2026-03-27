typedef struct list_s
{
    char *str;
    unsigned int len;
    struct list_s *next;
} list_t;

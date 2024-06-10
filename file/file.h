typedef struct LFILE
{
    void *data;
    struct LFILE * next;
} LFILE;

extern int list_parcours(LFILE **List, int (*operation)(LFILE **List, void *data), void *data);

extern int _enfiler (LFILE **f, void * element);
extern int _defiler(LFILE** f);
extern void enfiler(LFILE **f, void *data);
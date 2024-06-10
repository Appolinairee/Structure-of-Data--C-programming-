// typedef struct NTREE
// {
//     void *data;
//     LFILE **f;
// } NTREE;

typedef struct TREE
{
    void *data;
    struct TREE * child1;
    struct TREE * child2;
} TREE;

extern int parcours_largueur(TREE** t, int (*operation)(TREE **f, void *data), void *data);
extern int parcours_profondeur(TREE **t, int (*operation)(TREE **f, void *data), void *data, int type);
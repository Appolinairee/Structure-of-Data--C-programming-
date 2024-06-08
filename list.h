typedef struct Node
{
    void *data;
    struct Node* prev;
    struct Node* next;
} Node;

typedef struct Datas
{
    void *data1;
    void * data2;
} Datas;

extern int tri_bulle(int *t, int len);

extern int list_parcours(Node **List, int (*operation)(Node **List, void *data), void *data);

extern void list_ajouter(Node **List, void *data);

extern void  list_retirer(Node **List, void *data);

extern int insertElementOperation(Node **list, void *data);

extern void insertElement(Node **list, void *data);
extern int listLengthOperation(Node **list, void *l);
extern int removeElementOperation(Node **list, void *data);
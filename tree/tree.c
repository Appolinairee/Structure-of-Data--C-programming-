#include <stdio.h>
#include "../file/file.h"
#include "tree.h"

int parcours_largueur(TREE **t, int (*operation)(TREE **f, void *data), void *data)
{
    TREE **temp = t;
    LFILE **file = (LFILE **)(t);
    int res = 0;

    if (t == 0)
        return 100;
    else if (operation == 0)
        return 200;

    printf("\nadresses f: ");
    *file = (LFILE *)(*t);
    do
    {

        if (operation(temp, data) == 0)
            break;
        res++;
        // printf("%d \n", res);
        enfiler(file, (*temp)->child1);

        // enfiler(file, (*temp)->child2);

        _defiler(file);

        // printf("%d %d ", *file, (*file)->next);

        *temp = (TREE *)(*file);
    } while (*file && res < 3);

    return 0;
}
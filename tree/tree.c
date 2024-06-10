#include <stdio.h>
#include "../file/file.h"
#include "tree.h"

int parcours_largueur(TREE **t, int (*operation)(TREE **f, void *data), void *data)
{
    TREE **temp = t, *c1, child2;
    LFILE *file = 0;
    int res = 0;

    if (t == 0)
        return 100;
    else if (operation == 0)
        return 200;

    do
    {
        // printf("\n%d code", (*temp)->child1);
        enfiler(&file, *t);
        // printf("\n%d code", (*temp)->child1);

        if (operation(temp, data) == 0)
            break;

        res++;
        // printf("\n nouvelle itération 1: %d -- %d \n", (*t)->child1, file->next);

        enfiler(&file, (*temp)->child1);
        // printf("\n nouvelle itération 2: %d -- %d \n", file, file->next);

        enfiler(&file, (*temp)->child2);

        _defiler(&file);

        *temp = (TREE *)(file);
    } while (file && res < 1);

    return 0;
}

int parcours_profondeur(TREE **t, int (*operation)(TREE **t, void *data), void *data, int type)
{

    TREE *child1;
    TREE *child2;

    if (t == 0)
        return 100;
    else if (operation == 0)
        return 200;
    else if (type != -1 && type != 0 && type != 1)
        return 300;

    if (*t)
    {
        child1 = (*t)->child1;
        child2 = (*t)->child2;
    }

    if (child1 == 0 && child2 == 0)
    {
        operation(t, data);
        return;
    }

    if (type == -1)
    {
        operation(t, data);
        if (child1)
            parcours_profondeur(&child1, operation, data, type);
        if (child2)
            parcours_profondeur(&child2, operation, data, type);
    }
    else if (type == 0)
    {
        if (child1)
            parcours_profondeur(&child1, operation, data, type);
        operation(t, data);
        if (child2)
            parcours_profondeur(&child2, operation, data, type);
    }
    else
    {
        if (child1)
            parcours_profondeur(&child1, operation, data, type);
        if (child2)
            parcours_profondeur(&child2, operation, data, type);
        operation(t, data);
    }
}
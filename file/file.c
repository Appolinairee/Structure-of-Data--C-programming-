#include <stdio.h>
#include "file.h"
#include "../tree/tree.h"

int parcours(LFILE **f, int (*operation)(LFILE **f, void *data), void *data)
{
    LFILE **temp = f;

    if (f == 0)
        return 100;
    else if (operation == 0)
        return 200;

    do
    {
        if (operation(temp, data) == 0 || *temp == 0)
            break;

        *temp = (*temp)->next;
    } while (*temp);

    return 0;
}

int _enfiler(LFILE **f, void *element)
{
    if (element == 0)
        return 0;

    if (*f == 0)
    {
        *f = (LFILE *)(element);

        // printf("\n %d --- %d d\n", *f, ((*f)->next));

        (*f)->next = 0;


        return 0;
    }
    else
    {
        if ((*f)->next == 0)
        {
            (*f)->next = (LFILE *)element;
            ((LFILE *)element)->next = 0;
            return 0;
        }

        return 1;
    }
}

void enfiler(LFILE **f, void *data)
{
    parcours(f, _enfiler, data);
}

int _defiler(LFILE **f)
{
    if (*f == 0)
        return 0;

    *f = (*f)->next;
}

int _flength(LFILE **f, void *data)
{
    if (*f == 0)
        return 0;

    (*((int *)data))++;

    return 1;
}

int file_length(LFILE **f)
{
    int res = 0;

    parcours(f, _flength, &res);

    return res;
}
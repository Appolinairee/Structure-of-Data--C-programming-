#include <stdio.h>
#include "file.h"

int parcours(LFILE **f, int (*operation)(LFILE **f, void *data), void *data)
{
    LFILE **temp = f;

    if (f == 0)
        return 100;
    else if (operation == 0)
        return 200;
    printf("%d ", f);

    do
    {
    
        if (operation(temp, data) == 0 || *temp == 0)
            break;
        printf("%d ", *f);

        *temp = (LFILE *)((*temp)->next);
        printf("%d ", *f);

        break;
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
        return 0;
    }
    else
    {
        if ((*f)->next == NULL)
        {
            (*f)->next = (LFILE *)element;
            return 0;
        }

        return 1;
    }
}

void enfiler(LFILE **f, void *data)
{
    printf("%d %d \n", f, *f);
    parcours(f, _enfiler, &data);
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
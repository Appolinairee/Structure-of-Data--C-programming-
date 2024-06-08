#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "bulle.h"

int tri_bulle(int tab[], int len)
{
    int r, temp;
    if (tab == NULL || len == 0)
    {
        return 0;
    }

    for (int i = 0; i < len - 1; i++)
    {
        for (int j = len - 1; j > i; j--)
        {
            if (tab[j] < tab[j - 1])
            {
                temp = tab[j];
                tab[j] = tab[j - 1];
                tab[j - 1] = temp;
            }
        }
    }

    return 1;
}
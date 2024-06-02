#include <stdio.h>
#include "list.h"

int parcours(File **f, int (*operation)(File **f, void *data), void *data)
{
    File **temp = f;

    if (f == 0)
        return 100;
    else if (operation == 0)
        return 200;

    do
    {
        if (operation(temp, data) == 0)
            break;

    } while (*temp && (*temp = (*temp)->next));

    return 0;
}

void _addElement (FILE **f, void *data) {

}

void addElement (FILE **f, void *data) {
    list_parcours(f, _addElement, data);
}


int main () {


}
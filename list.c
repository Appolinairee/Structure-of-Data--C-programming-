#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "list.h"

int parcours(Node **list, int (*operation)(Node **list, void *data), void *data)
{
    Node **temp = list;

    if (list == 0)
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

/*
 * length of list*/

int list_length_operation(Node **elt, void *data)
{
    if (*elt)
        *(int *)data += 1;

    return 1;
}

int list_length(Node **list)
{
    int length = 0;

    Node *tempList = *list;

    parcours(&tempList, list_length_operation, &length);

    return length;
}

/*
 * create and insert element into list
 * insertion au debut de liste
 */
int insert_element_operation(Node **temp, void *data)
{
    Node *newNode = (Node *)data;

    if (*temp == NULL || (*temp)->prev == NULL) // debut de liste
    {
        newNode->next = *temp;
        newNode->prev = NULL;

        if (*temp != NULL)
        {
            (*temp)->prev = newNode;
        }

        *temp = newNode;
    }

    return 0;
}

void insertElement(Node **list, void *data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL)
        exit(0);

    newNode->data = data;

    parcours(list, insert_element_operation, newNode);
}

/*
 * create and insert element into list
 * insertion après element de reference
 */
int insert_element_operation2(Node **temp, void *datas)
{
    Node *newNode = (Node *)(((Datas *)datas)->data1);
    Node *refNode = (Node *)(((Datas *)datas)->data2);

    newNode->prev = NULL;
    newNode->next = NULL;

    if (*temp == NULL)
    {
        *temp = newNode;
    }
    else if (refNode == 0)
    {
        if ((*temp)->next == NULL)
        {
            newNode->prev = *temp;
            (*temp)->next = newNode;

            return 0;
        }

        return 1;
    }
    else if (*temp == refNode)
    {
        newNode->prev = refNode;

        if ((*temp)->next)
        {
            ((*temp)->next)->prev = newNode;
            newNode->next = (*temp)->next;
        }

        (*temp)->next = newNode;
    }

    return 0;
}

void insertElement2(Node **list, void *data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL)
        exit(0);
    newNode->data = data;

    Datas *datas = malloc(sizeof(Datas));
    datas->data1 = newNode;
    datas->data2 = *list;

    parcours(list, insert_element_operation2, datas);
}

/*
 * affichage liste
 */

int display_list_operation(Node **temp, void *data)
{
    if (*temp)
        printf("%d ", *((int *)((*temp)->data)));

    return 1;
}

void display_list(Node **list)
{
    Node *tempList = *list;

    if (tempList)
    {
        printf("Affichage de la liste: ");
    }
    parcours(&tempList, display_list_operation, 0);
    printf("\n");
}

/*
 * retirer un element de la liste (connaissant sa position)
 */

/*
int remove_element_operation(Node **temp, void *datas)
{
    int position = *((int *)((Datas *)datas)->data1);
    int *index = (int *)((Datas *)datas)->data2;

    if (position == *index)
    {
        if(((*temp)->prev == NULL)){
            if((*temp)->next){
                (*temp)->next->prev = NULL;
            }

            *temp = (*temp)->next;
        }
        else if((*temp)->next == NULL){
            ((*temp)->prev)->next = NULL;

        }else{
            ((*temp)->next)->prev = (*temp)->prev;
            ((*temp)->prev)->next = (*temp)->next;
        }

        return 0;
    }

    (*index) += 1;

    return 1;
}

void remove_element(Node **list, int pos)
{
    Node *tempList = *list;

    int position = pos;
    if (position < 0 || position > list_length(list))
        return;

    int index = 0;
    Datas datas;

    memset(&datas, 0, sizeof(Datas));
    datas.data1 = &position;
    datas.data2 = &index;

    parcours(list, remove_element_operation, &datas);
}
*/

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

// int main()
// {
//     Node *list = NULL;
//     int data[] = {0, 3, 4, 6, 8};

//     insertElement2(&list, data);
//     insertElement2(&list, data + 1);
//     insertElement2(&list, data + 2);

//     display_list(&list);

//     printf("\nTaille: %d\n", list_length(&list));
// }
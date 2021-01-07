#include <stdio.h>
#include <stdlib.h>
#include "linklist.h"

void PrintList(LinkList L)
{
    Node* p = L->next;
    printf("The LinkList is: ");
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
}
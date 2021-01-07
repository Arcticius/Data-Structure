#include <stdio.h>
#include <stdlib.h>
#include "linklist.h"

void CreateFromHead(LinkList L)
{
    Node* s;
    char c;
    int flag = 1;

    printf("Enter the data(end with $): ");
    while (flag)
    {
        c = getchar();

        if (c == ' ')
            continue;
        else if (c != '$')
        {
            s = (Node*)malloc(sizeof(Node));
            s->data = c;
            s->next = L->next;
            L->next = s;
        }
        else
            flag = 0;
    }
}

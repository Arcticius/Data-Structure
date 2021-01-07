#include <stdio.h>
#include <stdlib.h>
#include "linklist.h"

void CreateFromTail(LinkList L)
{
    Node* p, * q;
    char c;
    int flag = 1;

    p = L;

    printf("Enter the data(end with $): ");
    while (flag)
    {
        c = getchar();
        if (c == ' '||c == '\n')
            continue;
        else if (c != '$')
        {
            q = (Node*)malloc(sizeof(Node));
            q->data = c - '0';
            p->next = q;
            p = q;
        }
        else
        {
            flag = 0;
            p->next = NULL;
        }
    }
}

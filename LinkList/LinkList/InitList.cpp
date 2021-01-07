#include <stdio.h>
#include <stdlib.h>
#include "linklist.h"

void InitList(LinkList& L)
{
    L = (LinkList)malloc(sizeof(Node));
    L->data = 0;
    L->next = NULL;
    printf("Initialized successfully\n");
}

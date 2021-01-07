#include <stdio.h>
#include <stdlib.h>
#include "linklist.h"

int InsList(LinkList L, int i, ElemType e)
{
	Node* pre, * s;
	int k;

	if (i <= 0)
		return ERROR;

	pre = L; k = 0;

	while (pre != NULL && k < i - 1)
	{
		pre = pre->next;
		k++;
	}

	if (pre == NULL)
	{
		printf("Invalid location!\n");
		return ERROR;
	}

	s = (Node*)malloc(sizeof(Node));
	s->data = e; s->next = pre->next;
	pre->next = s;
	return OK;
}
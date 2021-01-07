#include <stdio.h>
#include <stdlib.h>
#include "linklist.h"

int DelList(LinkList L, int i, ElemType* e)
{
	Node* pre, * r;
	int k;

	if (i <= 0)
		return ERROR;

	pre = L; k = 0;
	while (pre!= NULL && k < i - 1)
	{
		pre = pre->next;
		k++;
	}
	if (pre == NULL)
	{
		printf("Invalid location!\n");
		return ERROR;
	}

	r = pre->next;
	pre->next = r->next;
	*e = r->data;
	free(r);

	return OK;
}
#include <stdio.h>
#include <stdlib.h>
#include "linklist.h"

Node* Get(LinkList L, int i)
{
	int j;
	Node* p;

	if (i <= 0)
		return NULL;
	p = L; j = 0;

	while ((p->next != NULL) && (j < i))
	{
		p = p->next;
		j++;
	}

	if (i == j)
		return p;
	else
		return NULL;
}
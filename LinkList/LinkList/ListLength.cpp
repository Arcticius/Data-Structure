#include <stdio.h>
#include <stdlib.h>
#include "linklist.h"

int ListLength(LinkList L)
{
	Node* p; int length;
	p = L->next; length = 0;

	while (p != NULL)
	{
		p = p->next;
		length++;
	}
	return length;
}
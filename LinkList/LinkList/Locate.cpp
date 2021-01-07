#include <stdio.h>
#include <stdlib.h>
#include "linklist.h"

Node* Locate(LinkList L, ElemType key)
{
	Node* p;
	p = L->next;
	
	while (p != NULL)
		if (p->data != ('0'+ key))
			p = p->next;
		else
			break;
	return p;
}
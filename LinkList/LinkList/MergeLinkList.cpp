#include <stdio.h>
#include <stdlib.h>
#include "linklist.h"

LinkList MergeLinkList(LinkList LA, LinkList LB)
{
	Node* pa, * pb, *r;
	LinkList LC; InitList(LC);

	pa = LA->next; pb = LB->next;

	r = LC;
	while (pa != NULL && pb != NULL)
	{
		if (pa->data <= pb->data)
		{
			r->next = pa;
			r = pa;
			pa = pa->next;
		}
		else
		{
			r->next = pb;
			r = pb;
			pb = pb->next;
		}
	}

	if (pa)
		r->next = pa;
	else
		r->next = pb;

	return LC;
}
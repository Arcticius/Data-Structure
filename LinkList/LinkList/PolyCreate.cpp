#include <stdio.h>
#include <stdlib.h>
#include "polynomial.h"

Polylist PolyCreate()
{
	Polynode* head, * rear, * s;
	int c, e;

	head = (Polynode*)malloc(sizeof(Polynode));
	rear = head;

	scanf_s("%d,%d", &c, &e);
	while (c != 0)
	{
		s = (Polynode*)malloc(sizeof(Polynode));
		s->coef = c;
		s->exp = e;
		rear->next = s;
		rear = s;
		scanf_s("%d,%d", &c, &e);
	}
	rear->next = NULL;

	return head;
}
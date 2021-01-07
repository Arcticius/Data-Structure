#include <stdio.h>
#include <stdlib.h>
#include "polynomial.h"

void PolyAdd(Polylist polya, Polylist polyb)
{
	Polynode* p, * q, * tail, * temp;
	int sum;

	p = polya->next;
	q = polyb->next;
	tail = polya;

	while (p != NULL && q != NULL)
	{
		if (p->exp < q->exp)
		{
			tail->next = p;
			tail = p;
			p = p->next;
		}
		else if (p->exp == q->exp)
		{
			sum = p->coef + q->coef;
			if (sum != 0)
			{
				p->coef = sum;
				tail->next = p;
				tail = p;
				p = p->next; 
				temp = q; q = q->next; free(temp);
			}
			else
			{
				temp = p; p = p->next; free(temp);
				temp = q; q = q->next; free(temp);
			}
		}
		else
		{
			tail->next = q;
			tail = q;
			q = q->next;
		}
	}

	if (p != NULL)
		tail->next = p;
	else
		tail->next = q;
}
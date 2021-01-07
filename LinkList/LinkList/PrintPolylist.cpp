#include <stdio.h>
#include <stdlib.h>
#include "polynomial.h"

void PrintPolylist(Polylist P)
{
	P = P->next;
	while (P != NULL)
	{
		printf("%d,%d ", P->coef, P->exp);
		P = P->next;
	}
	printf("\n");
}
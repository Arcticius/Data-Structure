#include <stdio.h>
#include <stdlib.h>
#include "tsmatrix.h"

void TransposeTSMatrix(TSMatrix A, TSMatrix* B)
{
	int i, j, k;
	B->m = A.n; B->n = A.m; B->len = A.len;

	if (B->len > 0)
	{
		j = 1;
		for(k=1;k<=A.n;k++)
			for(i=1;i<=A.len;i++)
				if (A.data[i].col == k)
				{
					B->data[j].row = A.data[i].col;
					B->data[j].col = A.data[i].row;
					B->data[j].e = A.data[i].e;
					j++;
				}
	}
}
#include <stdio.h>
#include <stdlib.h>
#include "tsmatrix.h"

void CreateTSMatrix(TSMatrix* A)
{
	int row, col, e;
	int i = 1;

	printf("Enter the element of TripleMatrix(row, col, data), which ends with 0\n");
	while (true)
	{
		scanf_s("%d %d %d", &row, &col, &e);
		if (row == 0)
			break;
		else
		{
			A->data[i].row = row;
			A->data[i].col = col;
			A->data[i].e = e;

			A->len++; A->m++; A->n++;
			i++;
		}
	}

}
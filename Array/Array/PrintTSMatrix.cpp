#include <stdio.h>
#include <stdlib.h>
#include "tsmatrix.h"

void PrintTSMatrix(TSMatrix A)
{
	int i;

	printf("The Triple Matrix is: (row col data)\n");
	for (i = 0; i < A.len; i++)
		printf("%d %d %d\n", A.data[i + 1].row, A.data[i + 1].col, A.data[i + 1].e);
}
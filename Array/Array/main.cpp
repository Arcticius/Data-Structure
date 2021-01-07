#include <stdio.h>
#include <stdlib.h>
#include "tsmatrix.h"

int main()
{
	TSMatrix A, B;
	InitTSMatrix(&A); InitTSMatrix(&B);
	CreateTSMatrix(&A);

	FastTransposeTSMatrix(A, &B);
	
	printf("After Transposing: \n");
	PrintTSMatrix(B);

	return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include "tsmatrix.h"

void InitTSMatrix(TSMatrix* A)
{
	A->len = A->m = A->n = 0;
}
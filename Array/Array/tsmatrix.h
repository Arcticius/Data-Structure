#pragma once
#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 1000

typedef int ElemType;
typedef struct
{
	int row, col;
	ElemType e;
}Triple;
typedef struct
{
	Triple data[MAXSIZE + 1];
	int m, n, len;
}TSMatrix;

void InitTSMatrix(TSMatrix* A);
void CreateTSMatrix(TSMatrix* A);
void PrintTSMatrix(TSMatrix A);
void TransposeTSMatrix(TSMatrix A, TSMatrix* B);
void FastTransposeTSMatrix(TSMatrix A, TSMatrix* B);
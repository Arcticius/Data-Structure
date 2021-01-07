#pragma once
#include <stdio.h>
#include <stdlib.h>
#define OK 1
#define ERROR 0

typedef struct Polynode
{
	int coef;
	int exp;
	struct Polynode* next;
}Polynode, * Polylist;

Polylist PolyCreate();
void PrintPolylist(Polylist P);
void PolyAdd(Polylist polya, Polylist polyb);
void PolyMultiply(Polylist &polya, Polylist polyb);

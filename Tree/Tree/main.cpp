#include <stdio.h>
#include <stdlib.h>
#include "binarytree.h"

int depth = 0;

int main()
{
	BiTree bt;

	printf("Enter the elements of the Tree:(use '.' for NULL Nodes) ");
	CreateBiTree(&bt);

	PrintTree(bt, 1);

	return 0;
}
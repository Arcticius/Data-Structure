#include <stdio.h>
#include <stdlib.h>
#include "binarytree.h"

void PrintTree(BiTree bt, int nLayer)
{
	if (bt == NULL) return;

	PrintTree(bt->RChild, nLayer + 1);
	for (int i = 0; i < nLayer; i++)
		printf("	");
	printf("%c\n", bt->data);
	PrintTree(bt->LChild, nLayer + 1);
}
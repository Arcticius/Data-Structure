#include <stdio.h>
#include <stdlib.h>
#include "binarytree.h"

void CreateBiTree(BiTree* bt)
{
	char ch;
	ch = getchar();

	if (ch == '.')
		*bt = NULL;
	else
	{
		*bt = (BiTree)malloc(sizeof(BiTNode));
		(*bt)->data = ch;
		CreateBiTree(&((*bt)->LChild));
		CreateBiTree(&((*bt)->RChild));
	}
}
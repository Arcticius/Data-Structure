#include <stdio.h>
#include <stdlib.h>
#include "binarytree.h"

void InOrder(BiTree root)
{
	if (root != NULL)
	{
		InOrder(root->LChild);
		printf("%c ", root->data);
		InOrder(root->RChild);
	}
}
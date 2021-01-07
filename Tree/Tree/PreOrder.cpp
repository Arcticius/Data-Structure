#include <stdio.h>
#include <stdlib.h>
#include "binarytree.h"

void PreOrder(BiTree root)
{
	if (root != NULL)
	{
		printf("%c ", root->data);
		PreOrder(root->LChild);
		PreOrder(root->RChild);
	}
}
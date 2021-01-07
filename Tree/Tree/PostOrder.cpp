#include <stdio.h>
#include <stdlib.h>
#include "binarytree.h"

void PostOrder(BiTree root)
{
	if (root != NULL)
	{
		PostOrder(root->LChild);
		PostOrder(root->RChild);
		printf("%c ", root->data);
	}
}
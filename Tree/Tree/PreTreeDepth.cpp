#include <stdio.h>
#include <stdlib.h>
#include "binarytree.h"

extern int depth;

void PreTreeDepth(BiTree bt, int h)
{
	if (bt != NULL)
	{
		if (h > depth)
			depth = h;
		PreTreeDepth(bt->LChild, h + 1);
		PreTreeDepth(bt->RChild, h + 1);
	}
}
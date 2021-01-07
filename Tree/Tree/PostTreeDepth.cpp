#include <stdio.h>
#include <stdlib.h>
#include "binarytree.h"

int PostTreeDepth(BiTree bt)
{
	int hl, hr, max;

	if (bt != NULL)
	{
		hl = PostTreeDepth(bt->LChild);
		hr = PostTreeDepth(bt->RChild);
		max = hl > hr ? hl : hr;
		return max + 1;
	}
	else
		return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include "binarytree.h"

/*
extern int counter;

int LeafCount(BiTree root)
{
	if (root != NULL)
	{
		LeafCount(root->LChild);
		LeafCount(root->RChild);
		if (root->LChild == NULL && root->RChild == NULL)
			counter++;
	}
	return 1;
}
*/

int LeafCount(BiTree root)
{
	int leafcounter;

	if (root == NULL)
		leafcounter = 0;
	else if (root->LChild == NULL && root->RChild == NULL)
		leafcounter = 1;
	else
		leafcounter = LeafCount(root->LChild) + LeafCount(root->RChild);

	return leafcounter;
}

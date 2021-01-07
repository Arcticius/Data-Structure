#pragma once
#include <stdio.h>
#include <stdlib.h>

typedef char ElemType;

typedef struct Node
{
	ElemType data;
	struct Node* LChild;
	struct Node* RChild;
}BiTNode, * BiTree;

void CreateBiTree(BiTree* bt);
void PreOrder(BiTree root);
void InOrder(BiTree root);
void PostOrder(BiTree root);
int LeafCount(BiTree root);
int PostTreeDepth(BiTree root);
void PreTreeDepth(BiTree root, int h);
void PrintTree(BiTree bt, int nLayer);
void NonRecursionInOrder(BiTree root);
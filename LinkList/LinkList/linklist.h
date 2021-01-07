#pragma once
#include <stdio.h>
#include <stdlib.h>
#define OK 1
#define ERROR 0
typedef int ElemType;
typedef struct Node
{
    ElemType data;
    struct Node* next;
}Node, * LinkList;

void InitList(LinkList& L);
void CreateFromHead(LinkList L);
void CreateFromTail(LinkList L);
void PrintList(LinkList L);
Node* Get(LinkList L, int i);
Node* Locate(LinkList L, ElemType key);
int ListLength(LinkList L);
int InsList(LinkList L, int i, ElemType e);
int DelList(LinkList L, int i, ElemType *e);
LinkList MergeLinkList(LinkList LA, LinkList LB);
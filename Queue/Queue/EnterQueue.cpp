#include <stdio.h>
#include <stdlib.h>
#include "linkqueue.h"
#include "seqqueue.h"

int EnterQueue(LinkQueue* Q, QueueElemType x)
{
	LinkQueueNode* NewNode;
	NewNode = (LinkQueueNode*)malloc(sizeof(LinkQueueNode));
	if (NewNode != NULL)
	{
		NewNode->data = x;
		NewNode->next = NULL;
		Q->rear->next = NewNode;
		Q->rear = NewNode;
		return TRUE;
	}
	else return FALSE;
}

int EnterQueue(SeqQueue* Q, QueueElemType x)
{
	if ((Q->rear + 1) % MAXSIZE == Q->front)
		return FALSE;
	Q->elem[Q->rear] = x;
	Q->rear = (Q->rear + 1) % MAXSIZE;
	return TRUE;
}
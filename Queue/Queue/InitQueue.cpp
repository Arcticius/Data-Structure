#include <stdio.h>
#include <stdlib.h>
#include "linkqueue.h"
#include "seqqueue.h"

int InitQueue(LinkQueue* Q)
{
	Q->front = (LinkQueueNode*)malloc(sizeof(LinkQueueNode));
	if (Q->front != NULL)
	{
		Q->rear = Q->front;
		Q->front->next = NULL;
		return TRUE;
	}
	else return FALSE;
}

void InitQueue(SeqQueue* Q)
{
	Q->front = Q->rear = 0;
}
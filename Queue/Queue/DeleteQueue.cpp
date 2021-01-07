#include <stdio.h>
#include <stdlib.h>
#include "linkqueue.h"
#include "seqqueue.h"

int DeleteQueue(LinkQueue* Q, QueueElemType* x)
{
	LinkQueueNode* p;
	if (Q->front == Q->rear)
		return FALSE;

	p = Q->front->next;
	Q->front->next = p->next;

	if (Q->rear == p)
		Q->rear = Q->front;

	*x = p->data;
	free(p);
	return TRUE;
}

int DeleteQueue(SeqQueue* Q, QueueElemType* x)
{
	if (Q->front == Q->rear)
		return FALSE;
	*x = Q->elem[Q->front];
	Q->front = (Q->front + 1) % MAXSIZE;
	return TRUE;
}
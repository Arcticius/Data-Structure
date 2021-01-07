#pragma once
#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0

typedef int QueueElemType;
typedef struct Node
{
	QueueElemType data;
	struct Node* next;
}LinkQueueNode;
typedef struct
{
	LinkQueueNode* front;
	LinkQueueNode* rear;
}LinkQueue;

int InitQueue(LinkQueue* Q);
int EnterQueue(LinkQueue* Q, QueueElemType x);
int DeleteQueue(LinkQueue* Q, QueueElemType* x);
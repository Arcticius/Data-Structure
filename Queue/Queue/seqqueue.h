#pragma once
#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0
#define MAXSIZE 50

typedef int QueueElemType;
typedef struct
{
	QueueElemType elem[MAXSIZE];
	int front;
	int rear;
}SeqQueue;

void InitQueue(SeqQueue* Q);
int EnterQueue(SeqQueue* Q, QueueElemType x);
int DeleteQueue(SeqQueue* Q, QueueElemType* x);

void PascalTriangle(int n);

void SeeDoctor();


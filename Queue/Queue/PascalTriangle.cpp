#include <stdio.h>
#include <stdlib.h>
#include "seqqueue.h"

/*�㷨˼�룺
��ӡ��������Σ�ÿһ�еĵ�һ��Ԫ�غ����һ��Ԫ�ؾ�Ϊ1������λ���ϵ�����������һ������֮���ڵ���������֮��.
��ˣ���i���ϵ�Ԫ��Ҫ�ɵ�i-1���е�Ԫ��������. 
����ѭ������Q����ѭ�����������δ�ŵ�i-1���ϵ�Ԫ�أ�Ȼ��������Ӳ���ӡ��ͬʱ���ɵ�i��Ԫ�ز����.
���ɵ�i�У�i>1��i��Ԫ��aj��j��[1,i]���岽�����£�
��	��i�е�һ��Ԫ��1���
��	ѭ��i-2�Σ����õ�i-1��Ԫ�ؼ����i���м�i-2��Ԫ�ص�ֵ����ʽΪ
			aj=elem[front]+elem[(front+1)%MAXSIZE],j��[2,i-1]
	������Ϻ�aj��ӣ�ͬʱelem[front]����.
��	��i-1�����һ��Ԫ��1����
��	��i�����һ��Ԫ��1���
*/

void PascalTriangle(int n) //��ӡn���������
{
	SeqQueue Q; InitQueue(&Q);
	int i, j, temp;

	EnterQueue(&Q, 1); //��һ��Ԫ�����
	
	for (i = 2; i <= n; i++) //������i��Ԫ�ز���ӣ�ͬʱ��ӡ��i-1��Ԫ��
	{
		EnterQueue(&Q, 1); //��i�е�һ��Ԫ�����

		for (j = 1; j <= i - 2; j++) //���õ�i-1��Ԫ�ز�����i���м�i-2��Ԫ�ز����
		{
			DeleteQueue(&Q, &temp);
			printf("%d	", temp); //��ӡ��i-1��Ԫ��
			temp = temp + Q.elem[Q.front]; //���õ�i-1��Ԫ�ز�����i��Ԫ��
			EnterQueue(&Q, temp);
		}

		DeleteQueue(&Q, &temp);
		printf("%d\n", temp); //��ӡ��i-1�����һ��Ԫ��

		EnterQueue(&Q, 1); //��i�����һ��Ԫ�����
	}

	while (!(Q.front == Q.rear)) //��ӡ���һ��Ԫ��
	{
		DeleteQueue(&Q, &temp);
		printf("%d	", temp);
	}
}
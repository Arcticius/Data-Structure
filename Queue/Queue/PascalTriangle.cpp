#include <stdio.h>
#include <stdlib.h>
#include "seqqueue.h"

/*算法思想：
打印杨辉三角形，每一行的第一个元素和最后一个元素均为1，其他位置上的数字是其上一行中与之相邻的两个整数之和.
因此，第i行上的元素要由第i-1行中的元素来生成. 
创建循环队列Q，在循环队列中依次存放第i-1行上的元素，然后逐个出队并打印，同时生成第i行元素并入队.
生成第i行（i>1）i个元素aj，j∈[1,i]具体步骤如下：
①	第i行第一个元素1入队
②	循环i-2次，利用第i-1行元素计算第i行中间i-2个元素的值，公式为
			aj=elem[front]+elem[(front+1)%MAXSIZE],j∈[2,i-1]
	计算完毕后aj入队，同时elem[front]出队.
③	第i-1行最后一个元素1出队
④	第i行最后一个元素1入队
*/

void PascalTriangle(int n) //打印n行杨辉三角
{
	SeqQueue Q; InitQueue(&Q);
	int i, j, temp;

	EnterQueue(&Q, 1); //第一行元素入队
	
	for (i = 2; i <= n; i++) //产生第i行元素并入队，同时打印第i-1行元素
	{
		EnterQueue(&Q, 1); //第i行第一个元素入队

		for (j = 1; j <= i - 2; j++) //利用第i-1行元素产生第i行中间i-2个元素并入队
		{
			DeleteQueue(&Q, &temp);
			printf("%d	", temp); //打印第i-1行元素
			temp = temp + Q.elem[Q.front]; //利用第i-1行元素产生第i行元素
			EnterQueue(&Q, temp);
		}

		DeleteQueue(&Q, &temp);
		printf("%d\n", temp); //打印第i-1行最后一个元素

		EnterQueue(&Q, 1); //第i行最后一个元素入队
	}

	while (!(Q.front == Q.rear)) //打印最后一行元素
	{
		DeleteQueue(&Q, &temp);
		printf("%d	", temp);
	}
}
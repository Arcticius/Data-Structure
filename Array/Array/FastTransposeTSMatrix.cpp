#include <stdio.h>
#include <stdlib.h>
#include "tsmatrix.h"

/*算法思想：
一次定位快速转置法： 仅对被转置矩阵的三元组表A扫描一次，就使A中所有非零元的三元组“一次定位”
直接放到三元组表B的正确位置上. 需预先计算：
①.	待转置矩阵三元组表A每一列中非零元素的总个数，即转置后三元组表B的每一行中非零元素的总个数.
②.	待转置矩阵每一列中第一个非零元素在三元组表B中的正确位置，即转置后矩阵每一行中第一个非零元
素在三元组表B中的正确位置.

为此，设置两个数组num[]和position[]，其中num[col]用来存放三元组表A第col列中非零元素的总个数，
position[col]用来存放转置前三元组表A中第col列（转置后三元组表B中第col行）中第一个非零元素在
三元组表B中的存储位置（下标值）.

num[col]的计算方法是，将三元组表A扫描一遍，对于其中列号为col的元素，给相应的num数值中下标为
col的元素加1.
position[col]的计算方法如下：
①.	position[1]=1，表示三元组表A中列值为1的第一个非零元素在三元组表B中的下标值.
②.	position[col]=position[col-1]+num[col-1]，其中2<=col<=A.n

*/

void FastTransposeTSMatrix(TSMatrix A, TSMatrix* B)
{
	int col, t, p, q;
	int num[MAXSIZE], position[MAXSIZE];

	B->len = A.len; B->n = A.m; B->m = A.n;

	if (B->len)
	{
		for (col = 1; col <= A.n; col++) //初始化num[]数组
			num[col] = 0;
		for (t = 1; t <= A.len; t++) //采取数组下标计数法计算每一列的非零元素个数
			num[A.data[t].col]++;
		
		position[1] = 1;

		for (col = 2; col <= A.n; col++) //求col列中第一个非零元素在B.data[]中的正确位置
			position[col] = position[col - 1] + num[col - 1];

		for (p = 1; p <= A.len; p++) //将被转置的矩阵的三元组表A从头到尾扫描一次，实现转置
		{
			col = A.data[p].col; q = position[col];
			B->data[q].row = A.data[p].col; //行列互换，元素赋值
			B->data[q].col = A.data[p].row;
			B->data[q].e = A.data[p].e;
			position[col]++; //position[col]加1，指向下一个列号为col的非零元素在三元组表B中存放的位置
		}
	}
}
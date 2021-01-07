#include <stdio.h>
#include <stdlib.h>
#include "tsmatrix.h"

/*�㷨˼�룺
һ�ζ�λ����ת�÷��� ���Ա�ת�þ������Ԫ���Aɨ��һ�Σ���ʹA�����з���Ԫ����Ԫ�顰һ�ζ�λ��
ֱ�ӷŵ���Ԫ���B����ȷλ����. ��Ԥ�ȼ��㣺
��.	��ת�þ�����Ԫ���Aÿһ���з���Ԫ�ص��ܸ�������ת�ú���Ԫ���B��ÿһ���з���Ԫ�ص��ܸ���.
��.	��ת�þ���ÿһ���е�һ������Ԫ������Ԫ���B�е���ȷλ�ã���ת�ú����ÿһ���е�һ������Ԫ
������Ԫ���B�е���ȷλ��.

Ϊ�ˣ�������������num[]��position[]������num[col]���������Ԫ���A��col���з���Ԫ�ص��ܸ�����
position[col]�������ת��ǰ��Ԫ���A�е�col�У�ת�ú���Ԫ���B�е�col�У��е�һ������Ԫ����
��Ԫ���B�еĴ洢λ�ã��±�ֵ��.

num[col]�ļ��㷽���ǣ�����Ԫ���Aɨ��һ�飬���������к�Ϊcol��Ԫ�أ�����Ӧ��num��ֵ���±�Ϊ
col��Ԫ�ؼ�1.
position[col]�ļ��㷽�����£�
��.	position[1]=1����ʾ��Ԫ���A����ֵΪ1�ĵ�һ������Ԫ������Ԫ���B�е��±�ֵ.
��.	position[col]=position[col-1]+num[col-1]������2<=col<=A.n

*/

void FastTransposeTSMatrix(TSMatrix A, TSMatrix* B)
{
	int col, t, p, q;
	int num[MAXSIZE], position[MAXSIZE];

	B->len = A.len; B->n = A.m; B->m = A.n;

	if (B->len)
	{
		for (col = 1; col <= A.n; col++) //��ʼ��num[]����
			num[col] = 0;
		for (t = 1; t <= A.len; t++) //��ȡ�����±����������ÿһ�еķ���Ԫ�ظ���
			num[A.data[t].col]++;
		
		position[1] = 1;

		for (col = 2; col <= A.n; col++) //��col���е�һ������Ԫ����B.data[]�е���ȷλ��
			position[col] = position[col - 1] + num[col - 1];

		for (p = 1; p <= A.len; p++) //����ת�õľ������Ԫ���A��ͷ��βɨ��һ�Σ�ʵ��ת��
		{
			col = A.data[p].col; q = position[col];
			B->data[q].row = A.data[p].col; //���л�����Ԫ�ظ�ֵ
			B->data[q].col = A.data[p].row;
			B->data[q].e = A.data[p].e;
			position[col]++; //position[col]��1��ָ����һ���к�Ϊcol�ķ���Ԫ������Ԫ���B�д�ŵ�λ��
		}
	}
}
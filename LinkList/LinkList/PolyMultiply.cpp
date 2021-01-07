#include <stdio.h>
#include <stdlib.h>
#include "polynomial.h"

/*�㷨˼�룺
������ʽ��a1,a2,...,am������b1,b2,...,bn����ˣ���ʽΪ
		��(i=1...m)��(j=1...n)ai*bj
��ˣ�������ָ��p,temp. temp�����δ��a1...am��pʼ��ָ��temp����һ���.
����ָ��r�����ڴ�Ŧ�ai*bj������β�巨���ν���m������ai*bj����ʽ��ͷ���Ϊpolya��ÿ������ʽ����n�.
������ʱ����ʽpolyc����ֵΪ�ա����ν�polya��polyc���m�Σ����ռ��õ�����ʽa*b.
*/


void PolyMultiply(Polylist &polya, Polylist polyb)
{
	Polylist polyc = (Polynode*)malloc(sizeof(Polynode)); //��������
	Polynode* p, * q, * temp;
	Polynode* s, * rear;

	p = polya->next; //��ʼ������
	polyc->coef = -1; polyc->exp = -1; polyc->next = NULL;

	while (p != NULL) //����polya
	{
		temp = p; p = p->next; //��p��ָ��㸳��temp�����pָ��ԭpolya��һ���
		rear = polya; //����β�巨����ÿ������ai*bj����ʽ��βָ��
		q = polyb->next; 
		while (q != NULL) //����polyb
		{
			s = (Polynode*)malloc(sizeof(Polynode)); //����ÿ��ai*bj��
			s->coef = temp->coef * q->coef;
			s->exp = temp->exp + q->exp;
			rear->next = s; //β�巨������������ʽpolya֮��
			rear = s;
			q = q->next;
		}
		rear->next = NULL; //��polya���һ������next��NULL
		PolyAdd(polyc, polya); //polya��polyc�ۼ�
		//PrintPolylist(polyc); //debug
	}

	polya = polyc; //��������ϵ�a*bͷ��㸳��polya
	//PrintPolylist(polya); //debug
}
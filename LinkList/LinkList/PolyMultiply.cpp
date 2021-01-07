#include <stdio.h>
#include <stdlib.h>
#include "polynomial.h"

/*算法思想：
两多项式（a1,a2,...,am），（b1,b2,...,bn）相乘，公式为
		Σ(i=1...m)Π(j=1...n)ai*bj
因此，声明两指针p,temp. temp中依次存放a1...am，p始终指向temp的下一结点.
声明指针r，用于存放Πai*bj，并按尾插法依次建立m个ΣΠai*bj多项式（头结点为polya，每个多项式均有n项）.
声明临时多项式polyc，初值为空。依次将polya与polyc相加m次，最终即得到多项式a*b.
*/


void PolyMultiply(Polylist &polya, Polylist polyb)
{
	Polylist polyc = (Polynode*)malloc(sizeof(Polynode)); //声明部分
	Polynode* p, * q, * temp;
	Polynode* s, * rear;

	p = polya->next; //初始化部分
	polyc->coef = -1; polyc->exp = -1; polyc->next = NULL;

	while (p != NULL) //遍历polya
	{
		temp = p; p = p->next; //将p所指结点赋给temp，随后p指向原polya下一结点
		rear = polya; //用于尾插法建立每个ΣΠai*bj多项式的尾指针
		q = polyb->next; 
		while (q != NULL) //遍历polyb
		{
			s = (Polynode*)malloc(sizeof(Polynode)); //计算每个ai*bj项
			s->coef = temp->coef * q->coef;
			s->exp = temp->exp + q->exp;
			rear->next = s; //尾插法将该项插入多项式polya之后
			rear = s;
			q = q->next;
		}
		rear->next = NULL; //将polya最后一个结点的next置NULL
		PolyAdd(polyc, polya); //polya与polyc累加
		//PrintPolylist(polyc); //debug
	}

	polya = polyc; //将计算完毕的a*b头结点赋给polya
	//PrintPolylist(polya); //debug
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"

/*�㷨˼�룺
����׺���ʽstrת��Ϊ��׺���ʽexp����3 + 4 * 5 �� 3 4 5 * + ����
��.	�涨��������ȼ���cmp[7][7]�������±�0-6�ֱ��ʾ+��-��*��/����������#. ֵ-1,0,1�ֱ��ʾ<��=��>.
���磬cmp[2][0]=1 ��ʾ��*�����ȼ����ڡ�+����cmp[1][3]=-1 ��ʾ��-�����ȼ�С�ڡ�/��.
�����ǽ�����#�����ȼ���ȵ������Ϊ��������.
��.	���������ջ.
��.	��������ɨ����׺���ʽstr���������´���
	����������������������������������ֱ��������ʽexp.
	�������������
	���������ջΪ��ջ��ǰ��������ȼ�С��ջ�����������ǰ�������ջ.
	������ǰ��������ȼ�����ջ�����������ջ�������������ջ��������ʽexp��ֱ��ջΪ�ջ�
	  ջ����������ȼ����ڵ�ǰ����������ǰ�������ջ.
	������ǰ��������ȼ�����ջ����������������Ϊ�������ţ��������Ų���.
	����������#����ֹͣɨ��str����ջ������ʣ��Ԫ�����γ�ջ��������ʽexp.
*/

int cmp[7][7] =  //��������ȼ���
{
	{1,1,-1,-1,-1,1,1},
	{1,1,-1,-1,-1,1,1},
	{1,1,1,1,-1,1,1},
	{1,1,1,1,-1,1,1},
	{-1,-1,-1,-1,-1,0,0},
	{1,1,1,1,0,1,1},
	{-1,-1,-1,-1,-1,0,0}
};

void Append(char* str, char ch) //�ַ������Ӻ���
{
	int i;
	for (i = 0; str[i] != '\0'; i++);
	str[i] = ch; 
	str[i + 1] = '\0';
}

int Compare(char a, char b) //���ȼ��ȽϺ���. ����-1,0,1���ֱ��ʾ<,=,>
{
	int i, j;
	i = j = 0;
	switch (a)
	{
		case '+':
			i = 0;
			break;
		case '-':
			i = 1;
			break;
		case '*':
			i = 2;
			break;
		case '/':
			i = 3;
			break;
		case '(':
			i = 4;
			break;
		case ')':
			i = 5;
			break;
		case '#':
			i = 6;
			break;
	}
	switch (b)
	{
		case '+':
			j = 0;
			break;
		case '-':
			j = 1;
			break;
		case '*':
			j = 2;
			break;
		case '/':
			j = 3;
			break;
		case '(':
			j = 4;
			break;
		case ')':
			j = 5;
			break;
		case '#':
			j = 6;
			break;
	}
	return cmp[i][j];
}

void PostfixConvert(char* str, char* exp)
{
	CharStack S; InitStack(&S); //��������
	int i, j, priority, flag; //priority��ʾ���ȼ���flagΪ��>�������ѭ��������־
	char oprt; //ջ�������

	char ch;

	for (i = 0; str[i] != '#'; i++)
	{
		if (str[i] >= '0' && str[i] <= '9') //�����������
		{
			Append(exp, str[i]);

			j = i + 1; //��λ����С�����
			while ((str[j] >= '0' && str[j] <= '9') || (str[j] == '.'))
			{
				Append(exp, str[j]); //����λ����С����ֱ������exp
				j++;
			}
			Append(exp, ' '); //��ո�
			i = j - 1; //����iֵ
		}

		else if ((str[i] == '-' && i == 0) || (str[i] == '-' && str[i - 1] == '(')) //������������ҽ�����-��Ϊstr��һ���ַ�����ǰ��Ϊ��(��
			Append(exp, str[i]); 

		else //��������
		{
			flag = 1; 
			while (flag)
			{
				if (IsEmpty(&S)) //��ջ����ǰ�����ֱ����ջ������ѭ��
				{
					Push(&S, str[i]);
					break;
				}
				else //ջ�ǿ����
				{
					GetTop(&S, &oprt); 
					priority = Compare(oprt, str[i]); //�Ƚ�ջ��������͵�ǰ����������ȼ�
					switch (priority)
					{
						case -1: //ջ��<��ǰ����ǰ�����ֱ����ջ������ѭ��
							Push(&S, str[i]); flag = 0;
							break;
						case 0: //ջ��=��ǰ���������ţ�����ջ���������������Ų���������ѭ��
							Pop(&S, &oprt); flag = 0;
							break;
						case 1: //ջ��>��ǰ������ջ�������������exp������ѭ��
							Pop(&S, &oprt); Append(exp, oprt); Append(exp, ' '); //��ո� 
							break;
					}
				}
			}
		}
	}

	if (str[i] == '#') //ɨ����������#
		while (!IsEmpty(&S)) //��ջ������Ԫ�أ������γ�ջ������exp.
		{
			Pop(&S, &oprt);
			Append(exp, oprt); Append(exp, ' ');
		}

}
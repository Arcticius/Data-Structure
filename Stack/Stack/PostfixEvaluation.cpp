#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"

/*�㷨˼�룺
�����׺���ʽexp��ֵ���� 3 4 5 * + ����ֵΪ23.
��.	���ø�����ջ.
��.	��������ɨ���׺���ʽexp���������´���
	������������������������������������ֱ����ջ.
	�����ո�������.
	���������oprt����������ջ���Σ��õ�������num1��num2,��num1��num2ִ��oprt���㣬���ý����ջ.
��.	ɨ�������ջ��Ԫ�ؼ�Ϊ����.
*/

double Execute(double a, char oprt, double b) //�������㺯��
{
	if (oprt == '+')
		return a + b;
	else if (oprt == '-')
		return a - b;
	else if (oprt == '*')
		return a * b;
	else if (oprt == '/')
		return a / b;
}

double PostfixEvaluation(char* exp)
{
	DoubleStack S; InitStack(&S); //��������
	double result, current, num1, num2, k; //kΪС��λ��������
	int i, j;
	char oprt;
	bool IsNegative, IsDecimal;
	
	for (i = 0; exp[i] != '\0'; i++) //��������ɨ���׺���ʽexp
	{
		IsNegative = false; //����ѭ����ʼʱ��Ĭ��������Ϊ����

		if (exp[i] == ' ') //�ո����
			continue;
		else if (exp[i] == '-' && exp[i + 1] != ' ') //������������ҽ�����ǰ�ַ�Ϊ��-���Һ�̲�Ϊ�ո�
		{
			IsNegative = true; //���ø�����־Ϊtrue
			i++; //ɨ�踺�ŵ���һλ�ַ���һ����������������²��������鲻����else if
		}

		if (exp[i] >= '0' && exp[i] <= '9') //���������
		{
			current = exp[i] - '0'; //���ַ�ת��Ϊ������
			IsDecimal = false; //��ʼĬ�ϸ�������Ϊ����

			j = i + 1;
			k = 0.1; //С��λ��������
			while (exp[j] != ' ') //��λ���ж���䣬����ɨ�赱ǰ�ַ��ĺ�̣�ֱ�������ո�Ϊֹ
			{
				if (exp[j] == '.') //��̳���С����
				{
					IsDecimal = true; //����С����־Ϊtrue
					j++;
				}

				if (IsDecimal) //С�������������
				{
					current = current + (exp[j] - '0') * k;
					k *= 0.1;
				}
				else //��С�������������
					current = current * 10 + (exp[j] - '0');

				j++;
			}

			if (IsNegative) //��Ϊ�����������-1
				current = current * (-1.0);

			i = j - 1; //����iֵ
			Push(&S, current); //��������ջ
		}
		else //��������
		{
			oprt = exp[i];
			Pop(&S, &num1); Pop(&S, &num2);
			Push(&S, Execute(num2, oprt, num1)); //��������ջ
		}
	}

	Pop(&S, &result); 
	return result;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"

/*算法思想：
计算后缀表达式exp的值，如 3 4 5 * + 计算值为23.
①.	设置浮点数栈.
②.	自左向右扫描后缀表达式exp，进行如下处理：
	遇到运算数（整数、浮点数、负数），则直接入栈.
	遇到空格，则跳过.
	遇到运算符oprt，则连续退栈两次，得到运算数num1、num2,对num1，num2执行oprt运算，所得结果入栈.
③.	扫描结束后，栈顶元素即为所求.
*/

double Execute(double a, char oprt, double b) //四则运算函数
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
	DoubleStack S; InitStack(&S); //声明部分
	double result, current, num1, num2, k; //k为小数位数计数器
	int i, j;
	char oprt;
	bool IsNegative, IsDecimal;
	
	for (i = 0; exp[i] != '\0'; i++) //从左至右扫描后缀表达式exp
	{
		IsNegative = false; //历次循环开始时，默认运算数为正数

		if (exp[i] == ' ') //空格情况
			continue;
		else if (exp[i] == '-' && exp[i + 1] != ' ') //负数情况，当且仅当当前字符为“-”且后继不为空格
		{
			IsNegative = true; //设置负数标志为true
			i++; //扫描负号的下一位字符，一定是运算数，因此下部条件语句块不可用else if
		}

		if (exp[i] >= '0' && exp[i] <= '9') //运算数情况
		{
			current = exp[i] - '0'; //由字符转化为浮点数
			IsDecimal = false; //初始默认该运算数为整数

			j = i + 1;
			k = 0.1; //小数位数计数器
			while (exp[j] != ' ') //多位数判定语句，依次扫描当前字符的后继，直到遇到空格为止
			{
				if (exp[j] == '.') //后继出现小数点
				{
					IsDecimal = true; //设置小数标志为true
					j++;
				}

				if (IsDecimal) //小数情况进入该语句
				{
					current = current + (exp[j] - '0') * k;
					k *= 0.1;
				}
				else //非小数情况进入该语句
					current = current * 10 + (exp[j] - '0');

				j++;
			}

			if (IsNegative) //若为负数，则乘以-1
				current = current * (-1.0);

			i = j - 1; //重置i值
			Push(&S, current); //运算数入栈
		}
		else //运算符情况
		{
			oprt = exp[i];
			Pop(&S, &num1); Pop(&S, &num2);
			Push(&S, Execute(num2, oprt, num1)); //计算结果入栈
		}
	}

	Pop(&S, &result); 
	return result;
}
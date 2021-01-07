#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"

/*算法思想：
将中缀表达式str转化为后缀表达式exp（如3 + 4 * 5 → 3 4 5 * + ），
①.	规定运算符优先级表cmp[7][7]，其中下标0-6分别表示+，-，*，/，（，），#. 值-1,0,1分别表示<，=，>.
例如，cmp[2][0]=1 表示“*”优先级高于“+”；cmp[1][3]=-1 表示“-”优先级小于“/”.
不考虑结束符#，优先级相等的情况仅为左右括号.
②.	设置运算符栈.
③.	自左向右扫描中缀表达式str，进行如下处理：
	遇到运算数（整数、浮点数、负数），直接填入结果式exp.
	遇到运算符，则：
	·若运算符栈为空栈或当前运算符优先级小于栈顶运算符，则当前运算符入栈.
	·若当前运算符优先级大于栈顶运算符，则栈顶运算符依次退栈并填入结果式exp，直到栈为空或
	  栈顶运算符优先级大于当前运算符，随后当前运算符入栈.
	·若当前运算符优先级等于栈顶运算符，则仅可能为左右括号，做脱括号操作.
	遇到结束符#，则停止扫描str，将栈内所有剩余元素依次出栈并填入结果式exp.
*/

int cmp[7][7] =  //运算符优先级表
{
	{1,1,-1,-1,-1,1,1},
	{1,1,-1,-1,-1,1,1},
	{1,1,1,1,-1,1,1},
	{1,1,1,1,-1,1,1},
	{-1,-1,-1,-1,-1,0,0},
	{1,1,1,1,0,1,1},
	{-1,-1,-1,-1,-1,0,0}
};

void Append(char* str, char ch) //字符串附加函数
{
	int i;
	for (i = 0; str[i] != '\0'; i++);
	str[i] = ch; 
	str[i + 1] = '\0';
}

int Compare(char a, char b) //优先级比较函数. 返回-1,0,1，分别表示<,=,>
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
	CharStack S; InitStack(&S); //声明部分
	int i, j, priority, flag; //priority表示优先级，flag为“>”情况中循环结束标志
	char oprt; //栈顶运算符

	char ch;

	for (i = 0; str[i] != '#'; i++)
	{
		if (str[i] >= '0' && str[i] <= '9') //正操作数情况
		{
			Append(exp, str[i]);

			j = i + 1; //多位数及小数情况
			while ((str[j] >= '0' && str[j] <= '9') || (str[j] == '.'))
			{
				Append(exp, str[j]); //将各位数及小数点直接填入exp
				j++;
			}
			Append(exp, ' '); //填空格
			i = j - 1; //重置i值
		}

		else if ((str[i] == '-' && i == 0) || (str[i] == '-' && str[i - 1] == '(')) //负数情况，当且仅当“-”为str第一个字符，或前驱为“(”
			Append(exp, str[i]); 

		else //运算符情况
		{
			flag = 1; 
			while (flag)
			{
				if (IsEmpty(&S)) //空栈，当前运算符直接入栈，结束循环
				{
					Push(&S, str[i]);
					break;
				}
				else //栈非空情况
				{
					GetTop(&S, &oprt); 
					priority = Compare(oprt, str[i]); //比较栈顶运算符和当前运算符的优先级
					switch (priority)
					{
						case -1: //栈顶<当前，当前运算符直接入栈，结束循环
							Push(&S, str[i]); flag = 0;
							break;
						case 0: //栈顶=当前，左右括号，弹出栈顶左括号做脱括号操作，结束循环
							Pop(&S, &oprt); flag = 0;
							break;
						case 1: //栈顶>当前，弹出栈顶运算符并填入exp，继续循环
							Pop(&S, &oprt); Append(exp, oprt); Append(exp, ' '); //填空格 
							break;
					}
				}
			}
		}
	}

	if (str[i] == '#') //扫描至结束符#
		while (!IsEmpty(&S)) //若栈内仍有元素，则依次出栈并填入exp.
		{
			Pop(&S, &oprt);
			Append(exp, oprt); Append(exp, ' ');
		}

}
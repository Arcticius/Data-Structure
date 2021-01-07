#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int main()
{
	char str[100], exp[100] = "";

	printf("Enter expression: ");
	gets_s(str);
	PostfixConvert(str, exp);

	printf("Converting to postfix: ");
	puts(exp);

	printf("Evaluation of this expression is: %f\n", PostfixEvaluation(exp));

	/*double num1, num2;
	DoubleStack S; InitStack(&S);
	Push(&S, -4); Push(&S, 5.2);
	Pop(&S, &num1); Pop(&S, &num2);

	printf("%f %f\n", num1,num2);

	double a = Execute(num2, '-', num1);
	printf("%f\n", a);*/
	return 0;
}
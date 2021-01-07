#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int GetTop(DoubleStack* S, double* x)
{
	if (S->top == -1)
		return FALSE;
	else
	{
		*x = S->elem[S->top];
		return TRUE;
	}
}

int GetTop(CharStack* S, char* x)
{
	if (S->top == -1)
		return FALSE;
	else
	{
		*x = S->elem[S->top];
		return TRUE;
	}
}
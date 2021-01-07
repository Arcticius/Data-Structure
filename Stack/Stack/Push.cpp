#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int Push(DoubleStack* S, double x)
{
	if (S->top == Stack_Size - 1)
		return FALSE;
	S->top++;
	S->elem[S->top] = x;
	return TRUE;
}

int Push(CharStack* S, char x)
{
	if (S->top == Stack_Size - 1)
		return FALSE;
	S->top++;
	S->elem[S->top] = x;
	return TRUE;
}
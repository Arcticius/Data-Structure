#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

bool IsEmpty(DoubleStack* S)
{
	return S->top == -1;
}

bool IsEmpty(CharStack* S)
{
	return S->top == -1;
}
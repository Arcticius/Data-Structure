#pragma once
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	char* ch;
	int len;
}HString;

int StrInsert(HString* s, int pos, HString* t);
int StrAssign(HString* s, char* tval);
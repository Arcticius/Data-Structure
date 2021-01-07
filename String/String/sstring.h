#pragma once
#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0
#define MAXLEN 40

typedef struct
{
	char ch[MAXLEN];
	int len;
}SString;

void InitString(SString* s, char* str);
int StrInsert(SString* s, int pos, SString t);
int StrDelete(SString* s, int pos, int len);
int StrCompare(SString s, SString t);
int StrIndex(SString s, int pos, SString t);



#include <stdio.h>
#include <stdlib.h>
#include "sstring.h"

void InitString(SString* s, char* str)
{
	int i, j, length;

	length = 0; s->len = 0;
	for (i = 0; str[i] != '\0'; i++)
		length++;
	
	if (length > MAXLEN)
		printf("Invalid length!");
	else
	{
		for (i = 0, j = 0; j < length; j++)
		{
			s->ch[i++] = str[j];
			s->len++;
		}
		
		for (i; i < MAXLEN; i++)
			s->ch[i] = '\0';
	}
		
}
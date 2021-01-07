#include <stdio.h>
#include <stdlib.h>
#include "sstring.h"

int StrDelete(SString* s, int pos, int len)
{
	int i;
	if (pos<0 || pos>s->len - len)
		return 0;
	
	for (i = pos + len; i < s->len; i++)
		s->ch[i - len] = s->ch[i];

	s->len = s->len - len;
	s->ch[s->len] = '\0';
	return 1;
}
#include <stdio.h>
#include <stdlib.h>
#include "sstring.h"

int StrCompare(SString s, SString t)
{
	int i;
	for (i = 0; i < s.len && i < t.len; i++)
		if (s.ch[i] != t.ch[i])
			return (s.ch[i] - t.ch[i]);
	return s.len - t.len;
}
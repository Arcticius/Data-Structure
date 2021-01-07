#include <stdio.h>
#include <stdlib.h>
#include "hstring.h"

int StrAssign(HString* s, char* tval)
{
	int len, i = 0;
	if (s->ch != NULL)
		free(s->ch);

	while (tval[i] != '\0')
		i++;
	len = i;

	if (len)
	{
		s->ch = (char*)malloc(len + 1);
		if (s->ch == NULL)
			return 0;

		for (i = 0; i < len; i++)
			s->ch[i] = tval[i];
		s->ch[len] = '\0';
	}
	else
		s->ch = NULL;
	s->len = len;
	return 1;
}

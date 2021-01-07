#include <stdio.h>
#include <stdlib.h>
#include "sstring.h"
#include "hstring.h"

int main()
{
	HString s, t; 
	s.ch = t.ch = NULL;
	char s1[20] = "hello world!";
	char s2[20] = "remote ";

	StrAssign(&s, s1); StrAssign(&t, s2);
	StrInsert(&s, 6, &t);

	if (s.ch)
		puts(s.ch);

	return 0;
}
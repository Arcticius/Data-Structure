#include <stdio.h>
#include <stdlib.h>
#include "sstring.h"
#include "hstring.h"

int StrInsert(SString* s, int pos, SString t)
{
	int i;
	if (pos<0 || pos>s->len)
		return FALSE;

	if (s->len + t.len <= MAXLEN)
	{
		for (i = s->len + t.len - 1; i >= t.len + pos; i--)
			s->ch[i] = s->ch[i - t.len];
		for (i = 0; i < t.len; i++)
			s->ch[i + pos] = t.ch[i];
		s->len = s->len + t.len;
	}

	else if (pos + t.len <= MAXLEN)
	{
		for (i = MAXLEN - 1; i >= t.len + pos; i--)
			s->ch[i] = s->ch[i - t.len];
		for (i = 0; i < t.len; i++)
			s->ch[i + pos] = t.ch[i];
		s->len = MAXLEN;
	}

	else
	{
		for (i = 0; i < MAXLEN - pos; i++)
			s->ch[i + pos] = t.ch[i];
		s->len = MAXLEN;
	}

	return TRUE;
}

int StrInsert(HString* s, int pos, HString* t)
{
	int i;
	char* temp;
	
	if (pos<0 || pos>s->len || s->len == 0)
		return 0;

	temp = (char*)malloc(s->len + t->len + 1);
	if (temp == NULL)
		return 0;

	for (i = 0; i < pos; i++)
		temp[i] = s->ch[i];
	for (i = 0; i < t->len; i++)
		temp[i + pos] = t->ch[i];
	for (i = pos; i < s->len; i++)
		temp[i + t->len] = s->ch[i];

	temp[s->len + t->len] = '\0';

	s->len += t->len;
	free(s->ch);
	s->ch = temp;

	return 1;
}
#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

bool Match(char left, char right)
{
	return (left == '(' && right == ')') || (left == '[' && right == ']') || (left == '{' && right == '}');
}

void BracketMatch(char* str)
{
	CharStack S; int i; char ch;
	InitStack(&S);

	for (i = 0; str[i] != '\0'; i++)
	{
		switch (str[i])
		{
			case '(':
			case '[':
			case '{':
				Push(&S, str[i]);
				break;
			case ')':
			case ']':
			case '}':
				if (IsEmpty(&S))
				{
					printf("Right bracket is redundant!\n");
					return;
				}
				else
				{
					GetTop(&S, &ch);
					if (Match(ch, str[i]))
						Pop(&S, &ch);
					else
					{
						printf("Current brackets are NOT machting!\n");
						return;
					}
				}
				break;
		}
	}

	if (IsEmpty(&S))
		printf("Brackets are matching!\n");
	else
		printf("Left bracket is redundant!\n");
}

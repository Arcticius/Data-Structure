#include <stdio.h>
#include <stdlib.h>
#include "linkqueue.h"
#include "seqqueue.h"

int main()
{
	int n;
	printf("Enter number of rows you want to print: ");
	scanf_s("%d", &n);

	printf("Pascal triangle: (%d rows)\n", n);
	PascalTriangle(n);

	//SeeDoctor();

	return 0;
}
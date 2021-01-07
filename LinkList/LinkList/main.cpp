#include <stdio.h>
#include <stdlib.h>
#include "linklist.h"
#include "polynomial.h"

int main()
{
	printf("Enter polynomial A: ");
	Polylist pa = PolyCreate();
	printf("Enter polynomial B: ");
	Polylist pb = PolyCreate();
	
	PolyMultiply(pa, pb);
	printf("After multiplying: ");
	PrintPolylist(pa);
	return 0;
}
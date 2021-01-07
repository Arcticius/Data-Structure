#include <stdio.h>
#define MAXSIZE 100
typedef int ElemType;
typedef struct
{
    ElemType elem[MAXSIZE];
    int last;
}SeqList;

int Locate(SeqList L, ElemType e)
{
    int i = 0;
    while ((i <= L.last) && (L.elem[i] != e))
        i++;
    if (i <= L.last)
        return i + 1;
    else
        return -1;
}

int main()
{
    SeqList L = { {1,2,3,4,5},4 };
    printf("Location of 2 in SeqList is:%d\n", Locate(L, 2));
    printf("Location of 6 in SeqList is:%d\n", Locate(L, 6));
    return 0;
}

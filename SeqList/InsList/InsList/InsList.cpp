#include <stdio.h>
#define MAXSIZE 6
#define OK 1
#define ERROR 0

typedef int ElemType;
typedef struct
{
    ElemType elem[MAXSIZE];
    int last;
}SeqList;

int InsList(SeqList* L, int i, ElemType e)
{
    int k;
    if ((i < 1) || (i > L->last + 2))
    {
        printf("Invalid position.\n");
        return ERROR;
    }
    if (L->last >= MAXSIZE - 1)
    {
        printf("Cannot insert, SeqList is FULL.\n");
        return ERROR;
    }
    for (k = L->last; k >= i - 1; k--)
        L->elem[k + 1] = L->elem[k];
    L->elem[i - 1] = e;
    L->last++;
    return OK;
}

void PrintList(SeqList L)
{
    for (int i = 0; i <= L.last; i++)
        printf("%d ", L.elem[i]);
}

int main()
{
    SeqList L = { {1,2,3,4,5},4 };

    printf("Inserting 0 before position -1\n");
    InsList(&L, -1, 0);
    printf("SeqList now is: "); PrintList(L);

    printf("\n\nInserting 0 before position 1\n");
    InsList(&L, 1, 0);
    printf("SeqList now is: "); PrintList(L);

    printf("\n\nInserting 10 before position 5\n");
    InsList(&L, 5, 10);
    printf("SeqList now is: "); PrintList(L);

    return 0;
}

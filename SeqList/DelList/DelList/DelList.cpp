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

int DelList(SeqList* L, int i, ElemType* e)
{
    int k; 
    if (L->last == -1)
    {
        printf("Failed to delete. SeqList is EMPTY\n");
        return ERROR;
    }
    if ((i < 1) || (i > L->last + 1))
    {
        printf("Invalid position.\n");
        return ERROR;
    }

    *e = L->elem[i - 1];

    for (k = i; k <= L->last; k++)
        L->elem[k - 1] = L->elem[k];
    L->last--;

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
    ElemType deleted[5];
    int e=0; int i = 0;
    
    printf("Deleting element in position 6\n");
    if (DelList(&L, 6, &e))
        deleted[i++] = e;
    printf("SeqList now is: "); PrintList(L);

    printf("\n\nDeleting element in position 1\n");
    if (DelList(&L, 1, &e))
        deleted[i++] = e;
    printf("SeqList now is: "); PrintList(L);

    printf("\n\nDeleting element in position 1\n");
    if (DelList(&L, 1, &e))
        deleted[i++] = e;
    printf("SeqList now is: "); PrintList(L);

    printf("\n\nDeleting element in position 1\n");
    if (DelList(&L, 1, &e))
        deleted[i++] = e;
    printf("SeqList now is: "); PrintList(L);

    printf("\n\nDeleting element in position 1\n");
    if (DelList(&L, 1, &e))
        deleted[i++] = e;
    printf("SeqList now is: "); PrintList(L);

    printf("\n\nDeleting element in position 1\n");
    if (DelList(&L, 1, &e))
        deleted[i++] = e;
    printf("SeqList now is: "); PrintList(L);

    printf("\n\nDeleting element in position 0\n");
    if (DelList(&L, 0, &e))
        deleted[i++] = e;
    printf("SeqList now is: "); PrintList(L);

    printf("\n\nYou have deleted: ");
    for (i = 0; i <= 4; i++)
        printf("%d ", deleted[i]);

    return 0;
}

#include <stdio.h>
#define MAXSIZE 100

typedef int ElemType;

typedef struct
{
    ElemType elem[MAXSIZE];
    int last;
}SeqList;

void MergeList(SeqList* LA, SeqList* LB, SeqList* LC)
{
    int i, j, k;
    i = 0; j = 0; k = 0;
    while (i <= LA->last && j <= LB->last)
        if (LA->elem[i] <= LB->elem[j])
            LC->elem[k++] = LA->elem[i++];
        else
            LC->elem[k++] = LB->elem[j++];

    while (i <= LA->last)
        LC->elem[k++] = LA->elem[i++];

    while (j <= LB->last)
        LC->elem[k++] = LB->elem[j++];

    LC->last = LA->last + LB->last + 1;
}

void PrintList(SeqList L)
{
    for (int i = 0; i <= L.last; i++)
        printf("%d ", L.elem[i]);
}

int main()
{
    SeqList LA, LB, LC;
    LA = { {2,2,3},2 }; LB = { {1,3,3,4},3 }; LC = { {},-1 };

    printf("LA: "); PrintList(LA);
    printf("\nLB: "); PrintList(LB);

    MergeList(&LA, &LB, &LC);
    printf("\nAfter merging, LC: "); PrintList(LC);

    return 0;
}

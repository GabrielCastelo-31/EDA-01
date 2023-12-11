#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int item;
const int MAX = 5123;
#define key(A) (A)
#define less(A, B) (key(A) < key(B))
#define lessEq(A, B) (key(A) <= key(B))
#define exch(A, B)  \
    {               \
        item t = A; \
        A = B;      \
        B = t;      \
    }
#define cmpexch(A, B) \
    if (less(A, B))   \
    exch(A, B)

void merge(item *v, int l, int r1, int r2)
{
    item *v2 = malloc(sizeof(item) * (r2 - l + 1));
    int k = 0;      // indice do vetor v2
    int i = l;      // indice da primeira metade do vetor v
    int j = r1 + 1; // indice da segunda metade do vetor v

    while (i <= r1 && j <= r2)
    {
        if (lessEq(v[i], v[j]))
        {
            v2[k++] = v[i++];
        }
        else
            v2[k++] = v[j++];
    }
    while (i <= r1)
        v2[k++] = v[i++];
    while (j <= r2)
        v2[k++] = v[j++];
    k = 0;
    for (i = l; i <= r2; i++)
    {
        v[i] = v2[k++];

    }
    free(v2);
}
void mergeSort(item *v, item l, item r)

{
    if (l >= r)
        return;
    int meio = (l + r) / 2;
    mergeSort(v, l, meio);
    mergeSort(v, meio + 1, r);
    merge(v, l, meio, r);
}

int main()
{
    // int i = 0;
    int num = 0;
    scanf("%d", &num);
    item *vetor = malloc(num * sizeof(int));

    for (int j = 0; j < num; j++)
    {
        scanf("%d", &vetor[j]);
    }

    mergeSort(vetor, 0, num - 1);
    for (int j = 0; j < num - 1; j++)
    {
        printf("%d ", vetor[j]);
    }
    printf("%d\n", vetor[num - 1]);
}

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef long item;

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

void insertionSort(item *vetor, item l, item r)
{
    for (int i = r; i > l; i--)
    {
        cmpexch(vetor[i], vetor[i - 1]);
    }
    for (int i = l + 2; i <= r; i++)
    {
        int j = i;
        item tmp = vetor[i];
        while (less(tmp, vetor[j - 1]))
        {
            vetor[j] = vetor[j - 1];
            j--;
        }
        vetor[j] = tmp;
    }
}

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
    if (r - l <= 15)
    {
        insertionSort(v, l, r);
        return;
    }
    int meio = (l + r) / 2;
    mergeSort(v, l, meio);
    mergeSort(v, meio + 1, r);
    merge(v, l, meio, r);
}
bool buscaBinaria(item *v1, int r, int x)
{
    int l = 0;
    while (l <= r)
    {
        int meio = l + (r - l) / 2;
        if (x == v1[meio])
            return true;
        else if (v1[meio] < x)
            l = meio + 1;
        else
            r = meio - 1;
    }
    return false;
}

int main()
{
    int num;
    int len = 0;
    scanf(" %d", &len);
    item vetor[len];
    for (int i = 0; i < len; i++)
    {
        scanf("%ld", &vetor[i]);
    }
    mergeSort(vetor, 0, len - 1);
    /*  for (int i = 0; i < len; i++)
     {
         printf("%ld ", vetor[i]);
     } */
    while (scanf("%d", &num) != EOF)
    {
        if (buscaBinaria(vetor, len, num))
            printf("sim\n");
        else
            printf("nao\n");
    }
    return 0;
}

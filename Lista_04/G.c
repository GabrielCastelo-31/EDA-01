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

void insertionSort(item *vetor, item l, item r)
{
    for (int i = r; i > l; i--)
    {
        cmpexch(vetor[i], vetor[i - 1]);
    }
    for (int i = l + 2; i <= r; i++)
    {
        int j = i;
        int tmp = vetor[i];
        while (less(tmp, vetor[j - 1]))
        {
            vetor[j] = vetor[j - 1];
            j--;
        }
        vetor[j] = tmp;
    }
}
int partition(item *v, int l, int r)
{
    item pivot = v[r];
    int j = l; // indice dos elementos menores que o pivot, ficam a esquerda
    for (int k = l; k < r; k++)
    {
        if (lessEq(v[k], pivot))
        {
            exch(v[k], v[j]);
            j++;
        }
    }
    exch(v[j], v[r]);
    return j;
}
void quickSort(item *v, item l, item r)

{
    if (r <= l)
        return;
    if (r - l <= 15)
    {
        insertionSort(v, l, r);
        return;
    }
    cmpexch(v[r], v[(l + r) / 2]);
    cmpexch(v[(l + r) / 2], v[l]);
    cmpexch(v[(l + r) / 2], v[r]);
    int j = partition(v, l, r);
    quickSort(v, l, j - 1);
    quickSort(v, j + 1, r);
}

int main()
{
    int num;
    scanf("%d", &num);
    item *vetor = malloc(num * sizeof(int));

    for (int j = num - 1; j >= 0; j--)
    {
        scanf("%d", &vetor[j]);
        // vetor[j] = j;
        //  printf("%d ", vetor[j]);
    }
    // printf("\n");
    /* for (int j = 0; j < 5; j++)
    {
        vetor[j] = rand() % 40;
        i++;
        printf("%d ", vetor[j]);
    }
    printf("\n"); */

    quickSort(vetor, 0, num - 1);
    for (int j = 0; j < num - 1; j++)
    {
        printf("%d ", vetor[j]);
    }
    printf("%d\n", vetor[num - 1]);
}

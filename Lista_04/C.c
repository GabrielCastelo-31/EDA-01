#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int item;
const int MAX = 90123;
#define key(A) (A)
#define less(A, B) key(A) < key(B)
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

int main()
{
    item *vetor = malloc(MAX * sizeof(int));
    int i = 0;
    while (scanf("%d", &vetor[i]) != EOF)
    {
        i++;
    }
    /*    for (int j = 0; j < MAX; j++)
       {
           vetor[j] = rand() % 900;
           i++;
       } */

    insertionSort(vetor, 0, i - 1);
    for (int j = 0; j < i - 1; j++)
    {
        printf("%d ", vetor[j]);
    }
    printf("%d\n", vetor[i - 1]);
}

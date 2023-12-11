#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int item;
const int MAX = 1001;
/* #define key(A) (A);
#define less(A,B) ((key(A)) < (key(B)));
#define exch(A,B) (item t = A; A = B; B=t); */

void insertionSort(item *vetor, item l, item r)
{
    for (int i = l; i < r; i++)
    {
        for (int j = l; j < r; j++)
        {
            if (vetor[j + 1] < vetor[j])
            {
                int temp = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = temp;
            }
        }
    }
}

int main()
{
    int *vetor = malloc(MAX * sizeof(int));
    int i = 0;
    while (scanf("%d", &vetor[i]) != EOF)
    {
        i++;
    }
    insertionSort(vetor, 0, i - 1);
    for (int j = 0; j < i - 1; j++)
    {
        printf("%d ", vetor[j]);
    }
    printf("%d\n", vetor[i - 1]);

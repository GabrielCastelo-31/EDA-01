#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int item;
const int MAX = 1001;
/* #define key(A) (A);
#define less(A,B) ((key(A)) < (key(B)));
#define exch(A,B) (item t = A; A = B; B=t); */

void selectionSort(item *vetor, item l, item r)
{
    int min;
    for (int i = l; i < r; i++)
    {
        min = i;
        for (int j = i + 1; j <= r; j++)
        {
            if (vetor[j] < vetor[i])
            {
                min = j;
                int temp = vetor[i];
                vetor[i] = vetor[min];
                vetor[min] = temp;
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
    selectionSort(vetor, 0, i - 1);
    for (int j = 0; j < i; j++)
    {
        printf("%d ", vetor[j]);
    }
    printf("\n");
}

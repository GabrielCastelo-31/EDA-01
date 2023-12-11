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

typedef struct
{
    int chave;
    int valor;
} key;
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

int buscaBinaria(item *v1, int r, int x)
{
    int l = 0;
    while (l <= r)
    {
        int meio = l + (r - l) / 2;
        if (x == v1[meio])
            return meio;
        else if (v1[meio] < x)
            l = meio + 1;
        else
            r = meio - 1;
    }
    return -1;
}

int main()
{
    int n;
    int num1, num2;
    scanf("%d %d", &num1, &num2);
    item *v2 = malloc(num2 * sizeof(int));
    key *indice = malloc(num1 * sizeof(key));
    for (int i = 0; i < num1; i++)
    {
        scanf("%d", &indice[i].chave);
        indice[i].valor = i;
    }

    mergeSort(v1, 0, num1 - 1);
    /*  printf("Vetor ordenado:\n");
     for (int i = 0; i < num1; i++)
     {
         printf("%d ", v1[i]);
     } */
    /*  printf("\n\n");
     printf("Termos a serem buscados:\n"); */
    for (int i = 0; i < num2; i++)
    {
        scanf("%d", &n);
        int ans = buscaBinaria(v1, num1 - 1, n);
        if (ans != -1)
        {
            v2[i] = indice[ans].valor;
        }
        else
        {
            v2[i] = -1;
        }
    }
    /* printf("\n");
    printf("Saída:\n"); */
    for (int i = 0; i < num2; i++)
    {
        printf("%d\n", v2[i]);
    }
    return 0;
}

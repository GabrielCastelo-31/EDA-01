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

int buscaBinaria(item *v1, int r, int v)
{
    int meio;
    int l = 0;
    while (l < r)
    {
        meio = l + (r - l) / 2;
        /* printf("l: %d\n", l);
        printf("r: %d\n", r);
        printf("meio: %d\n", meio); */
        if (v <= v1[meio])
            r = meio;
        else
            l = meio + 1;
    }
    /*    printf("l para retorno: %d\n", l); */
    return l;
}

int main()
{
    int n;
    int num1, num2;
    scanf("%d %d", &num1, &num2);
    item *v1 = malloc(num1 * sizeof(int));
    item *v2 = malloc(num2 * sizeof(int));
    for (int i = 0; i < num1; i++)
    {
        scanf("%d", &v1[i]);
    }
    for (int i = 0; i < num2; i++)
    {
        scanf("%d", &n);
        v2[i] = buscaBinaria(v1, num1, n);
    }
    for (int i = 0; i < num2; i++)
    {

        printf("%d\n", v2[i]);
    }
}
